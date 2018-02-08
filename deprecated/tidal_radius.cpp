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
#define pi (4.0 * atan(1.0))

/*   Potentials     */
double spherical_pot(double r, double * args)
{
    double M = 1.52954402e5;
    double d = 0.7;
    double pot = -M / (r + d);
    return pot;
}

double log_halo_pot(double r, double * args)
{
    double v0 = 73.0;
    double a = 12.0;
    double pot = -0.5 * sqr(v0) * log(1.0 + sqr(r) / sqr(a) );
    return pot;
}


double miyamotoNagai_pot(double r, double * args)
{
    double M = 4.45865888e5;
    double a = 6.5;
    double b = 0.26;
    double theta = pi / 2.0;
    double R = r * sin(theta);
    double Z = r * cos(theta);
    
    double denom = sqrt( sqr(R) + sqr(a + sqrt( sqr(Z) + sqr(b) ) ) );
    double pot = -M / denom ;
    return pot;
}

double plummer_pot(double r, double * args)
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
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
/*    Densities     */
double spherical_den(double r, double * args)
{
    double M = 1.52954402e5;
    double d = 0.7;
    double denom = ( r * cube(r + d) );
    double den = inv(2.0 * pi) * M * d / denom;
    return den;
}    

double log_halo_den(double r, double * args)
{
    double v0 = 73.0;
    double a = 12.0;
    double R = sqr(r) / sqr(a);
    double num = 3.0 + R;
    double denom = (sqr( 1.0 + R));
    double den = sqr(v0) * inv(4.0 * pi * sqr(a)) * num / denom; 
    return den;
}

double miyamotoNagai_den(double r, double * args)
{
    double M = 4.45865888e5;
    double a = 6.5;
    double b = 0.26;
    double theta = pi / 2.0; //this makes it a 2D disk
    double R = r * sin(theta);
    double Z = r * cos(theta);
    double coeff = sqr(b) * M * inv(4.0 * pi);
    double g = sqrt( sqr(Z) + sqr(b) );
    double d =  (a + g);
    double d2 =  (a + 3.0 * g);
    
    double num = a * sqr(R) + d2 * sqr(d);
    double denom = fivehalves(sqr(R) + sqr(d)) * cube(g);
    
    double den = coeff * num / denom;
    return den;
}

double plummer_den(double r, double * args)
{
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
//     printf("%f %f %f %f\n", rscale_l, rscale_d, mass_l, mass_d);
    double rscale_l_cube = cube(rscale_l); 
    double rscale_d_cube = cube(rscale_d); 

    double density_light_comp = (mass_l/rscale_l_cube) * minusfivehalves( (1.0 + sqr(r)/sqr(rscale_l) ) );
    double density_dark_comp  = (mass_d/rscale_d_cube) * minusfivehalves( (1.0 + sqr(r)/sqr(rscale_d) ) );
    double coeff = 3.0 / (4.0 * pi);

    double density_result = coeff * ( density_light_comp + density_dark_comp);
    return density_result;
}
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
/*   utility functions    */
//the guass quad takes a function as a parameter which itself takes a function as a parameter.
double gauss_quad(double (*Func)(double (*)(double, double *), double, double *), double (*func2)(double, double *), double * args, double lower, double upper )
{
    double Ng, hg, lowerg, upperg;
    double intv;
    double coef1, coef2;//parameters for gaussian quad
    double c1, c2, c3;
    double x1, x2, x3;
    double x1n, x2n, x3n;
    
    //this should be from infinity. But the dis func should be negligble here.
    double a = lower; 
    double b = upper;

    intv = 0;//initial value of integral
    Ng = 1000.0;//integral resolution
    hg = (b - a) / (Ng);

    
    lowerg = lower;
    upperg = lowerg + hg; 

    coef2 = (lowerg + upperg) / 2.0;//initializes the first coeff to change the function limits
    coef1 = (upperg - lowerg) / 2.0;//initializes the second coeff to change the function limits
    c1 = 5.0 / 9.0;
    c2 = 8.0 / 9.0;
    c3 = 5.0 / 9.0;
    x1 = -sqrt(3.0 / 5.0);
    x2 = 0.0;
    x3 = sqrt(3.0 / 5.0);
    x1n = (coef1 * x1 + coef2);
    x2n = (coef1 * x2 + coef2);
    x3n = (coef1 * x3 + coef2);
    int counter = 0;
    while (1)
    {
                //gauss quad
        intv = intv +  c1 * (*Func)((*func2), x1n, args) * coef1 +
                       c2 * (*Func)((*func2), x2n, args) * coef1 + 
                       c3 * (*Func)((*func2), x3n, args) * coef1;
                       
        lowerg = upperg;
        upperg = upperg + hg;
        coef2  = (lowerg + upperg) / 2.0;//initializes the first coeff to change the function limits
        coef1  = (upperg - lowerg) / 2.0;

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

double root_finder(double (*rootFunc)(double *, double), double * args, double funcValue, double lower, double upper)
{
    int N = 10;
    int numSteps = N;
    double interval;
    double values[numSteps + 1];
    /* Divide the function area up into bins in case there is more than one root */
    /*numSteps+1 because you want to include the upperbound in the interval*/
    
    
    for(int i = 0; i < numSteps + 1; i++)
    {
        interval = ((upper - lower) * (double)i) / (double)numSteps + lower;
        values[i] = (*rootFunc)(args, interval) - funcValue;
    }
    
    double midPoint = 0;
    double midVal = 0;
    int nsteps = 0;
    double curUpper = 0;
    double curLower = 0;
    int rootsFound = 0;
    int q = 0;
    
    /* Find the roots using bisection because it was easy to code and good enough for our purposes 
     * this will hope around the different intervals until it checks all of them. This way it does not 
     * favor any root.
     */
    for(int i = 0; i < numSteps; i++)
    {
        q = i;
        if((values[q] > 0 && values[q + 1] < 0) || (values[q] < 0 && values[q + 1] > 0))
        {
//             printf("sign change found...");
            if(values[q] < 0 && values[q + 1] > 0)
            {
                curLower = ((upper - lower) * (double)q) / (double)numSteps + lower;
                curUpper = ((upper - lower) * (double)(q + 1)) / (double)numSteps + lower;
            }
            else if(values[q] > 0 && values[q + 1] < 0)
            {
                curLower = ((upper - lower) * (double)(q + 1)) / (double)numSteps + lower;
                curUpper = ((upper - lower) * (double)q) / (double)numSteps + lower;
            }
            else
            {
                continue;
            }
            
            midVal = 1;
            nsteps = 0;
            while(fabs(midVal) > .01)
            {
                midPoint = (curLower + curUpper) / 2.0;
                midVal = (*rootFunc)(args, midPoint) - funcValue;
                
                if(midVal < 0.0)
                {
                    curLower = midPoint;
                }
                else
                {
                    curUpper = midPoint;
                }
                ++nsteps;
             
                if(nsteps > 1000)
                {
                    break;
                }
//                 printf("mid = %.20f \t nsteps = %i \t midval = %f curL = %f curU = %f\n", midPoint, nsteps, midVal, curLower, curUpper);
            }
            
//             if(nsteps < 10000)
//             {
//                 printf("This ran\n");
                ++rootsFound;
//             }
//             else
//             {
//                 printf("no this did\n");
//                 return midPoint = 0.0;
//             }
            
        }
        
        if(rootsFound != 0)
        {
            printf("nsteps = %i\n", nsteps);
            break;
        }
    }
//     mw_printf("rootsFound= %i\n", rootsFound);


    return midPoint;
}

//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
/*   calculation function  */
double rsqr_den(double (*func)(double, double *), double r, double * args)
{
    double val = sqr(r) * (*func)(r, args);
    return val;
}

/* cylindrical volume element */
double r_den(double (*func)(double, double *), double r, double * args)
{
    double val = (r) * (*func)(r, args);
    return val;
}

double calc_cutoff_radius_dwarf(double * args)
{
    /* this calculates the radius at which 95% of the mass is enclosed */
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double M_dwarf = mass_l + mass_d;
    double mass_dwarf;
    double r = 0.01;
    while(1)
    {
        mass_dwarf = 4.0 * pi * gauss_quad(rsqr_den, plummer_den, args, 0.0, r);
        
//         printf("%f \t %f \t %f\n", r, mass_dwarf, M_dwarf);
        if(mass_dwarf / M_dwarf > .75)
        {
            break;
        }
        else
        {
            r = r + 0.01;
        }
    }
    
    return r;
}

double mass_enc_galaxy(double * args, double r)
{
    /* this calculates the mass enclosed with some given r of the total galaxy potential */
    double mass_spherical = 0.0;
    double mass_log_halo = 0.0;
    double mass_mndisk = 0.0;
    double M_t;
    
    mass_spherical = 1.52954402e5; //4.0 * pi * gauss_quad(rsqr_den, spherical_den, args, 0.0, r);
    mass_log_halo  = 4.0 * pi * gauss_quad(rsqr_den, log_halo_den, args,  0.0, r);
    mass_mndisk    = 4.45865888e5; //2.0 * pi * gauss_quad(r_den, miyamotoNagai_den, args, 0.0, r);
//     printf("%f \t %f \t %f\n", mass_spherical, mass_log_halo, mass_mndisk);
    M_t = mass_spherical + mass_log_halo + mass_mndisk;
    
    return M_t;
}

double galaxy_pot(double * args, double r)
{
    double mn = miyamotoNagai_pot(r, args);
    double sph = spherical_pot(r, args);
    double log = log_halo_pot(r, args);
    double pot = mn + sph + log;
    return pot;
    
}
double mass_enc_dwarf(double * args, double r)
{
    double mass_dwarf = 4.0 * pi * gauss_quad(rsqr_den, plummer_den, args, 0.0, r);   
//     printf("mass = %f\n", mass_dwarf);
    return mass_dwarf;
}
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
/*   Tidal Radius   */
double tidal_radius_eq(double * args, double d)
{
    //d = x - r
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double r = args[4];
    double x = d + r;
    double galaxy_on_dwarf_center = mass_enc_galaxy(args, x) / sqr(x);
    double galaxy_on_star = mass_enc_galaxy(args, fabs(d)) / sqr(d);
    double dwarf_on_star = (mass_l + mass_d) / sqr(r);
    double force = galaxy_on_dwarf_center - galaxy_on_star + dwarf_on_star;
//     printf("mass = %f  r = %f\n", dwarf_on_star * sqr(r), r);
//     printf("%f\n", force);
    return force;
}

double tidal_radius_eq_pot(double * args, double d)
{
    //d = x - r
    double rscale_l = args[0];
    double rscale_d = args[1];
    double mass_l   = args[2];
    double mass_d   = args[3];
    double r = args[4];
    double x = d + r;
    double galaxy_on_dwarf_center = -galaxy_pot(args, x);
    double galaxy_on_star = -galaxy_pot(args, d);
    double dwarf_on_star = -plummer_pot(r, args);
    double pot = galaxy_on_dwarf_center - galaxy_on_star + dwarf_on_star;
    return pot;
    
}
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
/*   Plotting  */
void plot_density(double * args)
{
    double r = 0.01;
    double plum_den;
    double mn_den;
    double spher_den;
    double log_den;
    FILE * den;
    den = fopen("./theory/den.dat", "w");
    while(1)
    {
        plum_den = plummer_den(r, args);
        mn_den = miyamotoNagai_den(r, args);
        spher_den = spherical_den(r, args);
        log_den = log_halo_den(r, args);
        fprintf(den, "%f \t %f \t %f \t %f \t %f\n", r, plum_den, mn_den, spher_den, log_den);
        r += 0.01;
        
        if(r > 500.0){break;}
    }
    fclose(den);

    r = 0.01;
    FILE * pot;
    pot = fopen("./theory/pots.dat", "w");
    while(1)
    {
        plum_den = plummer_pot(r, args);
        mn_den = miyamotoNagai_pot(r, args);
        spher_den = spherical_pot(r, args);
        log_den = log_halo_pot(r, args);
        fprintf(pot, "%f \t %f \t %f \t %f \t %f\n", r, plum_den, mn_den, spher_den, log_den);
        r += 0.01;
        
        if(r > 500.0){break;}
    }
    fclose(pot);
}

void plot_rotation_curves(double * args)
{
    double r = 0.01;
    double vel_mn, vel_sph, vel_log, vel_sum;
    double mn_pot, sph_pot, log_pot;
    FILE * vels;
    vels = fopen("./theory/rotation.dat", "w");
    while(1)
    {
        mn_pot = miyamotoNagai_pot(r, args);
        sph_pot = spherical_pot(r, args);
        log_pot = log_halo_pot(r, args);
        vel_mn = sqrt(fabs(2.0 * mn_pot));
        vel_sph = sqrt(fabs(2.0 * sph_pot));
        vel_log = sqrt(fabs(2.0 * log_pot));
        vel_sum = sqrt(fabs(2.0 * (mn_pot + sph_pot + log_pot)));
        fprintf(vels, "%f \t %f \t %f \t %f \t %f\n", r, vel_mn, vel_sph, vel_log, vel_sum);

        if(r > 500.0)
        { 
            break;
        }
        else
        {
            r += 0.01;
        }
    }
}

void plot_force(double * args, double r)
{
    double x = 1000;
    double force = 0.0;
    FILE * f;
    f = fopen("./theory/force.dat", "w");
    while(1)
    {
        force = tidal_radius_eq(args, x);
        fprintf(f, "%f \t %f\n", x, force);
        x -= .1;
        
        if(x < 4.0){break;}
    }
    fclose(f);
}

//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
/*    testing    */
double test_func(double x, double * args)
{
    double t = sin(x) * sqr(x);
    return t;
}

double test_profile(double (*func)(double, double *), double x, double * args)
{
    double t = exp(x) * (*func)(x, args);
    return t;
}

double test(double * args)
{
    double t = gauss_quad(test_profile, test_func, args, 0.0, 3.0);
    return t;
}

double test_func2(double * args, double x)
{
    double t = exp(x) * sin(x) * sqr(x); 
    return t;
}
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
/*   main */
int main (int argc, char * const argv[])
{
    double rscale_l                = atof(argv[1]);
    double rscale_d                = atof(argv[2]);
    double mass_l                  = atof(argv[3]);
    double mass_d                  = atof(argv[4]);
    
    double args[4] = {rscale_l, rscale_d, mass_l, mass_d};
    
    /* quick test */
//     double get_x = test(args);
//     printf("test x = %f \t answer = 51.607\n", get_x);
//     double root_test = root_finder(test_func2, args, 2.0, 0.0, 4.0);
//     printf("root test x = %f \t answer = 0.9637 , 3.1327\n", root_test);
//     
    /* get the dwarf cutoff radius */
    double r_d = calc_cutoff_radius_dwarf(args);
    printf("rscale_l = %f \t rscale_d = %f\n", rscale_l, rscale_d);
    printf("r_dwarf = %f\n", r_d);
    double eq_args[5] = {rscale_l, rscale_d, mass_l, mass_d, r_d};
    
//     plot_density(args);
//     plot_rotation_curves(args);
//     plot_force(eq_args, r_d);
   
    
    double esc = sqrt( fabs(2.0 * (spherical_pot(25.0, args) + log_halo_pot(25.0, args) + miyamotoNagai_pot(25.0, args))));
    printf("esc = %f\n", esc);
    printf("search for tidal r...");
    double tidal_r = root_finder(tidal_radius_eq, eq_args, 0.0, 1, 500.0);
    double tidal_r_pot = root_finder(tidal_radius_eq_pot, eq_args, 0.0, 1, 500.0);
    
    /* assuming point potentials */
    //the 5.3e6 mass is the mass that the log halo seems to converge to.
//     double Mg = (4.45865888e5 + 1.52954402e5 + 5.3e6);
//     double Ms = 30.0;
//     double tidal_r2 = r_d * pow(( 3.0 * Mg / Ms), 1.0 / 3.0);
    printf("done. \ntidal radius = %f \t %f\n", tidal_r, tidal_r_pot); //reports the center to center distance
    
    
}