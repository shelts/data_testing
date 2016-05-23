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
#define sqr(x) ( x * x )
#define sqrdel(x1, x2) sqr( (x1 - x2 ))


struct bodies
{
    double x, y, z;
    double l, b, r;
    double vx, vy, vz;
    double mass;
    int type;
    int bar;
};

/*This gets the number of positional data from the raw data files*/
int get_size(string file_name)
{
    int N = 0;
    double datax;
    /*getting the length of the data set*/
    ifstream length;
    length.open (file_name);
    while(length>>datax>>datax>>datax>>datax>>datax>>datax)
    {
        N++;
    }
    length.close();

    return N;
}


void get_data(struct bodies * b, string file_name)
{
  
    string s;
    double d_x, d_y, d_z;
    double d_l, d_b, d_r;
    double d_vx, d_vy, d_vz;
    double m;
    int i = 0;
    ifstream data;
    data.open (file_name);
    int type;
    while(data >> type >> d_x >> d_y >> d_z >> d_l >> d_b >> d_r >> d_vx >> d_vy >> d_vz >> m)
    {
        b[i].type = type;
        b[i].x    = d_x;
        b[i].y    = d_y;
        b[i].z    = d_z;
        b[i].l    = d_l;
        b[i].b    = d_b;
        b[i].r    = d_r;
        b[i].vx   = d_vx;
        b[i].vy   = d_vy;
        b[i].vz   = d_vz;
        b[i].mass = m;
        i++;
//         printf("%f\n", data);
    }
    data.close();

  
}
  
void vel_dis(int N, struct bodies * b, string extension)
{
    double vx, vy, vz,v;
    double x, y, z, r;
    string s ="./test_output/vel_dis_"+extension+".txt";

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
  
int main (int argc, char * const argv[])
{
    string file_name = argv[1];
    int N = get_size(file_name);//getting the size of the dark matter data
    bodies b[N];
    double cm[3] = {0.0, 0.0, 0.0};
    double cmv[3] = {0.0, 0.0, 0.0};
    
    get_data(b, file_name);
    printf("%f\n", b[1].y );
}