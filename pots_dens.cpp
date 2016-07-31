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
#include "pots_dens.h"
#include "structs.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                             PLUMMER                                                                                   */
double plummer_den(double r, struct component & model)
{
    
    double rscale = model.rscale;
    double mass   = model.mass;
    
//     double pi = 4.0 * atan(1.0);
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
 double  nfw_den(double r, struct component & model)                                                                      //
{                                                                                                                        //
    double rscale = model.rscale;
    double mass   = model.mass;                                                                             //
    return (1.0 / (4.0 * pi)) * (mass * rscale / r) * (1.0 / sqr(1.0 + r / rscale));                                   //
}                                                                                                                        //
                                                                                                                         //
 double nfw_pot(double r, struct component & model)                                                                        //
{                                                                                                                        //
    double rscale = model.rscale;
    double mass   = model.mass;                                                                             //
    return (mass / r) * log(1.0 + r / rscale);                                                                        //
}                                                                                                                        //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                             GENERAL HERNQUIST                                                                         */
double gen_hern_den(double r, struct component & model)                                                                     //
{                                                                                                                        //
    double rscale = model.rscale;
    double mass   = model.mass;                                                                             //
    return inv(2.0 * pi) * mass * rscale / ( r * cube(r + rscale));                                                    //
}                                                                                                                        //
                                                                                                                         //
double gen_hern_pot(double r, struct component & model)                                                                    //
{                                                                                                                        //
    double rscale = model.rscale;
    double mass   = model.mass;                                                                             //
    return mass / (r + rscale);                                                                                          //
}                                                  

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


double get_density( double r, struct component & model)
{
    const int plummer = 1;
    const int nfw = 2;
    const int gen_hern = 3;
    const int einasto = 4;
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
    const int plummer = 1;
    const int nfw = 2;
    const int gen_hern = 3;
    const int einasto = 4;
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


