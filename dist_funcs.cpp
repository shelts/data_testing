#include "pots_dens.h"
#include "structs.h"

double plummer_distribution(double v, double r, struct component & light, struct component & dark)
{
    
    double mass = light.mass + dark.mass;
    double rscale = light.rscale; //it doesn't matter which since they should be the  same
    double coeff = 24.0 * sqrt(2.0) * inv( 7.0 * cube(pi) );
    
    double light_comp = get_potential(r, light);
    double dark_comp  = get_potential(r, dark);
    double potential =  (light_comp + dark_comp);
    
    double energy = -potential - 0.5 * sqr(v) ;
    
    double f = v * v * coeff * inv( fourth(mass) ) * sqr(rscale) * seventhhalfs(fabs(energy));
    
    return f;
    
}



double dist_func(double v, double r, struct component & light, struct component & dark)
{
    const int plummer = 1;
    const int nfw = 2;
    const int gen_hern = 3;
    const int einasto = 4;
    double dist_temp;
    
    switch(light.type)
    {
        case plummer:
            dist_temp = plummer_distribution(v, r, light, dark);
            break;
//         case nfw:
//             dist_temp = nfw_distribution(r, model);
//             break;
//         case gen_hern:
//             dist_temp = gen_hern_distribution(r, model);
//             break;
        default:
            printf("unknown model\n");
    }
    return dist_temp;
}