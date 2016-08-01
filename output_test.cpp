#include "pots_dens.h"
#include "structs.h"
#include "utility_functions.h"
#include "dist_funcs.h"

// theory functions

double density(double r, struct component & light, struct component & dark)
{
    double light_comp = get_density(r, light);
    double dark_comp  = get_density(r, dark);
    return (light_comp + dark_comp);
}


double potential(double r, struct component & light, struct component & dark)
{
    double light_comp = get_potential(r, light);
    double dark_comp  = get_potential(r, dark);
    return (light_comp + dark_comp);
}


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// theory checking functions
void single_density_theory(double bin_width, struct component & light, struct component & dark, double masspl, double masspd)
{
    double w = 0.0;
//     double pi = 4.0 * atan(1.0);
    
    double de, de2, de3;
    FILE * rho;
    rho = fopen("./theory/theory_den.dat", "w");
    while(1)
    {
        de2 = 4.0 * pi * w * w * get_density(w, light) * bin_width / masspl;
        de3 = 4.0 * pi * w * w * get_density(w, dark)  * bin_width / masspd;
        de = de2 + de3;
        w += 0.001;
        fprintf(rho, "%f \t %f \t %f\t%f\n", w, de, de2, de3);
            
        if( w > 5 * (light.rscale + dark.rscale)){break;}
    }
    fclose(rho);
}

void angle_theory( double bin_width, double * args)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double masspl   = args[4]; 
    double masspd   = args[5];
    
//     double pi = 4.0 * atan(1.0);
    double theta_l, theta_d, theta;
    double phi_l, phi_d, phi;
    FILE * th;
    double w = 0.0;
    th= fopen("./theory/theory_theta.dat", "w");
    while(1)
    {
        theta_l = 2.0 * pi * mass_l * sin(w) * bin_width / (masspl * 4 * pi);
        theta_d = 2.0 * pi * mass_d * sin(w) * bin_width / (masspd * 4 * pi);
        theta = theta_l + theta_d;
        w += 0.01;
        fprintf(th, "%f \t %f \t %f\t%f\n", w, theta, theta_l, theta_d);
            
        if(w > (5.0)){break;}
    }
    
    FILE * ph;
    w = -5.0;
    ph= fopen("./theory/theory_phi.dat", "w");
    while(1)
    {
        phi_l = 2 * mass_l * bin_width /  (masspl * 4 * pi);
        phi_d = 2 * mass_d * bin_width /  (masspd * 4 * pi);
        phi = phi_l + phi_d;
        w += 0.01;
        fprintf(ph, "%f \t %f \t %f\t%f\n", w, phi, phi_l, phi_d);
            
        if(w>(5.0)){break;}
    }
    fclose(th);
    fclose(ph);
}

void vel_distribution_theory(double bin_width, int number_of_bins, string extension, struct bodies * b,  int Nl, int Nd, struct component & light, struct component & dark)
{
    //this function only works if both components of the model are the same. 
    //I.E. the two component model is essentially a one component model.
    //this will return a vel distrib for a one comp model with the same mass and rscale
    //I split the distrib in 2 so when we split up each component of the two comp model
    //the counts match up when binned.
    int light_particle = 0;
    int N = Nl + Nd;
    int countl = 0;
    int countd = 0;
    
    double v_l[Nl];
    double v_d[Nd];
    double v_t[N];
    double v, u, f, r;
    double v_esc, v_mx;
    double fmax;
    
    for(int i = 0; i < N; i++)
    {
        r = b[i].r;
        v_esc = esc_vel(r, light, dark);
//         v_mx = (2.0 / 3.0) * sqrt( fabs( potential(r, args, comp1, comp2) ));
        v_mx = (sqrt(2.0) / 3.0) * v_esc;
        fmax = dist_func(v_mx, r, light, dark);
        
        while(1)
        {
            v = randDouble(0.0, v_esc);
            u = randDouble(0.0, 1.0);
            f = dist_func(v, r, light, dark);
            
//             printf("f = %f fmax = %f  f/fmax = %f\n", f, fmax, f/fmax);
            if(fabs(f / fmax) > u)
            {
                //These are split in two so when we compare each component, the counts match up
                v *= 0.977813107;
                if(b[i].type == light_particle)
                {
                    v_l[countl] = v;
                    countl++;
                }
                else
                {
                    v_d[countd] = v;
                    countd++;
                }
                v_t[N] = v;
                break;
            }
        }
    }
    
    
    
    
    string s;
    int type = 0;
    s = string("binned_data/dark_matter_theory_vel_bins.dat");
    binner(number_of_bins, bin_width, v_d, Nd, s, extension, type);
    s = string("binned_data/light_matter_theory_vel_bins.dat");
    binner(number_of_bins, bin_width, v_l, Nl, s, extension, type);
    s = string("binned_data/both_matter_theory_vel_bins.dat");
    binner(number_of_bins, bin_width, v_t, N, s, extension, type);
    
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// actual data checking function

void rad_vel_distribution(string extension, int Nd, int Nl, struct bodies * b, int number_of_bins, double bin_width)
{
    int type = 0;
    string s, s1, s2;
    s1 = string("actual/light_matter_velocity_dist_" + extension + ".dat");
    s2 = string("actual/dark_matter_velocity_dist_" + extension + ".dat");
    ofstream vel_l, vel_d;
    vel_l.open(s1);
    vel_d.open(s2);
    int light = 0;
    int dark = 1;
    int N = Nd + Nl;
    double r[N], v[N];
    double rd[Nd], rl[Nl];
    double vd[Nd], vl[Nl];
    int countl = 0;
    int countd = 0;
    
    for(int i = 0; i < N; i++)
    {
        r[i] = b[i].r; 
        v[i] = b[i].v;
        if(b[i].type == light)
        {
            vel_l << b[i].r << "\t" << b[i].v << endl;
            rl[countl] = b[i].r;
            vl[countl] = b[i].v;
            countl++;
        }
        else
        {
            vel_d << b[i].r << "\t" << b[i].v << endl;
            rd[countd] = b[i].r;
            vd[countd] = b[i].v;
            countd++;
        }
        
    }
    vel_l.close();
    vel_d.close();
    
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    //radial distribution                                                                  //
    s = string("binned_data/both_matter_bins_" + extension + ".dat");                      //
    binner(number_of_bins, bin_width, r, Nd + Nl, s, extension, type);                     //
                                                                                           //
    s = string("binned_data/dark_matter_bins_" + extension + ".dat");                      //
    binner(number_of_bins, bin_width, rd, Nd, s, extension, type);                         //
                                                                                           //
    s = string("binned_data/light_matter_bins_" + extension + ".dat");                     //
    binner(number_of_bins, bin_width, rl, Nl, s, extension, type);                         //
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    //velopcity distribution                                                               //
    s = string("binned_data/dark_matter_vel_bins_" + extension + ".dat");                  //
    binner(number_of_bins, bin_width, vd, Nd, s, extension, type);                         //
                                                                                           //
    s = string("binned_data/light_matter_vel_bins_" + extension + ".dat");                 //
    binner(number_of_bins, bin_width, vl, Nl, s, extension, type);                         //
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
}

void angles(string extension, int Nl, int Nd, struct bodies * b, int number_of_bins, double bin_width)
{
    int N = Nl + Nd;
    double theta_l[Nl], thetav_l[Nl];
    double theta_d[Nd], thetav_d[Nd];
    double theta[N]   , thetav[N];
  
    double phi[N]     , phiv[N];
    double phi_l[Nl]  , phiv_l[Nl];
    double phi_d[Nd]  , phiv_d[Nd];
    string s;
    
    int light = 1;
    int dark = 0;
    int countl = 0;
    int countd = 0;

    for(int i = 0; i < N; i++)
    {
        if(b[i].type == light)
        {
            theta_l[countl] = acos( b[i].z / b[i].r );
            phi_l[countl] = atan2(  b[i].y , b[i].x );
            
            thetav_l[countl] = acos( b[i].vz / b[i].v );
            phiv_l[countl] = atan2(  b[i].vy , b[i].vx );
            
            theta[i] = theta_l[countl];
            phi[i] = phi_l[countl];
            
            thetav[i] = thetav_l[countl];
            phiv[i] = phiv_l[countl];
            countl++;
        }
        else
        {
            theta_d[countd] = acos( b[i].z / b[i].r );
            phi_d[countd] = atan2(  b[i].y , b[i].x );
            
            thetav_d[countd] = acos( b[i].vz / b[i].v );
            phiv_d[countd] = atan2(  b[i].vy , b[i].vx );
            
            theta[i] = theta_d[countd];
            phi[i] = phi_d[countd];
            
            thetav[i] = thetav_d[countd];
            phiv[i] = phiv_d[countd];
            
            countd++;
        }
        
    }
    
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    //radial theta                                                                         //
    int type = 0;                                                                          //
    s = string("binned_data/theta_light_" + extension + ".dat");                           //
    binner(number_of_bins, bin_width, theta_l, Nl, s, extension, type);                    //
                                                                                           //
    s = string("binned_data/theta_dark_" + extension + ".dat");                            //
    binner(number_of_bins, bin_width, theta_d, Nd, s, extension, type);                    //
                                                                                           //
    s = string("binned_data/theta_both_" + extension + ".dat");                            //
    binner(number_of_bins, bin_width, theta, N, s, extension, type);                       //
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    //velocity theta                                                                       //
    s = string("binned_data/theta_vel_light_" + extension +".dat");                        //
    binner(number_of_bins, bin_width, thetav_l, Nl, s, extension, type);                   //
                                                                                           //
    s = string("binned_data/theta_vel_dark_" + extension +".dat");                         //
    binner(number_of_bins, bin_width, thetav_d, Nd, s, extension, type);                   //
                                                                                           //
    s = string("binned_data/theta_vel_both_" + extension + ".dat");                        //
    binner(number_of_bins, bin_width, thetav, N, s, extension, type);                      //
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    //radia phi                                                                            //
    type = 1;                                                                              //
    s = string("binned_data/phi_light_" + extension + ".dat");                             //
    binner(number_of_bins, bin_width, phi_l, Nl, s, extension, type);                      //
                                                                                           //
    s = string("binned_data/phi_dark_" + extension + ".dat");                              //
    binner(number_of_bins, bin_width, phi_d, Nd, s, extension, type);                      //
                                                                                           //
    s = string("binned_data/phi_both_" + extension + ".dat");                              //
    binner(number_of_bins, bin_width, phi, N, s, extension, type);                         //
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    //velocity phi                                                                         //
    s = string("binned_data/phi_vel_light_"+extension+".dat");                             //
    binner(number_of_bins, bin_width, phiv_l, Nl, s, extension, type);                     //
                                                                                           //
    s = string("binned_data/phi_vel_dark_"+extension+".dat");                              //
    binner(number_of_bins, bin_width, phiv_d, Nd, s, extension, type);                     //
                                                                                           //
    s = string("binned_data/phi_vel_both_"+extension+".dat");                              //
    binner(number_of_bins, bin_width, phiv, N, s, extension, type);                        // 
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
}


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// main function calls
int main (int argc, char * const argv[])
{
    srand(time(NULL));
    string simtime                 = argv[1];
    double rscale_l                    = atof(argv[2]);
    double rscale_d                    = atof(argv[3]);
    double mass_l                      = atof(argv[4]);
    double mass_d                      = atof(argv[5]);
    int model1                         = atof(argv[6]);
    int model2                         = atof(argv[7]);
    
    
    component light;
    component dark;
    init_comps(light, dark, rscale_l, rscale_d, mass_l, mass_d, model1, model2);

    
    string extension = simtime + "gy";
    
    /*these are markers for the type of data being sent into functions*/
    int d = 1;//dark matter     
    int l = 0;//light matter


    /*paramters for binning routine*/
    int number_of_bins = 1000;
    double bin_width = .10;

    
    int Nd = get_size(d, extension);//getting the size of the dark matter data
    int Nl = get_size(l, extension);//getting the size of the light matter data
    printf("light: %i dark: %i\n", Nl, Nd);

    int N = Nd + Nl;
    bodies b[N];
    
    double cm[3]  = {0.0, 0.0, 0.0};
    double cmv[3] = {0.0, 0.0, 0.0};
    
    printf("running tests");
    
    /*getting the positional and velocity data*/
    get_data(Nd, Nl, b, extension);
    
    /*get center of mass*/
    double mass = mass_l + mass_d;
    com(b, N, cm, cmv, mass);
    com_correction(cm, cmv, b, N);
    
    printf(".");//actual 
    rad_vel_distribution(extension, Nd, Nl, b, number_of_bins, bin_width);
    
    printf(".");//actual 
    angles(extension, Nl, Nd, b, number_of_bins, bin_width);
    
    printf(".");//theory
    
    double masspd = 0.0;
    double masspl = 0.0;
    for(int i = 0; i < N; i++)
    {
        if(b[i].type == l)
        {
            masspl = b[i].mass;
        }
        else
        { 
            masspd = b[i].mass;
        }
        
        if(masspd != 0.0 && masspl != 0.0){break;}
    }
    
    
    double args[6]  = {light.rscale, dark.rscale, light.mass, dark.mass, masspl, masspd};
    single_density_theory(bin_width, light, dark, masspl, masspd);

    printf(".");//theory -- from distribution func
    vel_distribution_theory(bin_width, number_of_bins, extension, b, Nl, Nd, light, dark);

    printf(".");//theory
    angle_theory(bin_width, args);
    
    
//     double args[4]  = {rscale_l, rscale_d, mass_l, mass_d};
    printf("done.\n");
}
