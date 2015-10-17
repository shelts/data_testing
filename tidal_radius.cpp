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
double spherical_pot(double r)
{
    double M = 1.52954402e5;
    double d = 0.7;
    double pot = M / (r + d);
    return pot;
}

double log_halo_pot(double r)
{
    double v0 = 73.0;
    double a = 12.0;
    double pot = 0.5 * sqr(v0) * log(1.0 + sqr(r) / sqr(a) );
    return pot;
}


double miyamotoNagai_pot(double r, double theta)
{
    double M = 4.45865888e5;
    double a = 6.5;
    double b = 0.26;
    double R = r * sin(theta);
    double Z = r * cos(theta);
    
    double demon = sqrt( sqr(R) + sqr(a + sqrt( sqr(Z) + sqr(b) ) ) );
    double pot = M / denom ;
    return pot;
}

/*   Densities */
double spherical_den(double r)
{
    double M = 1.52954402e5;
    double d = 0.7;
    double denom = inv( r * cube(r + d) );
    double den = inv(2.0 * pi) * M * d * denom;
    return den;
}

double log_halo_den(double r)
{
    double v0 = 73.0;
    double a = 12.0;
    double R = sqr(r) / sqr(a);
    double num = 3.0 - R;
    double denom = inv(sqr( 1.0 - R));
    double den = sqr(v0) * inv(4.0 * pi * sqr(a)) * num * denom; 
    return den;
}

double miyamotoNagai_den(double r, double theta)
{
    double M = 4.45865888e5;
    double a = 6.5;
    double b = 0.26;
    double R = r * sin(theta);
    double Z = r * cos(theta);
    double coeff = sqr(b) * M * inv(4.0 * pi);
    double g = sqrt( sqr(z) + sqr(b) );
    double d =  (a + g);
    double d2 =  (a + 3.0 * g);
    
    double num = a * sqr(R) + d2 * sqr(d);
    double denom = fivehalves(sqr(R) + sqr(d)) * cube(g);
    
    double den = coeff * num * inv(denom);
    
}


int main (int argc, char * const argv[])
{
    
  
}