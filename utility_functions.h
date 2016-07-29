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
void get_data(int Nd, int Nl, struct bodies * b, string extension);

int get_size(int type, string extension);

double randDouble(double low, double high);

void com(struct bodies * b, int N, double * cm, double * cmv, double mass);

void com_correction(double * cm, double * cmv, struct bodies * b, int N);

void init_comps(struct component & light, struct component & dark, double rscale_l, double rscale_d, double mass_l, double mass_d, int model1, int model2);