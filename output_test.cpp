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

  struct bodies
  {
    double x;
    double y;
    double z;
    double r;
    double vx, vy, vz, v;
    double mass;
    int type;
  };



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
    s = string("raw_data/dark_matter_" + extension + ".dat");
    ifstream data;
    data.open (s);
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

    s = string("raw_data/light_matter_" + extension + ".dat");
    ifstream data2;
    data2.open (s);
    while(data2>>datax>>datay>>dataz>>datal>>datab>>datar>>datavx>>datavy>>datavz>>datam)
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
    data2.close();
  
}


/*this actually gets the data and stores it*/
// void get_data(int N, double * x,double * y, double * z, double * vx,double * vy, double * vz, int type, string extension)
// {
//     string s;
//     if(type == 0){s = string("raw_data/light_matter_"+extension+".dat");}
//     else if(type == 1){s = string("raw_data/dark_matter_"+extension+".dat");}
//     double datax,datay,dataz;
//     double datal, datab, datar;
//     double datavx,datavy,datavz;
//     int l = 0;
// 
//     ifstream data;
//     data.open (s);
//     /*reading in data*/
//     while(data>>datax>>datay>>dataz>>datal>>datab>>datar>>datavx>>datavy>>datavz)
//     {
//         x[l]  = datax;
//         y[l]  = datay;
//         z[l]  = dataz;
//         vx[l] = datavx;
//         vy[l] = datavy;
//         vz[l] = datavz;
// 
//         l = l + 1;
//     }
//     data.close();
// }


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// theory functions

double density(double r, double * args)
{
    
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    
    double pi = 4.0 * atan(1.0);
    double rscale_l_cube = cube(rscale_l); 
    double rscale_d_cube = cube(rscale_d); 

    //   double density_result= (3.0/(4.0*pi))*(mass/rscalecube *pow(1+ sqr/sqrrcube, -2.5));
    double density_light_comp = (mass_l/rscale_l_cube) * minusfivehalves( (1.0 + sqr(r)/sqr(rscale_l) ) );
    double density_dark_comp  = (mass_d/rscale_d_cube) * minusfivehalves( (1.0 + sqr(r)/sqr(rscale_d) ) );
    double coeff = 3.0 / (4.0 * pi);

    double density_result = coeff * ( density_light_comp + density_dark_comp);
    return density_result;
}


//this isn't used
double mass_enc(double r, double * args)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];

    double rcube = cube(r);
    double mass_enclosed_l = mass_l * rcube * pow( (sqr(r) + sqr(rscale_l) ), -1.5);
    double mass_enclosed_d = mass_d * rcube * pow( (sqr(r) + sqr(rscale_d) ), -1.5);
    
    double mass_enclosed = mass_enclosed_l + mass_enclosed_d;
    return mass_enclosed;

}

double potential( double r, double * args)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double pot_light_comp = mass_l/sqrt( sqr(r) + sqr(rscale_l) );
    double pot_dark_comp  = mass_d/sqrt( sqr(r) + sqr(rscale_d) );
    double potential_result = -1.0 * (pot_light_comp + pot_dark_comp);

    return (potential_result);
}


// double get_x()
// {
//     double x = 0.0;
//     double y = 0.1;
//     double u = sqr(x) * sqrt(seventh( (1.0 - sqr(x)) ));
//     while(y > sqr(x) * pow( (1.0 - sqr(x)), 3.5) )
//     {
//         x = randDouble(0.0, 1.0);
//         y = randDouble(0.0, 0.1);
//     }
//     
//     return x;
// }


double distribution(double mass, double r_scale, double v, double r, double * args)
{
    
    double pi  = 4.0 * atan(1.0);
    double coeff = 24.0 * sqrt(2.0) * inv( 7.0 * cube(pi) );
    double energy = -potential(r, args) - 0.5 * sqr(v) ;
    
    double f = v * v * coeff * inv( fourth(mass) ) * sqr(r_scale) * seventhhalfs(fabs(energy));
    
    return f;
    
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// service functions

double esc_vel(double r, double * args)
{
    double escv = sqrt( fabs(2.0 * potential( r, args) ) );
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
}

void com_correction(double * cm, double * cmv, struct bodies * b, int N)
{
    double r_corrected, v_corrected;
    for(int i = 0; i < N; i++)
    {
        r_corrected = sqrt( sqrdif(cm[0], b[i].x)  + sqrdif(cm[1], b[i].y)  + sqrdif(cm[2], b[i].z) );
        v_corrected = sqrt( sqrdif(cm[0], b[i].vx) + sqrdif(cm[1], b[i].vy) + sqrdif(cm[2], b[i].vz) );
        
        b[i].x -= cm[0];
        b[i].y -= cm[1];
        b[i].z -= cm[2];
        
        b[i].vx -= cmv[0];
        b[i].vy -= cmv[1];
        b[i].vz -= cmv[2];
        
        b[i].r = r_corrected;
        b[i].v = v_corrected;
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
void single_density_theory(double bin_width, double * args)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double masspl   = args[4]; 
    double masspd   = args[5];
    
    
    double w = 0.0;
    double light[4] = {rscale_l, rscale_d, mass_l, 0.0};
    double dark[4]  = {rscale_l, rscale_d, 0.0, mass_d};
    double pi = 4.0 * atan(1.0);
    
    double de, de2, de3;
    FILE * rho;
    rho = fopen("./theory/theory_den.dat", "w");
    while(1)
    {
        de2 = 4.0 * pi * w * w * density(w, light) * bin_width / masspl;
        de3 = 4.0 * pi * w * w * density(w, dark)  * bin_width / masspd;
        de = de2 + de3;
        w += 0.001;
        fprintf(rho, "%f \t %f \t %f\t%f\n", w, de, de2, de3);
            
        if( w > 5 * (rscale_l + rscale_d)){break;}
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
            
        if(w>(5.0)){break;}
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

void vel_distribution_theory(double bin_width, int number_of_bins, string extension, double * args, double * r_l, double * r_d, int Nl, int Nd)
{
    
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double masspl   = args[4]; 
    double masspd   = args[5];
    
    double light[4] = {rscale_l, rscale_d, mass_l, mass_d};
    double dark[4]  = {rscale_l, rscale_d, mass_l, mass_d};
    
    double v_l[Nl];
    double v_d[Nd];
    double v, u, f, r;
    double v_esc, v_mx;
    double fmax;
    
    for(int i = 0; i < Nl; i++)
    {
        r = r_l[i];
        v_esc = sqrt( 2.0 * fabs( potential(r, light) ));
        v_mx = (2.0 / 3.0) * sqrt( fabs( potential(r, light) ));
        fmax = distribution(mass_l, rscale_l, v_mx, r, light);
        while(1)
        {
            v = randDouble(0.0, v_esc);
            u = randDouble(0.0,1.0);
            f = distribution(mass_l, rscale_l, v, r, light);
//             printf("f = %f fmax = %f  f/fmax = %f\n", f, fmax, f/fmax);
            if(fabs(f/fmax) > u)
            {
                v *= 0.977813107;
                v_l[i] = v;
                break;
            }
        }
    }
    
    for(int i = 0; i < Nd; i++)
    {
        r = r_d[i];
        v_esc = sqrt( 2.0 * fabs( potential(r, dark) ));
        v_mx = (2.0 / 3.0) * sqrt( fabs( potential(r, dark) ));
        fmax = distribution(mass_d, rscale_d, v_mx, r, dark);
        while(1)
        {
            v = randDouble(0.0, v_esc);
            u = randDouble(0.0,1.0);
            f = distribution(mass_d, rscale_d, v, r, dark);
            if(fabs(f/fmax) > u)
            {
                v *= 0.977813107;
                v_d[i] = v;
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
    
    
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// actual data checking function

void rad_vel_distribution(string extension, int Nd, int Nl, struct bodies * b, int number_of_bins, double bin_width)
{
    int type = 0;
    string s1, s2;
    s1 = string("actual/light_matter_velocity_dist_" + extension + ".dat");
    s2 = string("actual/dark_matter_velocity_dist_" + extension + ".dat");
    ofstream vel_l, vel_d;
    vel_l.open(s1);
    vel_d.open(s2);
    int light = 1;
    int dark = 0;
    double r[Nd + Nl], v[Nd + Nl];
    double rd[Nd], rl[Nl];
    double vd[Nd], vl[Nl];
    int counterl = 0;
    int counterd = 0;
    for(int i = 0; i < N; i++)
    {
        
    }
    
    
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
            rl[countd] = b[i].r;
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
    binner(number_of_bins, bin_width, vel_d, Nd, s, extension, type);                      //
                                                                                           //
    s = string("binned_data/light_matter_vel_bins_" + extension + ".dat");                 //
    binner(number_of_bins, bin_width, vel_l, Nl, s, extension, type);                      //
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
    
    int counterl = 0;
    int counterd = 0;

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
    double rscale_l                = atof(argv[2]);
    double rscale_d                = atof(argv[3]);
    double mass_l                  = atof(argv[4]);
    double mass_d                  = atof(argv[5]);
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
    com(cm, cmv, b, N, mass);
    com_correction(cm, cmv, b, N);

    
    printf(".");//actual 
    rad_vel_distribution(extension, Nd, Nl, b, number_of_bins, bin_width, args);
    
    printf(".");//actual 
    angles(extension, Nl, Nd, b, number_of_bins, bin_width, cm);
    
    printf(".");//theory
    
    double masspd;
    double masspl;
    for(i = 0, i < N; i++)
    {
        if(b[i] == l)
        {
            masspl = b[i].mass;
        }
        else
        { 
            masspd = b[i].mass;
        }
        
        if(masspd != 0.0 && masspl != 0.0){break;}
    }
    double args[6]  = {rscale_l, rscale_d, mass_l, mass_d, masspl, masspd};
    single_density_theory(bin_width, args);

    printf(".");//theory -- from distribution func
    vel_distribution_theory(bin_width, number_of_bins, extension, args, rl, rd, Nl, Nd);

    printf(".");//theory
    angle_theory(bin_width, args);
    
    
    
    
    printf("done.\n");
}
