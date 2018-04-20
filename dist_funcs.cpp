/* Copyright (c) 2016 Siddhartha Shelton */

#include "pots_dens.h"
#include "structs.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                             PLUMMER                                                                                   */
double plummer_distribution(double v, struct position & pos, struct component & light, struct component & dark)
{
    double mass = light.mass + dark.mass;
    double rscale = light.rscale; //it doesn't matter which since they should be the  same
    double coeff = 24.0 * sqrt(2.0) * inv( 7.0 * cube(pi) );
    
    double light_comp = get_potential(pos, light);
    double dark_comp  = get_potential(pos, dark);
    double potential =  (light_comp + dark_comp);
    
    double energy = -potential - 0.5 * sqr(v) ;
    
    double f = v * v * coeff * inv( fifth(mass) ) * sqr(rscale) * seventhhalfs(fabs(energy));
    //there is an extra mass in the denom because this was derived with dist in terms of rho/m, not rho 
    //(see binney 2nd ed eq 4.46a and 4.48)
    return f;
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                             NFW                                                                                       */
/* WARNING: this is the distribution function for the plummer sphere. I had to put something because there is no analytic form    */ 
/* for the nfw                                                                                                           */

double nfw_distribution(double v, struct position & pos, struct component & light, struct component & dark)
{
    
    double mass = light.mass + dark.mass;
    double rscale = light.rscale; //it doesn't matter which since they should be the  same
    double coeff = 24.0 * sqrt(2.0) * inv( 7.0 * cube(pi) );
    
    double light_comp = get_potential(pos, light);
    double dark_comp  = get_potential(pos, dark);
    double potential =  (light_comp + dark_comp);
    
    double energy = -potential - 0.5 * sqr(v) ;
    
    double f = v * v * coeff * inv( fourth(mass) ) * sqr(rscale) * seventhhalfs(fabs(energy));
    
    return f;
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                             GENERAL HERNQUIST                                                                         */
double gen_hern_distribution(double v, struct position & pos, struct component & light, struct component & dark)
{
    double rscale = light.rscale;
    double mass = light.mass + dark.mass; 
    double light_comp = get_potential(pos, light);
    double dark_comp  = get_potential(pos, dark);
    double potential =  (light_comp + dark_comp);
    
    double eps = (-potential - 0.5 * sqr(v)) * rscale / mass ;
    
    double coeff1 = inv(sqrt(2.0) * cube(2.0 * pi) * threehalves(mass * rscale));
    double coeff2 = sqrt(eps) / sqr(1.0 - eps);
    double coeff3_pt1 = (1.0 - 2.0 * eps) * (8.0 * sqr(eps) - 8.0 * eps - 3.0);
    double coeff3_pt2 = 3.0 * asin(sqrt(eps)) / sqrt(eps * (1.0 - eps));
    double f = sqr(v) * coeff1 * coeff2 * (coeff3_pt1 + coeff3_pt2);
    return f;
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double dist_func(double v, struct position & pos, struct component & light, struct component & dark)
{
    double dist_temp;
    /*in order for this to work it has to both be one type*/ 
    switch(light.type)
    {
        case plummer:
            dist_temp = plummer_distribution(v, pos, light, dark);
            break;
        case nfw:
            dist_temp = nfw_distribution(v, pos, light, dark);
            break;
        case gen_hern:
            dist_temp = gen_hern_distribution(v, pos, light, dark);
            break;
        default:
            printf("unknown model\n");
    }
    return dist_temp;
}