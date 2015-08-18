#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <string>
using namespace std;


int get_size(string s)
{
    int N = 0;
    double datax;
 /*getting the length of the data set*/
    ifstream length;
    length.open (s);
    while(length>>datax>>datax)
    {
        N++;
    }
    length.close();
   
   return N;
}

void get_data(int N, double * bins, double * counts, string s)
{
    double datax, datay;
    int l = 0;

    ifstream data;
    data.open (s);
    /*reading in data*/
    while(data>>datax>>datay)
    {
        bins[l]    = datax;
        counts[l]  = datay;
        l++;
    }
    data.close();
}


void write_hist(int N, double * bins, double * counts, double * args, string s)
{
 
    int line = 0;
    
    
    
    
}


int main (int argc, char * const argv[])
{
    string simtime                 = argv[1];
    double rscale_l                = atof(argv[2]);
    double rscale_d                = atof(argv[3]);
    double mass_l                  = atof(argv[4]);
    double mass_d                  = atof(argv[5]);
    double mass_per_particle_light = atof(argv[6]); 
    double mass_per_particle_dark  = atof(argv[7]); 
    string extension = simtime + "gy";
    string l, d, b;
    int Nl, Nd, Nb;
    
    double args[] = {nbody, simtime
    
    
    b = string("binned_data/both_matter_bins_" + extension + ".dat");
    Nb = get_size(b);
    
    d = string("binned_data/dark_matter_bins_" + extension + ".dat");
    Nd = get_size(d);//getting the size of the dark matter data
    
    l = string("binned_data/light_matter_bins_" + extension + ".dat");
    Nl = get_size(l);//getting the size of the light matter data
    
    printf("%i %i %i\n", Nd, Nl, Nb);
    
    double binsl[Nl];
    double binsd[Nd];
    double binsb[Nb];
    
    double countsl[Nl];
    double countsd[Nd];
    double countsb[Nb];
    
    get_data(Nl, binsl, countsl, l);
    get_data(Nd, binsd, countsd, d); 
    get_data(Nb, binsb, countsb, b); 
     


}
