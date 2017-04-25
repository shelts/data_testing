/* Copyright (c) 2016 Siddhartha Shelton */
#include "pots_dens.h"
#include "structs.h"
#include "utility_functions.h"


/*
 * This code calculates the viral ratio for the entire system as a whole
 */

double kinetic(int N, struct bodies * b)
{
    /* sums over the particles kinetic energy */
    double ke = 0.0;
    double vx, vy, vz;
    for(int i = 0; i < N; i++)
    {
        vx = b[i].vel.vx;
        vy = b[i].vel.vy;
        vz = b[i].vel.vz;

        ke += 0.5 * b[i].mass * (sqr(vx) + sqr(vy) + sqr(vz));
    }
    return ke;
}


double potential_energy(int Nl, int Nd, struct bodies * b, string extension)
{
    /*
     * this calculates the potential energy of the system using the particle
     * particle sum of classical potential energy
     */
    int  N = Nd + Nl;
    double pot = 0.0;
    double rad_diff = 0.0;
    double x1, y1, z1;
    double x2, y2, z2;
    double mass1, mass2;
    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        { 
            x1 = b[i].pos.x;
            x2 = b[j].pos.x;
            
            y1 = b[i].pos.y;
            y2 = b[j].pos.y;
            
            z1 = b[i].pos.z;
            z2 = b[j].pos.z;
            
            mass1 = b[i].mass;
            mass2 = b[j].mass;
            
            /* this sums over the particles, without particle self interaction */
            rad_diff = sqrt( sqrdif(x1, x2) + sqrdif(y1, y2) + sqrdif(z1, z2) );
            pot += -mass1 * mass2 / (rad_diff);
        
        }
    }

    return pot;
}

double potential_func( struct bodies * b, int N, struct component & light, struct component & dark)
{
    /*
     * This calculates the potential energy using the theoretical potential function for that model
     */
    double pot = 0.0;
    double mass;
    double light_comp, dark_comp;
    
    for(int i = 0; i < N; i++)
    {
        mass = b[i].mass;

        light_comp = get_potential(b[i].pos, light);
        dark_comp  = get_potential(b[i].pos, dark);
        
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
    
    init_comps(light, dark, rscale_l, rscale_d, mass_l, mass_d, model1, model2);
    printf("p0l,p0d :  (%0.15f , %0.15f)\n", light.p0, dark.p0);
    printf("r200l,r200d: (%0.15f\t  %0.15f)\n", light.r200, dark.r200);
    
    check_mass(light);
    check_mass(dark);
    printf("ml,md :  (%0.15f , %0.15f)\n", light.mass, dark.mass);
    mass_l = light.mass;
    mass_d = dark.mass;
    
    int Nl = get_size(0, extension);//getting the size of the dark matter data
    int Nd = get_size(1, extension);//getting the size of the light matter data

    int N = Nd + Nl;
    bodies b[N];
    double cm[3] = {0.0, 0.0, 0.0};
    double cmv[3] = {0.0, 0.0, 0.0};
    
    double mass = mass_l + mass_d;

    double ke;
    double pot_func, pot_pp;
    double test = in_quad(3, 4, 5);
    get_data(Nd, Nl, b, extension);
    
    com(b, N, cm, cmv, mass);
    com_correction(cm, cmv, b, N);
    
    
    printf("calculating virial ratio\n");
    
    /*calculates kinetic energy relative to centor of mass*/
    ke = kinetic(N, b);
    
    
    /*calculates potential energy relative to centor of mass*/
    pot_func = potential_func(b, N, light, dark);
    
    
    /*particle particle potential energy*/
    
    pot_pp = potential_energy(Nl, Nd, b, extension);
    
    printf("done.\n");

    double ratio_func = fabs( 2.0 * ke / pot_func);
    double ratio_pp = fabs( 2.0 * ke / pot_pp);
    double rat = pot_pp / pot_func;
    FILE * file;
    file = fopen("./test_output/virial_output.txt", "a");


    fprintf(file, "%f \t %f \t ratio: %f \t %s \n", ratio_func, ratio_pp, rat, (argv[1]));
    printf("%f \t %f \t ratio: %f \t %s \n", ratio_func, ratio_pp, rat, (argv[1]));
    fclose(file);
}