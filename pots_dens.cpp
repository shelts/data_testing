/* Copyright (c) 2016 Siddhartha Shelton */
#include "pots_dens.h"
#include "structs.h"
#include "utility_functions.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                             PLUMMER                                                                                   */
double plummer_den(double r, struct component & model)
{
    
    double rscale = model.rscale;
    double mass   = model.mass;
    
    double rscale_cube = cube(rscale); 

    double density_result = (mass / rscale_cube) * minusfivehalves( (1.0 + sqr(r)/sqr(rscale) ) );
    double coeff = 3.0 / (4.0 * pi);

    density_result *= coeff;
    return density_result;
}

double plummer_pot(double r, struct component & model)
{
    double rscale = model.rscale;
    double mass   = model.mass;
    double potential_result  = - mass / sqrt( sqr(r) + sqr(rscale) );
    return (potential_result);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                            NFW                                                                                        */
 
double get_p0(struct component & model)
{
    double mass = model.mass; 
    double rscale = model.rscale;

    //as defined in Binney and Tremaine 2nd ed:
    double r200 = cbrt(mass / (vol_pcrit));//vol_pcrit = 200.0 * pcrit * PI_4_3           //
    double c = r200 / rscale; //halo concentration                                                                       //
    double term = log(1.0 + c) - c / (1.0 + c);                                                                          //
    double p0 = 200.0 * cube(c) * pcrit / (3.0 * term); //rho_0 as defined in Navarro et. al. 1997                       //
    model.r200 = r200;
    model.p0 = p0;
//     printf("%0.15f\n", p0);
}

double nfw_den(double r, struct component & model)                                                                       //
{                                                                                                                        //
    double rscale = model.rscale;                                                                                        //
    double mass   = model.mass;                                                                                          //
    double p0     = model.p0;
//     double p0 = get_p0(mass, rscale);
    
    double R = r / rscale;
    return p0 * inv(R) * inv(sqr(1.0 + R));                                                                              //
}                                                                                                                        //
                                                                                                                         //
 double nfw_pot(double r, struct component & model)                                                                      //
{                                                                                                                        //
    double rscale = model.rscale;                                                                                        //
    double mass   = model.mass;                                                                                          //
    double p0     = model.p0;
//     double p0 = get_p0(mass, rscale);    
    
    double R = r / rscale;
    
    return  - 4.0 * pi * sqr(rscale) * p0 * inv(R) * log(1.0 + R);                                                       //
}                                                                                                                        //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                             GENERAL HERNQUIST                                                                         */
double gen_hern_den(double r, struct component & model)                                                                  //
{                                                                                                                        //
    double rscale = model.rscale;                                                                                        //
    double mass   = model.mass;                                                                                          //
    return inv(2.0 * pi) * mass * rscale / ( r * cube(r + rscale));                                                      //
}                                                                                                                        //
                                                                                                                         //
double gen_hern_pot(double r, struct component & model)                                                                  //
{                                                                                                                        //
    double rscale = model.rscale;                                                                                        //
    double mass   = model.mass;                                                                                          //
    return - mass / (r + rscale);                                                                                        //
}                                                                                                                        //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


double get_density( double r, struct component & model)
{
    double den_temp;
    
    switch(model.type)
    {
        case plummer:
            den_temp = plummer_den(r, model);
            break;
        case nfw:
            den_temp = nfw_den(r, model);
            break;
        case gen_hern:
            den_temp = gen_hern_den(r, model);
            break;
        default:
            printf("unknown model\n");
    }
    return den_temp;
}


double get_potential( double r, struct component & model)
{
    double pot_temp;
    
    switch(model.type)
    {
        case plummer:
            pot_temp = plummer_pot(r, model);
            break;
        case nfw:
            pot_temp = nfw_pot(r, model);
            break;
        case gen_hern:
            pot_temp = gen_hern_pot(r, model);
            break;
        default:
            printf("unknown model\n");
    }
    return pot_temp;
}


