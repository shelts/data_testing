#include "pots_dens.h"
#include "structs.h"
#include "utility_functions.h"
using namespace std;


/*
 * This code calculates the viral ratio for the entire system as a whole
 */

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
    string s ="./test_output/vel_dis_" + extension + ".txt";

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
  
double kinetic(int N, struct bodies * b, double * cmv)
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

        ke += 0.5 * b[i].mass * ( sqrdel(cmv[0], vx) + sqrdel(cmv[1], vy) + sqrdel(cmv[2], vz) );
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

double potential_func( struct bodies * b, int N, double * cm, struct component & light, struct component & dark)
{
    double pot = 0.0;
    double x, y, z, r, mass;
    double light_comp, dark_comp;
    
    for(int i = 0; i < N; i++)
    {
        x = b[i].x;
        y = b[i].y;
        z = b[i].z;
        r = sqrt( sqrdel(cm[0], x) + sqrdel(cm[1], y) + sqrdel(cm[2], z));
        mass = b[i].mass;

        light_comp = get_potential(r, light);
        dark_comp  = get_potential(r, dark);
        
        pot += mass * (light_comp + dark_comp);
        
    }
    return pot / 2.0;
}


int main (int argc, char * const argv[])
{
    string simtime                 = argv[1];
    double rscale_l                = atof(argv[2]);
    double rscale_d                = atof(argv[3]);
    double mass_l                  = atof(argv[4]);
    double mass_d                  = atof(argv[5]);
    int model1                     = atof(argv[6]);
    int model2                     = atof(argv[7]);
    
    string extension = simtime + "gy";
    component light;
    component dark;
    
    light.type = model1;
    light.rscale = rscale_l;
    light.mass = mass_l;
    
    dark.type = model2;
    dark.rscale = rscale_d;
    dark.mass = mass_d;
    
    int l = 0;
    int d = 1;
    int Nl = get_size(0, extension);//getting the size of the dark matter data
    int Nd = get_size(1, extension);//getting the size of the light matter data

    int N = Nd + Nl;
    bodies b[N];
    double cm[3] = {0.0, 0.0, 0.0};
    double cmv[3] = {0.0, 0.0, 0.0};
    
    double mass = mass_l + mass_d;

    double ke;
    double pot_func, pot_pp;

    get_data(Nd, Nl, b, extension);
    
    com(b, N, cm, cmv, mass);
    
    printf("calculating virial ratio");
    /*calculates kinetic energy relative to centor of mass*/
    ke = kinetic(N, b, cmv);
    printf("..");
    /*calculates potential energy relative to centor of mass*/
    pot_func = potential_func(b, N, cm, light, dark);
    printf("..");
    /*particle particle potential energy*/
    pot_pp = potential_energy(Nl, Nd, b, extension);
    printf("done.\n");

    double ratio_func = fabs( 2.0 * ke / pot_func);
    double ratio_pp = fabs( 2.0 * ke / pot_pp);
    double rat = pot_pp / pot_func;
    FILE * file;
    file = fopen("./test_output/virial_output.txt", "a");
    //   printf("ke \t pot \t ratio \t time\n");
    //   fprintf(file, "%f \t %f \t %f \t %f \t%f\t %f \n", ke, pot,pot2, ratio,ratio2, atof(argv[1]));
    fprintf(file, "%f \t %f \t ratio: %f \t %s \n", ratio_func, ratio_pp, rat, (argv[1]));
    fclose(file);

//     vel_dis(N, b, extension);

   
}