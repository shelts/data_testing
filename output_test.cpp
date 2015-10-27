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
   while(length>>datax>>datax>>datax>>datax>>datax>>datax)
    {
//       cout<<datax<<endl;
      N++;
    }
    length.close();
   
   return N;
}

/*this actually gets the data and stores it*/
void get_data(int N, double * x,double * y, double * z, double * vx,double * vy, double * vz, int type, string extension)
{
    string s;
    if(type == 0){s = string("raw_data/light_matter_"+extension+".dat");}
    else if(type == 1){s = string("raw_data/dark_matter_"+extension+".dat");}
    double datax,datay,dataz,datavx,datavy,datavz;
    int l = 0;

    ifstream data;
    data.open (s);
    /*reading in data*/
    while(data>>datax>>datay>>dataz>>datavx>>datavy>>datavz)
    {
        x[l]  = datax;
        y[l]  = datay;
        z[l]  = dataz;
        vx[l] = datavx;
        vy[l] = datavy;
        vz[l] = datavz;

        l = l + 1;
    }
    data.close();
}
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

double test(double x, double * args, double * args2)
{
 double func = exp(x) + sin(x) + x;
 return func;
}

double get_x()
{
    double x = 0.0;
    double y = 0.1;
    double u = sqr(x) * sqrt(seventh( (1.0 - sqr(x)) ));
    while(y > sqr(x) * pow( (1.0 - sqr(x)), 3.5) )
    {
        x = randDouble(0.0, 1.0);
        y = randDouble(0.0, 0.1);
    }
    
    return x;
}

double nemo_vel(double r)
{
    double x = get_x();
    double v = x * sqrt(2.0) * pow( (1.0 + sqr(r)) , -0.25);
    return v;
}

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


void com(double * cm, double * xd, double * yd, double * zd,  int Nd, double * xl, double * yl, double * zl, int Nl, double masspd, double masspl, double mass)
{
    double cm_x = 0.0;
    double cm_y = 0.0;
    double cm_z = 0.0;
    
    for(int i = 0; i < Nd; i++)
    {
        cm_x += masspd * xd[i];
        cm_y += masspd * yd[i];
        cm_z += masspd * zd[i];
        
    }
    
    for(int i = 0; i < Nl; i++)
    {
        cm_x += masspl * xl[i];
        cm_y += masspl * yl[i];
        cm_z += masspl * zl[i];
    }
    
    cm[0] = cm_x * inv(mass);
    cm[1] = cm_y * inv(mass);
    cm[2] = cm_z * inv(mass);
    
}

void comv(double * cmv, double * vxd, double * vyd, double * vzd,  int Nd, double * vxl, double * vyl, double * vzl, int Nl, double masspd, double masspl, double mass)
{
    double cm_vx = 0.0;
    double cm_vy = 0.0;
    double cm_vz = 0.0;
    
    for(int i = 0; i < Nd; i++)
    {
        cm_vx += masspd * vxd[i];
        cm_vy += masspd * vyd[i];
        cm_vz += masspd * vzd[i];
        
    }
    
    for(int i = 0; i < Nl; i++)
    {
        cm_vx += masspl * vxl[i];
        cm_vy += masspl * vyl[i];
        cm_vz += masspl * vzl[i];
    }
    
    cmv[0] = cm_vx * inv(mass);
    cmv[1] = cm_vy * inv(mass);
    cmv[2] = cm_vz * inv(mass);
    
}

static double gauss_quad(double (*rootFunc)(double, double *, double *), double * comp_args, double * args, double lower, double upper )
{
    double Ng,hg,lowerg, upperg;
    double intv;
    double coef1,coef2;//parameters for gaussian quad
    double c1, c2, c3;
    double x1, x2, x3;
    double x1n, x2n, x3n;
    
    //this should be from infinity. But the dis func should be negligble here.
    double a = lower; 
    double b = upper;

    intv = 0;//initial value of integral
    Ng = 1000.0;//integral resolution
    hg = (b-a)/(Ng);

    
    lowerg = lower;
    upperg = lowerg + hg; 

    coef2 = (lowerg+upperg)/2.0;//initializes the first coeff to change the function limits
    coef1 = (upperg-lowerg)/2.0;//initializes the second coeff to change the function limits
    c1 = 5.0/9.0;
    c2 = 8.0/9.0;
    c3 = 5.0/9.0;
    x1 = -sqrt(3.0/5.0);
    x2 = 0.0;
    x3 = sqrt(3.0/5.0);
    x1n = (coef1 * x1 + coef2);
    x2n = (coef1 * x2 + coef2);
    x3n = (coef1 * x3 + coef2);
    int counter=0;
    while (1)
    {
                //gauss quad
        intv = intv +  c1 * (*rootFunc)(x1n, comp_args, args) * coef1 +
                       c2 * (*rootFunc)(x2n, comp_args, args) * coef1 + 
                       c3 * (*rootFunc)(x3n, comp_args, args) * coef1;

        lowerg = upperg;
        upperg = upperg + hg;
        coef2  = (lowerg + upperg)/2.0;//initializes the first coeff to change the function limits
        coef1  = (upperg - lowerg)/2.0;

        x1n = ((coef1) * x1 + coef2);
        x2n = ((coef1) * x2 + coef2);
        x3n = ((coef1) * x3 + coef2);

        if(upper > lower)
        {
            if(lowerg >= upper)//loop termination clause
            {
                break;
            }
        }
        else if(lower > upper)
        {
            if(lowerg <= upper)//loop termination clause
            {
                break;
            }
        }
        
        
        counter++;
    }
    return intv;
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

void get_radii(int N, double * x, double * y, double * z, double * r, double * cm)
{
    
    for(int i=0;i<N;i++)
    {
        r[i]= sqrt( sqrdif(cm[0], x[i]) + sqrdif(cm[1], y[i]) + sqrdif(cm[2], z[i]) );
    }
    
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
    double pi= 4.0 * atan(1.0);
    
    double de, de2, de3;
    FILE * rho;
    rho = fopen("./theory/theory_den.dat", "w");
    while(1)
    {
        de2 = 4.0 * pi * w * w * density(w, light) * bin_width / masspl;
        de3 = 4.0 * pi * w * w * density(w, dark)  * bin_width / masspd;
        de = de2 + de3;
        w += 0.01;
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

void vel_theory(double bin_width, double * args)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double masspl   = args[4]; 
    double masspd   = args[5];
    
    double q = 0.0;
    double g;
    double pi = 4.0 * atan(1.0);
    double n;
    
    FILE * vel;
    vel= fopen("./theory/theory_vel.dat", "w");
    while(1)
    {
        g = sqr(q) * seventhhalfs(1.0 - sqr(q)) * 20000.0 * 0.01 * 4.0 * pi;
        q += 0.001;
        fprintf(vel, "%f \t %f\n", q, g);
            
        if( q > 1.0){break;}
    }
    fclose(vel);
}

void vel_distribution_theory(double bin_width, int number_of_bins, string extension, double * args, double * r_l, double * r_d, int Nl, int Nd)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double masspl   = args[4]; 
    double masspd   = args[5];
    
    double light[4] = {rscale_l, rscale_d, mass_l, 0.0};
    double dark[4]  = {rscale_l, rscale_d, 0.0, mass_d};
    
    double v_l[Nl];
    double v_d[Nd];
    double v, u, f, r;
    double v_esc, v_mx;
    double fmax;
    
    for(int i = 0; i < Nl; i++)
    {
        r = r_l[i];
        v_esc = sqrt( 2.0 * fabs( potential(r, light) ));
        v_mx = (2.0/3.0) * sqrt( fabs( potential(r, light) ));
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
        v_mx = (2.0/3.0) * sqrt( fabs( potential(r, dark) ));
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

void nemo_vel_distribution_theory(double bin_width, int number_of_bins, string extension, double * args, double * r_l, double * r_d, int Nl, int Nd)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double masspl   = args[4]; 
    double masspd   = args[5];
    
    double light[4] = {rscale_l, rscale_d, mass_l, 0.0};
    double dark[4]  = {rscale_l, rscale_d, 0.0, mass_d};
    
    double v_l[Nl];
    double v_d[Nd];
    double v, u, f, r;
    double v_esc, v_mx;
    double fmax;
    
    for(int i = 0; i < Nl; i++)
    {
        r = r_l[i];
        v_l[i] = nemo_vel(r);
        v_l[i] *= 0.977813107;
        
    }
    
    for(int i = 0; i < Nd; i++)
    {
        r = r_d[i];
        v_d[i] = nemo_vel(r);
        v_d[i] *= 0.977813107;
    }
    
    string s;
    int type = 0;
    s = string("binned_data/dark_matter_theory_nemo_vel_bins.dat");
    binner(number_of_bins, bin_width, v_d, Nd, s, extension, type);
    s = string("binned_data/light_matter_theory_nemo_vel_bins.dat");
    binner(number_of_bins, bin_width, v_l, Nl, s, extension, type);
    
    
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// actual data checking function

void radial_distribution(string extension, int Nd, int Nl, double * rd, double * rl, int number_of_bins, double bin_width, double * args)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double masspl   = args[4]; 
    double masspd   = args[5];
    int type = 0;
    string s;
    s= string("actual/dark_matter_density_"+extension+".dat");
    ofstream dens;
    dens.open(s);
    double r[Nd + Nl];
    
    for(int i = 0; i < Nd; i++)
    {
        dens<<rd[i]<<endl;
        r[i] = rd[i];
    }
    dens.close();
    
    s= string("actual/light_matter_density_"+extension+".dat");
    dens.open(s);
    for(int i=0;i<Nl;i++)
    {
        r[i+Nd] = rl[i];
        dens<<rl[i]<<endl;
    }
    dens.close();
    
    
    s = string("binned_data/both_matter_bins_" + extension + ".dat");
    binner(number_of_bins, bin_width, r, Nd + Nl, s, extension, type);
    
    s = string("binned_data/dark_matter_bins_" + extension + ".dat");
    binner(number_of_bins, bin_width, rd, Nd, s, extension, type);
    
    s = string("binned_data/light_matter_bins_" + extension + ".dat");
    binner(number_of_bins, bin_width, rl, Nl, s, extension, type);
}

void angles(string extension, int Nl, int Nd, double * rl, double * rd, double * xl, double * yl, double * zl, double * xd, double * yd, double * zd, int number_of_bins, double bin_width, double * cm)
{
    int N = Nl + Nd;
    double r[N];
    double theta_l[Nl];
    double theta_d[Nd];
    double theta[N];
    double phi[N];
    double phi_l[Nl];
    double phi_d[Nd];
    string s;
    
    int j = 0;
    for(int i = 0; i < Nl; i++)
    {
        theta_l[i] = acos( (cm[2] - zl[i]) / rl[i] );
        phi_l[i] = atan2( (cm[1] - yl[i]) , (cm[0] - xl[i]) );
        
        theta[j] = theta_l[i];
        phi[j] = phi_l[i];
        j++;
    }
    
    for(int i = 0; i < Nd; i++)
    {
        theta_d[i] = acos( (cm[2] - zd[i]) / rd[i] );
        phi_d[i] = atan2( (cm[1] - yd[i]) , (cm[0] - xd[i]) );
        
        theta[j] = theta_d[i];
        phi[j] = phi_d[i];
        j++;
    }
    
    int type = 0;
    s = string("binned_data/theta_light_" + extension + ".dat");
    binner(number_of_bins, bin_width, theta_l, Nl, s, extension, type);
    s = string("binned_data/theta_dark_" + extension + ".dat");
    binner(number_of_bins, bin_width, theta_d, Nd, s, extension, type);
    s = string("binned_data/theta_both_" + extension + ".dat");
    binner(number_of_bins, bin_width, theta, N, s, extension, type);
    
    type = 1;
    s = string("binned_data/phi_light_" + extension + ".dat");
    binner(number_of_bins, bin_width, phi_l, Nl, s, extension, type);
    s = string("binned_data/phi_dark_" + extension + ".dat");
    binner(number_of_bins, bin_width, phi_d, Nd, s, extension, type);
    s = string("binned_data/phi_both_" + extension + ".dat");
    binner(number_of_bins, bin_width, phi, N, s, extension, type);
    
}

void vel_angles(string extension, int Nl, int Nd, double * vl, double * vd, double * vxl, double * vyl, double * vzl, double * vxd, double * vyd, double * vzd, int number_of_bins, double bin_width, double * cmv )
{
    int N = Nl + Nd;
    double v[N];
    string s;
    int type = 0;
    double theta_l[Nl];
    double theta_d[Nd];
    double theta[N];
    double phi[N];
    double phi_l[Nl];
    double phi_d[Nd];
    
    int j = 0;
    for(int i = 0; i < Nl; i++)
    {
        theta_l[i] = acos( (cmv[2] - vzl[i]) / vl[i] );
        phi_l[i] = atan2( (cmv[1] - vyl[i]) , (cmv[0] - vxl[i]) );
        
        theta[j] = theta_l[i];
        phi[j] = phi_l[i];
        j++;
    }
    
    for(int i = 0; i < Nd; i++)
    {
        theta_d[i] = acos( (cmv[2] - vzd[i]) / vd[i] );
        phi_d[i] = atan2( (cmv[1] - vyd[i]) , (cmv[0] - vxd[i]) );
        
        theta[j] = theta_d[i];
        phi[j] = phi_d[i];
        j++;
    }
    
    s = string("binned_data/theta_vel_light_"+extension+".dat");
    binner(number_of_bins, bin_width, theta_l, Nl, s, extension, type);
    s = string("binned_data/theta_vel_dark_"+extension+".dat");
    binner(number_of_bins, bin_width, theta_d, Nd, s, extension, type);
    s = string("binned_data/theta_vel_both_"+extension+".dat");
    binner(number_of_bins, bin_width, theta, N, s, extension, type);
    
    type = 1;
    s = string("binned_data/phi_vel_light_"+extension+".dat");
    binner(number_of_bins, bin_width, phi_l, Nl, s, extension, type);
    s = string("binned_data/phi_vel_dark_"+extension+".dat");
    binner(number_of_bins, bin_width, phi_d, Nd, s, extension, type);
    s = string("binned_data/phi_vel_both_"+extension+".dat");
    binner(number_of_bins, bin_width, phi, N, s, extension, type);
    
}


void vel_dis(string extension, double * args, int Nl, int Nd, double * vel_l, double * vel_d, double * rl, double * rd, int number_of_bins, double bin_width)
{

    int type = 0;
    string s;
    double vsc;
    s = string("actual/light_matter_velocity_dist_" + extension + ".dat");
    ofstream vel;
    vel.open(s);
    for(int i = 0; i < Nl; i++)
    {
        vel<<rl[i]<<"\t"<<vel_l[i]<<endl;
    }
    vel.close();
    
    s = string("actual/dark_matter_velocity_dist_" + extension + ".dat");
    ofstream vel2;
    vel2.open(s);
    for(int i = 0; i < Nd; i++)
    {
        vel2<<rd[i]<<"\t"<<vel_d[i]<<endl;
    }
    vel2.close();

    double vd[Nd];
    double vl[Nl];
    
    for(int i = 0; i < Nl; i++)
    {
        vsc = esc_vel(rl[i], args);
        vl[i] = vel_l[i] / (vsc);
    }
    
     for(int i = 0; i < Nd; i++)
    {
        vsc = esc_vel(rd[i], args);
        vd[i] = vel_d[i] / (vsc);
    }
    
    s = string("binned_data/dark_matter_vel_bins_" + extension + ".dat");
    binner(number_of_bins, bin_width, vel_d, Nd, s, extension, type);
    s = string("binned_data/light_matter_vel_bins_" + extension + ".dat");
    binner(number_of_bins, bin_width, vel_l, Nl, s, extension, type);
    
    bin_width = 0.01;
    s = string("binned_data/dark_matter_norm_vel_bins_" + extension + ".dat");
    binner(number_of_bins, bin_width, vd, Nd, s, extension, type);
    s = string("binned_data/light_matter_norm_vel_bins_" + extension + ".dat");
    binner(number_of_bins, bin_width, vl, Nl, s, extension, type);
  
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
    double mass_per_particle_light = atof(argv[6]); 
    double mass_per_particle_dark  = atof(argv[7]); 
    string extension = simtime + "gy";
    
//     printf("massl = %f  massd = %f rscale_l = %f rscale_d = %f\n", mass_l, mass_d, rscale_l, rscale_d);
    double args[6]  = {rscale_l, rscale_d, mass_l, mass_d, mass_per_particle_light, mass_per_particle_dark};

    //    printf("rad_light= %f \t rad_dark=%f \n mass_light=%f \t mass_dark=%f\n", rscale_l, rscale_d, mass_l, mass_d);

    /*paramters for binning routine*/
    int number_of_bins = 1000;
    double bin_width = .10;

    /*these are markers for the type of data being sent into functions*/
    int d = 1;//dark matter     
    int l = 0;//light matter
    
    int Nd = get_size(d, extension);//getting the size of the dark matter data
    int Nl = get_size(l, extension);//getting the size of the light matter data
    printf("light: %i dark: %i\n", Nl, Nd);
    double rd[Nd], rl[Nl];//, r[Nd+Nl];  
    double vel_d[Nd], vel_l[Nl];


//     printf("Nl = %i  Nd = %i\n", Nl, Nd);
    double dx[Nd], dy[Nd], dz[Nd], dvx[Nd], dvy[Nd], dvz[Nd];//vectors to store dark positions
    double lx[Nl], ly[Nl], lz[Nl], lvx[Nl], lvy[Nl], lvz[Nl];//vectors to store light positions
    double dv[Nd];//this is a vector to store the velocity distribution
    double lv[Nl];//this is a vector to store the velocity distribution
    
    double cm[3] = {0.0, 0.0, 0.0};
    double cmv[3] = {0.0, 0.0, 0.0};
    double mass;
    
//     double tst1 = gauss_quad(test, args, args, 0.0, 5.0 );
//     double tst2 = gauss_quad(test, args, args,  5.0, 0.0);
//     printf("test = %f  %f\n", tst1, tst2);
    
    printf("running tests");
    /*getting the positional and velocity data*/
    get_data(Nd, dx, dy, dz, dvx, dvy, dvz, d, extension);  
    get_data(Nl, lx, ly, lz, lvx, lvy, lvz, l, extension);
    
    
    /*get center of mass*/
    mass = mass_l + mass_d;
    com(cm, dx, dy, dz, Nd, lx, ly, lz, Nl, mass_per_particle_dark, mass_per_particle_light, mass);
    comv(cmv, dx, dy, dz, Nd, lx, ly, lz, Nl, mass_per_particle_dark, mass_per_particle_light, mass);

    /*getting the radii and vel vectors*/
    get_radii(Nd, dx, dy, dz, rd, cm);
    get_radii(Nl, lx, ly, lz, rl, cm);
    get_radii(Nd, dvx, dvy, dvz, vel_d, cmv);
    get_radii(Nl, lvx, lvy, lvz, vel_l, cmv);

    
    /*radii*/
    printf(".");//actual 
    radial_distribution(extension, Nd, Nl, rd, rl, number_of_bins, bin_width, args);
    
    printf(".");//theory
    single_density_theory(bin_width, args);
    
    /*angles*/
    printf(".");//actual for radii
    angles(extension, Nl, Nd, rl, rd, lx, ly, lz, dx, dy, dz, number_of_bins, bin_width, cm);
    
    printf(".");//actual for vel
    vel_angles(extension, Nl, Nd, vel_l, vel_d, lvx, lvy, lvz, dvx, dvy, dvz, number_of_bins, bin_width, cmv);
    
    printf(".");//theory
    angle_theory(bin_width, args);
    
    
    /*velocity*/
    printf(".");//actual
    vel_dis(extension, args, Nl, Nd, vel_l, vel_d, rl, rd, number_of_bins, bin_width);
    
    printf(".");//theory -- vel curves
    
    vel_theory(bin_width, args);
    
    printf(".");//theory -- from distribution func
    vel_distribution_theory(bin_width, number_of_bins, extension, args, rl, rd, Nl, Nd);
    nemo_vel_distribution_theory(bin_width, number_of_bins, extension, args, rl, rd, Nl, Nd);
    
    
    printf("done.\n");
}
