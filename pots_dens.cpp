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
#define in_quad(x,y,z) (sqrt( x * x + y * y + z * z))


double plummer_den(double r, struct dwarf_component * model)
{
    
    double rscale = model.rscale;
    double mass   = model.mass;
    
    double pi = 4.0 * atan(1.0);
    double rscale_cube = cube(rscale); 

    double density_result = (mass / rscale_cube) * minusfivehalves( (1.0 + sqr(r)/sqr(rscale) ) );
    double coeff = 3.0 / (4.0 * pi);

    density_result *= coeff;
    return density_result;
}


double plummer_pot(double r, struct dwarf_component * model)
{
    double rscale = model.rscale;
    double mass   = model.mass;
    double potential_result  = - mass / sqrt( sqr(r) + sqr(rscale) );
    return (potential_result);
}



double get_density( double r, const struct dwarf_component model)
{
    const int plummer = 1;
    double den_temp;
    switch(model.type)
    {
        case plummer:
            den_temp = plummer_den(r, model);
            break;
    }
    return den_temp;
}


double get_potential( double r, const struct dwarf_component model)
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
            
            
    }
    return pot_temp;
}


