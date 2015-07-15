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

#define sqr(x) ( x * x )
#define sqrdel(x1, x2) sqr( (x1 - x2 ))

/*
 * This code calculates the viral ratio for the entire system as a whole
 */

  struct bodies
  {
    double x;
    double y;
    double z;
    double vx, vy, vz;
    double mass;
    int type;
  };

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


void get_data(int Nd,int Nl,struct bodies * b, string extension,
              double masspd, double masspl, int type_dark, int type_light)
{
  
    string s;
    double datax,datay,dataz,datavx,datavy,datavz;
    int i =0;
    int N = Nd + Nl;
    s = string("raw_data/dark_matter_"+extension+".dat");
    ifstream data;
    data.open (s);
    while(data>>datax>>datay>>dataz>>datavx>>datavy>>datavz)
    {
        b[i].x    = datax;
        b[i].y    = datay;
        b[i].z    = dataz;
        b[i].vx   = datavx;
        b[i].vy   = datavy;
        b[i].vz   = datavz;
        b[i].mass = masspd;
        b[i].type = type_dark;
        i++;
    }
    data.close();

    s = string("raw_data/light_matter_"+extension+".dat");
    ifstream data2;
    data2.open (s);
    while(data2>>datax>>datay>>dataz>>datavx>>datavy>>datavz)
    {
        b[i].x    = datax;
        b[i].y    = datay;
        b[i].z    = dataz;
        b[i].vx   = datavx;
        b[i].vy   = datavy;
        b[i].vz   = datavz;
        b[i].mass = masspl;
        b[i].type = type_light;
        i++;
    }
    data2.close();
  
  }
  
double mass_enc(double r, double rscale, double mass)
{
    double rcube = r * r * r;
    double mass_enclosed= mass * rcube * pow( (r * r + rscale * rscale), -1.5);

    return mass_enclosed;
  
}
  
void vel_dis(int N, struct bodies * b, string extension)
{
    double vx, vy, vz,v;
    double x, y, z, r;
    string s ="./test_output/vel_dis_"+extension+".txt";

    ofstream vels;
    vels.open(s);
    for(int i = 0; i < N; i++)
    {
        vx = b[i].vx;
        vy = b[i].vy;
        vz = b[i].vz;
        v  = sqrt( sqr(vx) + sqr(vy) + sqr(vz) );
        x  = b[i].x;
        y  = b[i].y;
        z  = b[i].z;
        r  = sqrt( sqr(x) + sqr(y) + sqr(z));
        vels<<v<<"\t"<<r<<endl;

    }
    vels.close();
}
  
double kinetic(int N, struct bodies * b)
{
    string s;
    //   if(type==1){s= string("energy/kinetic_e_light_"+extension+".dat");}
    //   else {s= string("energy/kinetic_e_dark_"+extension+".dat");}

    double ke = 0.0;
    double vx, vy, vz;
    for(int i = 0; i < N; i++)
    {
        vx = b[i].vx;
        vy = b[i].vy;
        vz = b[i].vz;

        ke += 0.5 * b[i].mass * ( sqr(vx) + sqr(vy) + sqr(vz) );
    }
    return ke;
}


double potential_energy(int Nl, int Nd, struct bodies * b, string extension)
{
    string s;
    int  N = Nd + Nl;
    double pot = 0.0;
    double rad_diff = 0.0;
    double x1, y1, z1;
    double x2, y2, z2;
    double mass1, mass2;
    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        { 
            x1 = b[i].x;
            x2 = b[j].x;
            
            y1 = b[i].y;
            y2 = b[j].y;
            
            z1 = b[i].z;
            z2 = b[j].z;
            
            mass1 = b[i].mass;
            mass2 = b[j].mass;
            
            
            rad_diff = sqrt( sqrdel(x1,x2) + sqrdel(y1, y2) + sqrdel(z1, z2) );
            pot += -mass1 * mass2 / (rad_diff);
        
        }
    }

    return pot;
}

double potential_func( struct bodies * b, double * args, int N)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    
    double pot = 0.0;
    double x, y, z, r, mass;
    double mass_light, mass_dark;
    for(int i = 0; i < N; i++)
    {
        x = b[i].x;
        y = b[i].y;
        z = b[i].z;
        r = sqrt( sqr(x) + sqr(y) + sqr(z));
        mass = b[i].mass;
        mass_light = mass_l;
        mass_dark = mass_d;
        pot += -mass * (mass_light/sqrt(sqr(r) + sqr(rscale_l)) +  mass_dark/sqrt(sqr(r) + sqr(rscale_d)) );
    }
    return pot/2;
}


int main (int argc, char * const argv[])
{
  /*taking in command line data. should be the same parameters used to calculate the simulation*/
    string simtime = argv[1];
    double backtime  = atof(argv[2]);
    double rscale_d  = atof(argv[3]);
    double light_r_ratio = atof(argv[4]);
    double dwarfmass = atof(argv[5]);
    double light_mass_ratio = atof(argv[6]);
    double diff_masses=atof(argv[7]);

    string extension = simtime+"gy";
    /*changes the parameters to usable info*/
    double massl = dwarfmass - (dwarfmass * light_mass_ratio);
    double massd = dwarfmass * light_mass_ratio;  
    double rscale_l = rscale_d / light_r_ratio;
    
    double args[4]  = {rscale_l, rscale_d, massl, massd};
    /*these are markers for the type of data being sent into functions*/
    int d = 1;//dark matter
    int l = 0;//light matter

    int Nl = get_size(0, extension);//getting the size of the dark matter data
    int Nd = get_size(1, extension);//getting the size of the light matter data

    int N = Nd + Nl;
    bodies b[N];
    double mass_per_light_particle;
    double mass_per_dark_particle;

    if(diff_masses == 1)
    {
        mass_per_light_particle = massl / (Nl);
        mass_per_dark_particle = massd / (Nd);
        cout<<mass_per_dark_particle<<"\t"<<mass_per_light_particle<<endl;
    }
    else if(diff_masses == 0)
    {
        cout<<"hello"<<endl;
        mass_per_light_particle = (massl + massd) / (N);
        mass_per_dark_particle = (massl + massd) / (N);
        cout<<mass_per_dark_particle<<"\t"<<mass_per_light_particle<<endl;
    }

    //   cout<<Nl<<"  "<< Nd<<endl;
    double ke;
    double pot_func, pot_pp;

    get_data(Nd, Nl, b, extension, mass_per_dark_particle, mass_per_light_particle, d, l);

    ke = kinetic(N,b);
    pot_func = potential_func(b, args, N);
    pot_pp = potential_energy(Nl, Nd, b, extension);

    double ratio_func = fabs( 2.0 * ke / pot_func);
    double ratio_pp = fabs( 2.0 * ke / pot_pp);
    double rat = pot_pp / pot_func;
    FILE * file;
    file = fopen("./test_output/virial_output.txt", "a");
    //   printf("ke \t pot \t ratio \t time\n");
    //   fprintf(file, "%f \t %f \t %f \t %f \t%f\t %f \n", ke, pot,pot2, ratio,ratio2, atof(argv[1]));

    fprintf(file, "%f  %f\t %f  %f \t ratio: %f \t %f \n", ratio_func, pot_func, ratio_pp, pot_pp, rat, atof(argv[1]));
    fclose(file);

    vel_dis(N, b, extension);

  
}