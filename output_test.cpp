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

#define fifth(x) ((x) * (x) * (x) * (x) * (x))
#define cube(x) ((x) * (x) * (x))
#define sqr(x)  ((x) * (x))
#define inv(x)  ((double) 1.0 / (x))

#define fivehalves(x) ( sqrt(fifth(x) ) )
#define threehalves(x) ( sqrt(cube(x)  ) )

#define minusfivehalves(x) (inv(fivehalves(x)))
#define minusthreehalves(x) (inv(threehalves(x)) )
#define minushalf(x) ( inv(sqrt(x)) )

double potential( double r, double mass, double rscale)
{
  double sqrsq=rscale*rscale;
  double sqr=r*r;
  double potential_result= -1.0*(mass/pow((sqr + sqrsq),2));
  
  return (-1.0*potential_result);
}

double density(double r, double * args)
{
    
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    
    double pi=4.0*atan(1.0);
    double rscale_l_cube = cube(rscale_l); 
    double rscale_d_cube = cube(rscale_d); 

    //   double density_result= (3.0/(4.0*pi))*(mass/rscalecube *pow(1+ sqr/sqrrcube, -2.5));
    double density_light_comp=(mass_l/rscale_l_cube) * minusfivehalves( (1.0 + sqr(r)/sqr(rscale_l) ) );
    double density_dark_comp= (mass_d/rscale_d_cube)  * minusfivehalves( (1.0 + sqr(r)/sqr(rscale_d) ) );
    double coeff=(3.0/(4.0*(pi)));

    double density_result= coeff*( density_light_comp + density_dark_comp);
    return density_result;
}

double mass_enc(double r, double rscale, double mass)
{
  double rcube=r*r*r;
  double mass_enclosed= mass*rcube*pow( (r*r+ rscale*rscale), -1.5);
 
  return mass_enclosed;
  
}

/*This gets the number of positional data from the raw data files*/
int get_size(int type, string extension)
{
  string s;
    if(type==0){s= string("./raw_data/light_matter_"+extension+".dat");}
  else {s= string("./raw_data/dark_matter_"+extension+".dat");}
   int N=0;
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
  if(type==0){s= string("raw_data/light_matter_"+extension+".dat");}
  else if(type==1){s= string("raw_data/dark_matter_"+extension+".dat");}
  double datax,datay,dataz,datavx,datavy,datavz;
  int l=0;
  
  ifstream data;
  data.open (s);
  /*reading in data*/
  while(data>>datax>>datay>>dataz>>datavx>>datavy>>datavz)
  {
    x[l] =datax;
    y[l] =datay;
    z[l] =dataz;
    vx[l]=datavx;
    vy[l]=datavy;
    vz[l]=datavz;
    
    l=l+1;
  }
  data.close();
}

/*this is a binning routine, makes a histogram*/
void binner(int binN,double binwidth, double * x,int N, int type, string extension)
{
  // binN=number of bins
  //binwidthsize of bins
  double bins[binN];
  double range=0;
  double upper=binN*binwidth;
  string s;
  if(type==1){s= string("binned_data/dark_matter_bins_"+extension+".dat");}
  else if(type==0){s= string("binned_data/light_matter_bins_"+extension+".dat");}
  else if(type==2){s= string("binned_data/dark_matter_vel_bins_"+extension+".dat");}
  else if(type==3){s= string("binned_data/light_matter_vel_bins_"+extension+".dat");}
  else if(type==4){s=string("binned_data/theta_light_"+extension+".dat");}
  else if(type==5){s=string("binned_data/theta_dark_"+extension+".dat");}
  else if(type==6){s=string("binned_data/theta_both_"+extension+".dat");}
  
  else if(type==7){s=string("binned_data/phi_light_"+extension+".dat");}
  else if(type==8){s=string("binned_data/phi_dark_"+extension+".dat");}
  else if(type==9){s=string("binned_data/phi_both_"+extension+".dat");}
  
/*binning*/

/*initializing bins*/
  for(int i=0; i!=binN;i++)
    {bins[i]=0;}
  ofstream bin;
  bin.open (s);

  for(int j=0; j<N;j++)/*tests one of the numbers at a time*/
  {
      range=0;/*resets the range so that the bins can be tested again against the number*/
      for(int i=0;i<binN;i++)/*for each bin, the number is tested*/
      {
            /*these two if statements justs for end points. if the range of the bin
            includes the upper interval, 1, then the second one runs. if not the first
            one runs. the only difference is the first is only less than range+binwidth
            and the second is less than or equal to range+binwidth. */
	  if((range+binwidth)< upper)
	  {
	      /*this if statement tests to see if the random number is in that
	      bin range.*/
	      if (x[j]>=range && x[j]< (range+binwidth))
	      {
                bins[i]=bins[i]+1;
                break;
	      }
	      range=range+binwidth;/*this statement changes the range of testing
	      so that a new new bin can be checked against the number*/
	  }
	  else if((range+binwidth)==upper)/*includes the upper interval*/
	  {
	      if (x[j]>=range && x[j]<= (range+binwidth))
	      {
		bins[i]=bins[i]+1;
	        break;
	      }
	      range=range+binwidth;
	  }

      }
  }

  double total=0;
  double binrange=0;
  double normed;
  for(int i=0; i!=binN;i++)
  {
      binrange=binrange+binwidth;
//       normed=(bins[i])/double(N);
//       bin<<normed<<"\t"<<binrange<<endl;
	bin<<bins[i]<<"\t"<<binrange<<endl;
  }
  bin.close();
}

void single_density_theory(double mass_l, double rscale_l, double mass_d, double rscale_d, double bin_width, double masspd, double masspl)
{
    double w = 0.0;
    double args[4]  = {rscale_l, rscale_d, mass_l, mass_d};
    double light[4] = {rscale_l, rscale_d, mass_l, 0.0};
    double dark[4]  = {rscale_l, rscale_d, 0.0, mass_d};
    double pi= 4.0 * atan(1.0);
    
    double de, de2, de3;
    FILE * rho;
    rho= fopen("./theory/theory.dat", "w");
    while(1)
    {
        de2 = 4.0 * pi * w * w * density(w, light) * bin_width/ masspl;
        de3 = 4.0 * pi * w * w * density(w, dark) * bin_width / masspd;
        de = de2 + de3;
        w=w+0.01;
        fprintf(rho, "%f \t %f \t %f\t%f\n", w, de, de2, de3);
            
        if(w>5*(rscale_l+rscale_d)){break;}
    }
}

void angle_theory( double bin_width, double masspd, double masspl)
{
    double pi= 4.0 * atan(1.0);
    double theta_l, theta_d, theta;
    double phi_l, phi_d, phi;
    FILE * th;
    double w = 0.0;
    th= fopen("./theory/theory_theta.dat", "w");
    while(1)
    {
        theta_l = 2.0 * pi * sin(w) * bin_width /  masspl;
        theta_d = 2.0 * pi * sin(w) * bin_width / masspd;
        theta = theta_l + theta_d;
        w=w+0.01;
        fprintf(th, "%f \t %f \t %f\t%f\n", w, theta, theta_l, theta_d);
            
        if(w>(5.0)){break;}
    }
    
    FILE * ph;
    w = 0.0;
    ph= fopen("./theory/theory_phi.dat", "w");
    while(1)
    {
        phi_l = 2.0 * pi * sin(w) * bin_width /  masspl;
        phi_d = 2.0 * pi * sin(w) * bin_width / masspd;
        phi = theta_l + theta_d;
        w=w+0.01;
        fprintf(ph, "%f \t %f \t %f\t%f\n", w, phi, phi_l, phi_d);
            
        if(w>(5.0)){break;}
    }
    
    fclose(th);
    fclose(ph);
}


/*This uses the data and plots the radial distribution*/
void radial_distribution(int type, string extension, int N, double * x, double * y, double * z, double * r, int number_of_bins, double bin_width, double rscale, double mass)
{
  string s;
  if(type==1){s= string("actual/dark_matter_density_"+extension+".dat");}
  else if(type==0){s= string("actual/light_matter_density_"+extension+".dat");}
//   else if(type==2){s= string("actual/dark_matter_vel_density.dat");}
//   else if(type==3){s= string("actual/light_matter_vel_density.dat");}

  for(int i=0;i<N;i++)
  {r[i]= sqrt( x[i]*x[i] +y[i]*y[i] + z[i]*z[i] );}
  
//   double density[N];
//   double pi=4*atan(1);
//   double coeff= 3.0*mass/(4*pi*pow(rscale, 3));
  
  ofstream dens;
  dens.open(s);
  for(int i=0;i<N;i++)
  {
//     density[i]=r[i]*r[i]* coeff*pow( (1.0 + r[i]*r[i]/(rscale*rscale)), -2.5);
    dens<<r[i]<<endl;
  }
//   dens.close();
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
        phi_l[i] = atan( yl[i] / xl[i] );
        
        theta[j] = theta_l[i];
        phi[j] = phi_l[i];
        j++;
    }
    
    for(int i = 0; i < Nl; i++)
    {
        rd[i] = sqrt( sqr(xd[i]) + sqr(yd[i]) + sqr(zd[i]) );
        theta_d[i] = acos( zd[i] / rd[i]);
        phi_d[i] = atan( yd[i] / xd[i] );
        
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



void vel_dis(int type, string extension, int N, double * vx,double * vy, double * vz, double * v, double * r,double number_of_bins, double bin_width, double rscale, double mass)
{

  string s;
  if(type==3){s= string("actual/light_matter_velocity_dist_"+extension+".dat");}
  else if(type==2){s= string("actual/dark_matter_velocity_dist_"+extension+".dat");}
  
  for(int i=0;i<N;i++)
  {
    v[i]= sqrt( vx[i]*vx[i] +vy[i]*vy[i] + vz[i]*vz[i] );
  }
  
  ofstream vel;
  vel.open(s);
  for(int i=0;i<N;i++)
  {
    vel<<r[i]<<"\t"<<v[i]<<endl;
  }
  vel.close();
  binner(number_of_bins, bin_width, v, N, type, extension);
  
}


int main (int argc, char * const argv[])
{
  /*taking in command line data. should be the same parameters used to calculate the simulation*/
   string simtime= argv[1];
   double backtime  = atof(argv[2]);
   double rscale_l  = atof(argv[3]);
   double light_r_ratio = atof(argv[4]);
   double dwarfmass = atof(argv[5]);
   double light_mass_ratio = atof(argv[6]);

   string extension= simtime+"gy";
   /*changes the parameters to usable info*/
   double massl= dwarfmass * light_mass_ratio;
   double massd= dwarfmass - (dwarfmass * light_mass_ratio);
   double mass_per_particle_dark = massd/ (0.5* 20000);
   double mass_per_particle_light = massl/ (0.5* 20000);
   double rscale_d= rscale_l/light_r_ratio;
   
  
//    printf("rad_light= %f \t rad_dark=%f \n mass_light=%f \t mass_dark=%f\n", rscale_l, rscale_d, massl, massd);
  
  /*paramters for binning routine*/
  int number_of_bins=1000;
  double bin_width=.10;
  
  /*these are markers for the type of data being sent into functions*/
  int d=1;//dark matter
  int l=0;//light matter
  int vd=2;//vel
  int vl=3;//vel
  int Nd= get_size(d, extension);//getting the size of the dark matter data
  int Nl= get_size(l, extension);//getting the size of the light matter data
  
  double rd[Nd], rl[Nl];//, r[Nd+Nl];  
  
  cout<<Nl<<"  "<< Nd<<endl;
  double dx[Nd], dy[Nd],dz[Nd],dvx[Nd], dvy[Nd],dvz[Nd];//vectors to store dark positions
  double lx[Nl], ly[Nl],lz[Nl],lvx[Nl], lvy[Nl],lvz[Nl];//vectors to store light positions
  double dv[Nd];//this is a vector to store the velocity distribution
  double lv[Nl];//this is a vector to store the velocity distribution
  
    /*getting the positional and velocity data*/
  get_data(Nd, dx, dy, dz, dvx, dvy, dvz, d, extension);  
  get_data(Nl, lx, ly, lz, lvx, lvy, lvz, l, extension);
    
  /*getting the radius value and binning*/
  radial_distribution(d, extension, Nd, dx, dy, dz, rd, number_of_bins, bin_width, rscale_d, massd);
  radial_distribution(l, extension, Nl, lx, ly, lz, rl, number_of_bins, bin_width, rscale_l, massl);
  
  single_density_theory( massl,  rscale_l,  massd,  rscale_d,  bin_width, mass_per_particle_dark,mass_per_particle_light );
  angles(extension, Nl, Nd, lx, ly, lz, dx, dy, dz, number_of_bins, bin_width );
  angle_theory(bin_width, mass_per_particle_dark, mass_per_particle_light);
}