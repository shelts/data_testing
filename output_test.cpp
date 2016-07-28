#include <iostream>
#include <fstream>
#include <cmath>
#include <tgmath.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <string>
#include <ctime>
#include "pots_dens.h"
#include "structs.h"
using namespace std;

#define inv(x)  ((double) 1.0 / (x))
#define seventh(x) ((x) * (x) * (x) * (x) * (x) * (x) * (x))
#define sixth(x) ((x) * (x) * (x) * (x) * (x) * (x))
#define fourth(x) ((x) * (x) * (x) * (x))
#define fifth(x) ((x) * (x) * (x) * (x) * (x))
#define cube(x) ((x) * (x) * (x))
#define sqr(x)  ((x) * (x))
#define sqrdif(x, y) (sqr( (x) - (y) ))

#define seventhhalfs(x) ( sqrt(seventh(x) ) )
#define fivehalves(x)   ( sqrt(fifth(x) ) )
#define threehalves(x)  ( sqrt(cube(x)  ) )


#define minusfivehalves(x) (inv(fivehalves(x)))
#define minusthreehalves(x) (inv(threehalves(x)) )
#define minushalf(x) ( inv(sqrt(x)) )
#define minusquarter(x) (inv( sqrt(sqrt(x))) )
#define in_quad(x,y,z) (sqrt( x * x + y * y + z * z))

//   struct bodies
//   {
//     double x;
//     double y;
//     double z;
//     double r;
//     double l, b, r;
//     double vx, vy, vz, v;
//     double mass;
//     int type;
//   };
// 
// struct dwarf_component
// {
//     int type;
//     double mass;
//     double rscale;
// };

double randDouble(double low, double high)
{
    double temp;
/* calculate the random number & return it */
    temp = ((double) rand() / (static_cast<double>(RAND_MAX) + 1.0))* (high - low) + low;
    return temp;
}


/*This gets the number of positional data from the raw data files*/
int get_size(int type, string extension)
{
    string s;
    if(type == 0){s = string("./raw_data/light_matter_"+extension+".dat");}
    else {s = string("./raw_data/dark_matter_"+extension+".dat");}
    
    int N = 0;
    double datax;
    /*getting the length of the data set*/
    ifstream length;
    length.open (s);
    
    while(length>>datax>>datax>>datax>>datax>>datax>>datax>>datax>>datax>>datax>>datax)
    {
    //       cout<<datax<<endl;
        N++;
    }
    length.close();

    return N;
}

void get_data(int Nd, int Nl, struct bodies * b, string extension)
{
  
    string s;
    double datax,datay,dataz;
    double datal, datab, datar;
    double datavx,datavy,datavz, datam;
    int i = 0;
    int N = Nd + Nl;
    s = string("raw_data/light_matter_" + extension + ".dat");
    ifstream data;
    data.open(s);
    int type_dark = 1;
    int type_light = 0;
    
    while(data>>datax>>datay>>dataz>>datal>>datab>>datar>>datavx>>datavy>>datavz>>datam)
    {
        b[i].x    = datax;
        b[i].y    = datay;
        b[i].z    = dataz;
        b[i].r    = in_quad(datax, datay, datay);
        b[i].vx   = datavx;
        b[i].vy   = datavy;
        b[i].vz   = datavz;
        b[i].v    = in_quad(datavx, datavy, datavy);
        b[i].mass = datam;
        b[i].type = type_dark;
        i++;
    }
    data.close();

    s = string("raw_data/dark_matter_" + extension + ".dat");
    data.open(s);
    while(data>>datax>>datay>>dataz>>datal>>datab>>datar>>datavx>>datavy>>datavz>>datam)
    {
        b[i].x    = datax;
        b[i].y    = datay;
        b[i].z    = dataz;
        b[i].r    = in_quad(datax, datay, datay);
        b[i].vx   = datavx;
        b[i].vy   = datavy;
        b[i].vz   = datavz;
        b[i].v    = in_quad(datavx, datavy, datavy);
        b[i].mass = datam;
        b[i].type = type_light;
        i++;
    }
    data.close();
  
}


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// theory functions

double density(double r, struct dwarf_component  light, struct dwarf_component  dark)
{
    double light_comp = get_density(r, light);
    double dark_comp  = get_density(r, dark);
    return (light_comp + dark_comp);
}


double potential(double r, struct dwarf_component  light, struct dwarf_component  dark)
{
    double light_comp = get_potential(r, light);
    double dark_comp  = get_potential(r, dark);
    return (light_comp + dark_comp);
}


double distribution(double mass, double r_scale, double v, double r, struct dwarf_component * light, struct dwarf_component * dark)
{
    
    double pi  = 4.0 * atan(1.0);
    double coeff = 24.0 * sqrt(2.0) * inv( 7.0 * cube(pi) );
    double energy = -potential(r, light, dark) - 0.5 * sqr(v) ;
    
    double f = v * v * coeff * inv( fourth(mass) ) * sqr(r_scale) * seventhhalfs(fabs(energy));
    
    return f;
    
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// service functions

double esc_vel(double r, struct dwarf_component * light, struct dwarf_component * dark)
{
    double escv = sqrt( fabs(2.0 * potential( r, light, dark) ) );
    return escv;
}


void com(double * cm, double * cmv, struct bodies * b,  int N, double mass)
{
    double cm_x = 0.0;
    double cm_y = 0.0;
    double cm_z = 0.0;
    double cmv_x = 0.0;
    double cmv_y = 0.0;
    double cmv_z = 0.0;

    for(int i = 0; i < N; i++)
    {
        cm_x += b[i].mass * b[i].x;
        cm_y += b[i].mass * b[i].y;
        cm_z += b[i].mass * b[i].z;
        
        cmv_x += b[i].mass * b[i].vx;
        cmv_y += b[i].mass * b[i].vy;
        cmv_z += b[i].mass * b[i].vz;
    }
    
    
    cm[0] = cm_x * inv(mass);
    cm[1] = cm_y * inv(mass);
    cm[2] = cm_z * inv(mass);
    
    cmv[0] = cmv_x * inv(mass);
    cmv[1] = cmv_y * inv(mass);
    cmv[2] = cmv_z * inv(mass);
//     printf("%f\t%f\t%f\t%f\t%f\t%f\n", cm[0], cm[1], cm[2], cmv[0], cmv[1], cmv[2]);
}

void com_correction(double * cm, double * cmv, struct bodies * b, int N)
{
    double r_corrected, v_corrected;
    for(int i = 0; i < N; i++)
    {
        r_corrected = sqrt( sqrdif(cm[0], b[i].x)  + sqrdif(cm[1], b[i].y)  + sqrdif(cm[2], b[i].z) );
        v_corrected = sqrt( sqrdif(cm[0], b[i].vx) + sqrdif(cm[1], b[i].vy) + sqrdif(cm[2], b[i].vz) );
//         printf("%f\t%f\t%f\t%f\t%f\t%f\n", b[i].x, b[i].y, b[i].z, b[i].vx, b[i].vy, b[i].vz);
        b[i].x -= cm[0];
        b[i].y -= cm[1];
        b[i].z -= cm[2];
        
        b[i].vx -= cmv[0];
        b[i].vy -= cmv[1];
        b[i].vz -= cmv[2];
        
        b[i].r = r_corrected;
        b[i].v = v_corrected;
//         printf("%f\t%f\t%f\t%f\t%f\t%f\n", b[i].x, b[i].y, b[i].z, b[i].vx, b[i].vy, b[i].vz);
    }
    
}

/*this is a binning routine, makes a histogram*/
void binner(int binN, double binwidth, double * x, int N, string s, string extension, int type)
{
    // binN=number of bins
    //binwidthsize of bins
    double bins[binN];
    double range = 0;
    double upper = binN * binwidth;
    
    /*binning*/

    /*initializing bins*/
    for(int i = 0; i != binN; i++)
    {bins[i] = 0;}
    ofstream bin;
    bin.open (s);
    
    for(int j = 0; j < N; j++)/*tests one of the numbers at a time*/
    {
        
        range = 0;/*resets the range so that the bins can be tested again against the number*/
        if(type == 1)
        {
            range = -4.0;
            upper = 4.0;
        }
        if(type == 2 )
        {
            range = -15.0;
            upper = 0.0;
        }
        
        for(int i = 0; i < binN; i++)/*for each bin, the number is tested*/
        {
            if( ( range + binwidth ) < upper)
            {
                
                /*this if statement tests to see if the random number is in that
                bin range.*/
                if ( x[j] >= range && x[j] < ( range + binwidth ) )
                {
                    bins[i] = bins[i] + 1;
                    break;
                }
                range = range + binwidth;/*this statement changes the range of testing
                so that a new new bin can be checked against the number*/
            }
            else if( (range + binwidth) == upper)/*includes the upper interval*/
            {
                if(x[j] >= range && x[j] <= (range + binwidth))
                {
                    bins[i] = bins[i] + 1;
                    break;
                }
                range = range + binwidth;
            }

        }
    }


    double total = 0;
    double binrange = 0;
    
    if(type == 1)
    {
        binrange = -4.0;
    }
    
    if(type == 2 )
    {
        binrange = -15.0;
    }
    
    for(int i = 0; i != binN; i++)
    {
        binrange = binrange + binwidth;
        bin<<bins[i]<<"\t"<<binrange<<endl;
    }
    bin.close();
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// theory checking functions
void single_density_theory(double bin_width, struct dwarf_component * light, struct dwarf_component * dark, double masspl, double masspd)
{
    double w = 0.0;
    double pi = 4.0 * atan(1.0);
    
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
    
    double pi = 4.0 * atan(1.0);
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

void vel_distribution_theory(double bin_width, int number_of_bins, string extension, struct bodies * b,  int Nl, int Nd, struct dwarf_component * light, struct dwarf_component * dark)
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
    double mass = light.mass + dark.mass;
    double rscale = light.rscale; //it doesn't matter which since they should be the  same
    
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
        fmax = distribution(mass, rscale, v_mx, r, light, dark);
        
        while(1)
        {
            v = randDouble(0.0, v_esc);
            u = randDouble(0.0, 1.0);
            f = distribution(mass, rscale, v, r, light, dark);
            
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
    double model1                      = atof(argv[6]);
    double model2                      = atof(argv[7]);
    
    
    dwarf_component light;
    dwarf_component dark;
    
    light.type = model1;
    light.rscale = rscale_l;
    light.mass = mass_l;
    
    dark.type = model2;
    dark.rscale = rscale_d;
    dark.mass = mass_d;
    
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
    double mass = light.mass + dark.mass;
    com(cm, cmv, b, N, mass);
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
    FILE * data;
    data = fopen("2.out", "w");
    double pot, den;
    double v_mx1, v_mx2, v_esc;
    double rtmp = 0.1;
    while(1)
    {
        v_esc = esc_vel(rtmp, light, dark);
        pot = density(rtmp, light, dark);
        den = potential(rtmp, light, dark);
        v_mx1 = (2.0 / 3.0) * sqrt( fabs( potential(rtmp, light, dark) ));
        v_mx2 = (sqrt(2.0) / 3.0) * v_esc;
        fprintf(data, "%0.15f\t%0.15f\t%0.15f\t%0.15f\t%0.15f\n", pot, den, rtmp, v_mx1, v_mx2);
        rtmp += .1;
        if(rtmp > 10){break;}
        
    }
    fclose(data);
    printf("done.\n");
}
