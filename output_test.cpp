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

using namespace std;

#define inv(x)  ((double) 1.0 / (x))
#define sixth(x) ((x) * (x) * (x) * (x) * (x) * (x))
#define fourth(x) ((x) * (x) * (x) * (x))
#define fifth(x) ((x) * (x) * (x) * (x) * (x))
#define cube(x) ((x) * (x) * (x))
#define sqr(x)  ((x) * (x))


#define fivehalves(x) ( sqrt(fifth(x) ) )
#define threehalves(x) ( sqrt(cube(x)  ) )

#define minusfivehalves(x) (inv(fivehalves(x)))
#define minusthreehalves(x) (inv(threehalves(x)) )
#define minushalf(x) ( inv(sqrt(x)) )


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
    double coeff = (3.0/(4.0*(pi)));

    double density_result = coeff*( density_light_comp + density_dark_comp);
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


double potential_total_int(double r, double * args)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    
    double pi= 4.0 * atan(1.0);
    double pot = potential(r, args);
    double den = density(r, args);
    double func = sqr(r) * pot * den;
    
//     printf("func = %f pot = %f den = %f \n", func, pot, den);
    return func;
    
}


double potential_total_calc(double r, double * args)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    
    double pi= 4.0 * atan(1.0);
    
    double func_light_comp = 3.0 * sqr(mass_l) * inv(2.0 * sixth(rscale_l)) * fourth(r) * inv( sqr( 1.0 + sqr(r)/sqr(rscale_l)) );
    double func_dark_comp  = 3.0 * sqr(mass_d) * inv(2.0 * sixth(rscale_d)) * fourth(r) * inv( sqr( 1.0 + sqr(r)/sqr(rscale_d)) );
    
    double func = (func_light_comp + func_dark_comp);
    
//     printf("func = %f pot = %f den = %f \n", func, pot, den);
    return func;
    
}

double test(double x, double * args)
{
 double func = exp(x) * sin(x) * x;
 return func;
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// service functions

static double gauss_quad(double (*rootFunc)(double, double *), double * args, double lower, double upper )
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    
    double Ng,hg,lowerg, upperg;
    double intv;
    double coef1,coef2;//parameters for gaussian quad
    double c1,c2,c3;
    double x1,x2,x3;
    double x1n,x2n,x3n;
    
    //this should be from infinity. But the dis func should be negligble here.
    double a = lower; 
    double b = upper;
    

    intv = 0;//initial value of integral
    Ng = 1000.0;//integral resolution
    hg = fabs(b-a)/(Ng);
/*I have set the lower limit to be zero. '
 * This is in the definition of the distribution function. 
 * If this is used for integrating other things, this will need to be changed.*/
    lowerg = 0.0;
    upperg = lowerg+hg;
    

    coef2 = (lowerg+upperg)/2.0;//initializes the first coeff to change the function limits
    coef1 = (upperg-lowerg)/2.0;//initializes the second coeff to change the function limits
    c1 = 0.555555556;
    c2 = 0.888888889;
    c3 = 0.555555556;
    x1 = -0.774596669;
    x2 = 0.000000000;
    x3 = 0.774596669;
    x1n = ((coef1) * x1 + coef2);
    x2n = ((coef1) * x2 + coef2);
    x3n = ((coef1) * x3 + coef2);
    int counter=0;
    while (1)
    {
                //gauss quad
        intv= intv +(c1 * (*rootFunc)(x1n, args) * coef1 +
                     c2 * (*rootFunc)(x2n, args) * coef1 + 
                     c3 * (*rootFunc)(x3n, args) * coef1);

        lowerg = upperg;
        upperg = upperg + hg;
        coef2 = (lowerg + upperg)/2.0;//initializes the first coeff to change the function limits
        coef1 = (upperg - lowerg)/2.0;

        x1n = ((coef1) * x1 + coef2);
        x2n = ((coef1) * x2 + coef2);
        x3n = ((coef1) * x3 + coef2);


        if (lowerg >= b)//loop termination clause
        {
            break;
        }
        counter++;
    }
    return intv;
}


/*this is a binning routine, makes a histogram*/
void binner(int binN,double binwidth, double * x, int N, int type, string extension)
{
    // binN=number of bins
    //binwidthsize of bins
    double bins[binN];
    double range = 0;
    double upper = binN*binwidth;
    string s;
         if(type == 1){s = string("binned_data/dark_matter_bins_"+extension+".dat");}
    else if(type == 0){s = string("binned_data/light_matter_bins_"+extension+".dat");}

    else if(type == 2){s = string("binned_data/dark_matter_vel_bins_"+extension+".dat");}
    else if(type == 3){s = string("binned_data/light_matter_vel_bins_"+extension+".dat");}

    else if(type == 4){s = string("binned_data/theta_light_"+extension+".dat");}
    else if(type == 5){s = string("binned_data/theta_dark_"+extension+".dat");}
    else if(type == 6){s = string("binned_data/theta_both_"+extension+".dat");}

    else if(type == 7){s = string("binned_data/phi_light_"+extension+".dat");}
    else if(type == 8){s = string("binned_data/phi_dark_"+extension+".dat");}
    else if(type == 9){s = string("binned_data/phi_both_"+extension+".dat");}

    else if(type == 10){s = string("binned_data/pot_dark_"+extension+".dat");}
    else if(type == 11){s = string("binned_data/pot_light_"+extension+".dat");}

    /*binning*/

    /*initializing bins*/
    for(int i = 0; i != binN; i++)
    {bins[i] = 0;}
    ofstream bin;
    bin.open (s);
    
    for(int j = 0; j < N; j++)/*tests one of the numbers at a time*/
    {
        
        range = 0;/*resets the range so that the bins can be tested again against the number*/
        if(type == 7 || type == 8 || type == 9)
        {
            range = -4.0;
            upper = 4.0;
        }
        if(type == 10 || type == 11 )
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
    if(type == 7 || type == 8 || type == 9)
    {
        binrange = -4.0;
    }
    
    if(type == 10 || type == 11 )
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

void get_radii(int N, double * x, double * y, double * z, double * r)
{
    
    for(int i=0;i<N;i++)
    {
        r[i]= sqrt( x[i]*x[i] +y[i]*y[i] + z[i]*z[i] );
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
    rho= fopen("./theory/theory_den.dat", "w");
    while(1)
    {
        de2 = 4.0 * pi * w * w * density(w, light) * bin_width/ masspl;
        de3 = 4.0 * pi * w * w * density(w, dark) * bin_width / masspd;
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
    
    double pi= 4.0 * atan(1.0);
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

void potential_theory(double bin_width, double * args)
{
    
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double masspl   = args[4]; 
    double masspd   = args[5];
    
    double light[4] = {rscale_l, rscale_d, mass_l, 0.0};
    double dark[4]  = {rscale_l, rscale_d, 0.0, mass_d};
    double pot_all, pot_l, pot_d;
    double pi= 4.0 * atan(1.0);
    double w = 0.0;
    
    //done via integral:
    FILE * pot;
    pot= fopen("./theory/theory_pot_int.dat", "w");
    while(1)
    {
        pot_l    = 4.0 * pi * gauss_quad(potential_total_int, light, 0.0, w) * bin_width;
        pot_d    = 4.0 * pi * gauss_quad(potential_total_int, dark, 0.0, w)  * bin_width;
        pot_all  = 4.0 * pi * gauss_quad(potential_total_int, args, 0.0, w)  * bin_width ;
        w += 0.01;
        fprintf(pot, "%f \t %f \t %f\t%f\n", w, pot_all, pot_l, pot_d);
            
        if( w > 5 * (rscale_l + rscale_d)){break;}
    }
    fclose(pot);
    
    //done via analytical calc
    FILE * pot2;
    pot2= fopen("./theory/theory_pot_calc.dat", "w");
    w = 0.0;
    while(1)
    {
        pot_l = potential_total_calc(w, light);
        pot_d = potential_total_calc(w, dark) ;
        pot_all = pot_l + pot_d;
        w += 0.01;
        fprintf(pot2, "%f \t %f \t %f\t%f\n", w, pot_all, pot_l, pot_d);
            
        if( w > 5 * (rscale_l + rscale_d)){break;}
    }
    fclose(pot2);
    
    
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// actual data checking function



void radial_distribution(int type, string extension, int N, double * r, int number_of_bins, double bin_width, double rscale, double mass)
{
    string s;
    if(type==1){s= string("actual/dark_matter_density_"+extension+".dat");}
    else if(type==0){s= string("actual/light_matter_density_"+extension+".dat");}

    ofstream dens;
    dens.open(s);
    for(int i=0;i<N;i++)
    {
        dens<<r[i]<<endl;
    }
    dens.close();
    binner(number_of_bins, bin_width, r, N, type, extension);
}

void angles(string extension, int Nl, int Nd, double * xl, double * yl, double * zl, double * xd, double * yd, double * zd, int number_of_bins, double bin_width )
{
    double rl[Nl];
    double rd[Nd]; 
    int N = Nl + Nd;
    double r[N];
    int type;
    double theta_l[Nl];
    double theta_d[Nd];
    double theta[N];
    double phi[N];
    double phi_l[Nl];
    double phi_d[Nd];
    
    int j = 0;
    for(int i = 0; i < Nl; i++)
    {
        rl[i] = sqrt( sqr(xl[i]) + sqr(yl[i]) + sqr(zl[i]) );
        theta_l[i] = acos( zl[i] / rl[i] );
        phi_l[i] = atan2( yl[i] , xl[i] );
        
        theta[j] = theta_l[i];
        phi[j] = phi_l[i];
        j++;
    }
    
    for(int i = 0; i < Nl; i++)
    {
        rd[i] = sqrt( sqr(xd[i]) + sqr(yd[i]) + sqr(zd[i]) );
        theta_d[i] = acos( zd[i] / rd[i]);
        phi_d[i] = atan2( yd[i] , xd[i] );
        
        theta[j] = theta_d[i];
        phi[j] = phi_d[i];
        j++;
    }
    
    type = 4;
    binner(number_of_bins, bin_width, theta_l, Nl, type, extension);
    type = 5;
    binner(number_of_bins, bin_width, theta_d, Nd, type, extension);
    type = 6;
    binner(number_of_bins, bin_width, theta, N, type, extension);
    
    type = 7;
    binner(number_of_bins, bin_width, phi_l, Nl, type, extension);
    type = 8;
    binner(number_of_bins, bin_width, phi_d, Nd, type, extension);
    type = 9;
    binner(number_of_bins, bin_width, phi, N, type, extension);
    
}


void vel_dis(int type, string extension, int N, double * v, double * r,double number_of_bins, double bin_width, double rscale, double mass)
{

  string s;
  if(type == 3){s = string("actual/light_matter_velocity_dist_"+extension+".dat");}
  else if(type == 2){s = string("actual/dark_matter_velocity_dist_"+extension+".dat");}
  
  ofstream vel;
  vel.open(s);
  for(int i = 0; i < N; i++)
  {
    vel<<r[i]<<"\t"<<v[i]<<endl;
  }
  vel.close();
  binner(number_of_bins, bin_width, v, N, type, extension);
  
}

void potential_distribution(double bin_width, double number_of_bins, string extension, double * args, double * rl, int Nl, double * rd, int Nd)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double masspl   = args[4]; 
    double masspd   = args[5];
    int type;
    double light[4] = {rscale_l, rscale_d, mass_l, 0.0};
    double dark[4]  = {rscale_l, rscale_d, 0.0, mass_d};
    
    double pot_d[Nd];
    double pot_l[Nl];
    double r;
    
    ofstream pod;
    pod.open("./actual/dark_potential_" + extension + ".dat");
    ofstream pol;
    pol.open("./actual/light_potential_" + extension + ".dat");
    for(int i = 0; i < Nd; i++)
    {
        r = rd[i];
        pot_d[i] = potential(r, dark);
        pod<<r <<"\t"<<pot_d[i]<<endl;
    }
    
    for(int i = 0; i < Nl; i++)
    {
        r = rl[i];
        pot_l[i] = potential(r, light);
        pol<<r <<"\t"<<pot_l[i]<<endl;
    }
    
    
    type = 10;
    binner(number_of_bins, bin_width, pot_d, Nd, type, extension);
    type = 11;
    binner(number_of_bins, bin_width, pot_l, Nl, type, extension);
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// main function calls
int main (int argc, char * const argv[])
{
    /*taking in command line data. should be the same parameters used to calculate the simulation*/
    string simtime          = argv[1];
    double backtime         = atof(argv[2]);
    double rscale_l         = atof(argv[3]);
    double light_r_ratio    = atof(argv[4]);
    double dwarfmass        = atof(argv[5]);
    double light_mass_ratio = atof(argv[6]);

    double Nbody = 20000; 


    string extension = simtime + "gy";
    /*changes the parameters to usable info*/
    double massl = dwarfmass * light_mass_ratio;
    double massd = dwarfmass - (dwarfmass * light_mass_ratio);
    double mass_per_particle_dark = massd/ (0.5 * Nbody);
    double mass_per_particle_light = massl/ (0.5 * Nbody);
    double rscale_d = rscale_l / light_r_ratio;

    double args[6]  = {rscale_l, rscale_d, massl, massd, mass_per_particle_light, mass_per_particle_dark};

    //    printf("rad_light= %f \t rad_dark=%f \n mass_light=%f \t mass_dark=%f\n", rscale_l, rscale_d, massl, massd);

    /*paramters for binning routine*/
    int number_of_bins = 1000;
    double bin_width = .10;

    /*these are markers for the type of data being sent into functions*/
    int d = 1;//dark matter
    int l = 0;//light matter
    int vd = 2;//vel
    int vl = 3;//vel
    int Nd = get_size(d, extension);//getting the size of the dark matter data
    int Nl = get_size(l, extension);//getting the size of the light matter data

    double rd[Nd], rl[Nl];//, r[Nd+Nl];  
    double vel_d[Nd], vel_l[Nl];


    printf("Nl = %i  Nd = %i\n", Nl, Nd);
    double dx[Nd], dy[Nd],dz[Nd],dvx[Nd], dvy[Nd],dvz[Nd];//vectors to store dark positions
    double lx[Nl], ly[Nl],lz[Nl],lvx[Nl], lvy[Nl],lvz[Nl];//vectors to store light positions
    double dv[Nd];//this is a vector to store the velocity distribution
    double lv[Nl];//this is a vector to store the velocity distribution

    printf("running tests");
    /*getting the positional and velocity data*/
    get_data(Nd, dx, dy, dz, dvx, dvy, dvz, d, extension);  
    get_data(Nl, lx, ly, lz, lvx, lvy, lvz, l, extension);

    /*getting the radii and vel vectors*/
    get_radii(Nd, dx, dy, dz, rd);
    get_radii(Nl, lx, ly, lz, rl);
    get_radii(Nd, dvx, dvy, dvz, vel_d);
    get_radii(Nl, lvx, lvy, lvz, vel_l);
    
    
    /*actual data*/
    printf(".");
    radial_distribution(d, extension, Nd, rd, number_of_bins, bin_width, rscale_d, massd);
    printf(".");
    radial_distribution(l, extension, Nl, rl, number_of_bins, bin_width, rscale_l, massl);
    printf(".");
    angles(extension, Nl, Nd, lx, ly, lz, dx, dy, dz, number_of_bins, bin_width );
    printf(".");
    potential_distribution(bin_width, number_of_bins, extension, args, rl, Nl, rd, Nd);


    /*theory*/
    printf(".");
    single_density_theory(bin_width, args);
    printf(".");
    angle_theory(bin_width, args);
    printf(".");
    potential_theory(bin_width, args);

    double tester = gauss_quad(test, args, 0.0, 5.0);
    //   printf(" int = %f \n", tester);

    printf("done.\n");

}


//test