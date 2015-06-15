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

double potential( double r, double mass, double rscale)
{
  double sqrsq=rscale*rscale;
  double sqr=r*r;
  double potential_result= -1.0*(mass/pow((sqr + sqrsq),2));
  
  return (-1.0*potential_result);
}

double density(double rscale, double mass, double r)
{
  double pi=4.0*atan(1.0);
  double rscalecube = (rscale)*(rscale)*(rscale); 
  double sqr=r*r;
  double sqrrcube=rscalecube*rscalecube;
  double density_result= (3.0/(4.0*pi))*(mass/rscalecube *pow(1+ sqr/sqrrcube, -2.5));
  
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
    if(type==1){s= string("./raw_data/light_matter_"+extension+".dat");}
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
  if(type==1){s= string("raw_data/light_matter_"+extension+".dat");}
  else {s= string("raw_data/dark_matter_"+extension+".dat");}
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

double fun(double r, double mass, double rscale)
{
  double function_val=r*r*density(rscale, mass, r);
  return function_val;
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
  if(type==0){s= string("binned_data/dark_matter_bins_"+extension+".dat");}
  else if(type==1){s= string("binned_data/light_matter_bins_"+extension+".dat");}
  else if(type==2){s= string("binned_data/dark_matter_vel_bins_"+extension+".dat");}
  else if(type==3){s= string("binned_data/light_matter_vel_bins_"+extension+".dat");}
  
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

  double binrange=0;
  double normed;
  for(int i=0; i!=binN;i++)
  {
      binrange=binrange+binwidth;
      normed=(bins[i])/double(N);
      bin<<normed<<"\t"<<binrange<<endl;
// 	bin<<bins[i]<<"\t"<<binrange<<endl;
  }

  bin.close();
}

/*This uses the data and plots the radial distribution*/
void radial_distribution(int type, string extension, int N, double * x, double * y, double * z, double * r, int number_of_bins, double bin_width, double rscale, double mass)
{
  string s;
  if(type==0){s= string("actual/dark_matter_density_"+extension+".dat");}
  else if(type==1){s= string("actual/light_matter_density_"+extension+".dat");}
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
   double rscale_d= rscale_l/light_r_ratio;
//    printf("rad_light= %f \t rad_dark=%f \n mass_light=%f \t mass_dark=%f\n", rscale_l, rscale_d, massl, massd);
  
  /*paramters for binning routine*/
  int number_of_bins=100;
  double bin_width=1;
  
  /*these are markers for the type of data being sent into functions*/
  int d=0;//dark matter
  int l=1;//light matter
  int vd=2;//vel
  int vl=3;//vel
  int Nd= get_size(0, extension);//getting the size of the dark matter data
  int Nl= get_size(1, extension);//getting the size of the light matter data
  
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
}