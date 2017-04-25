/* Copyright (c) 2016 Siddhartha Shelton */
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
#define pi ( 4.0 * atan(1.0) )
#define pi_4_3 (4.0 * pi / 3.0)
#define hubble ((double) 73.8 / 1000.0) //km/s/kpc
#define hubble_gyr ((double) hubble * 3.154 *inv(3.086) ) //conversion to 1/gyr -> (km/s/kpc * 3.15576e16s/gyr * 1kpc/3.086e16km)
#define pcrit_exact ((double) 3.0 * sqr(hubble_gyr) / (8.0 * pi) )
#define pcrit       0.000679087369829744220469326744094105320596648627735869652//precalculated version of pcrit
#define vol_pcrit   0.568910904587397184785763397846734505212216314432372653620//vol_pcrit = 200.0 * pcrit * PI_4_3 

#define lm       (int) 0
#define dm       (int) 1
#define plummer  (int) 2
#define nfw      (int) 3
#define gen_hern (int) 4
#define einasto  (int) 5
#define miyamoto (int) 6
#define log_halo (int) 7
struct position
{
    double x;
    double y;
    double z;
    double r;
    double l; 
    double b;
};

struct velocity
{
    double vx;
    double vy;
    double vz;
    double v;
};

struct bodies
{
    position pos;
    velocity vel;
    double mass;
    int type;
};


struct component
{
    double mass;
    double rscale;
    int type;
    double p0;
    double r200;
    double vhalo;
    double scale_height;
};

struct galaxy_model
{
    component bulge;
    component disk;
    component halo;
};