/* Copyright (c) 2016 Siddhartha Shelton */
#include "structs.h"
#include "utility_functions.h"
#include "pots_dens.h"

/*This gets the number of positional data from the raw data files*/
int get_size(int type, string extension)
{
    string s;
    
    if(type == 0){s = string("./raw_data/light_matter_"+extension+".dat");}
    else {s = string("./raw_data/dark_matter_"+extension+".dat");}
    
    int N = 0;
    double datax;
    /*getting the length of the data set*/
    ifstream length;
    length.open (s);
    while(length>>datax>>datax>>datax>>datax>>datax>>datax>>datax>>datax>>datax>>datax)
    {
    //       cout<<datax<<endl;
        N++;
    }
    length.close();

    return N;
}

/*this gets the actual data*/
void get_data(int Nd, int Nl, struct bodies * b, string extension)
{
  
    string s;
    double datax,datay,dataz;
    double datal, datab, datar;
    double datavx, datavy, datavz, datam;
    int i = 0;
    s = string("raw_data/light_matter_" + extension + ".dat");
    ifstream data;
    data.open(s);
    
    while(data>>datax>>datay>>dataz>>datal>>datab>>datar>>datavx>>datavy>>datavz>>datam)
    {
        b[i].pos.x    = datax;
        b[i].pos.y    = datay;
        b[i].pos.z    = dataz;
        b[i].pos.l    = datal;
        b[i].pos.b    = datab;
        b[i].pos.r    = in_quad(datax, datay, datay);
        b[i].vel.vx   = datavx;
        b[i].vel.vy   = datavy;
        b[i].vel.vz   = datavz;
        b[i].vel.v    = in_quad(datavx, datavy, datavy);
        b[i].mass = datam;
        b[i].type = lm;
        i++;
    }
    data.close();

    s = string("raw_data/dark_matter_" + extension + ".dat");
    data.open(s);
    while(data>>datax>>datay>>dataz>>datal>>datab>>datar>>datavx>>datavy>>datavz>>datam)
    {
        b[i].pos.x    = datax;
        b[i].pos.y    = datay;
        b[i].pos.z    = dataz;
        b[i].pos.r    = in_quad(datax, datay, datay);
        b[i].vel.vx   = datavx;
        b[i].vel.vy   = datavy;
        b[i].vel.vz   = datavz;
        b[i].vel.v    = in_quad(datavx, datavy, datavy);
        b[i].mass = datam;
        b[i].type = dm;
        i++;
    }
    data.close();
  
}


/*quick random number generator*/
double randDouble(double low, double high)
{
    double temp;
/* calculate the random number & return it */
    temp = ((double) rand() / (static_cast<double>(RAND_MAX) + 1.0))* (high - low) + low;
    return temp;
}

/*calculates the center of mass and center of momentum and stores it into arrays*/
void com(struct bodies * b, int N, double * cm, double * cmv, double mass)
{
    double cm_x = 0.0;
    double cm_y = 0.0;
    double cm_z = 0.0;
    double cmv_x = 0.0;
    double cmv_y = 0.0;
    double cmv_z = 0.0;

    for(int i = 0; i < N; i++)
    {
        cm_x += b[i].mass * b[i].pos.x;
        cm_y += b[i].mass * b[i].pos.y;
        cm_z += b[i].mass * b[i].pos.z;
        
        cmv_x += b[i].mass * b[i].vel.vx;
        cmv_y += b[i].mass * b[i].vel.vy;
        cmv_z += b[i].mass * b[i].vel.vz;
    }
    
    
    cm[0] = cm_x * inv(mass);
    cm[1] = cm_y * inv(mass);
    cm[2] = cm_z * inv(mass);
    
    cmv[0] = cmv_x * inv(mass);
    cmv[1] = cmv_y * inv(mass);
    cmv[2] = cmv_z * inv(mass);
//     printf("%f\t%f\t%f\t%f\t%f\t%f\n", cm[0], cm[1], cm[2], cmv[0], cmv[1], cmv[2]);
}

/*used to correct for center of mass and momentum drift*/
void com_correction(double * cm, double * cmv, struct bodies * b, int N)
{
    double r_corrected, v_corrected;
    for(int i = 0; i < N; i++)
    {
        r_corrected = sqrt( sqrdif(cm[0], b[i].pos.x)  + sqrdif(cm[1], b[i].pos.y)  + sqrdif(cm[2], b[i].pos.z) );
        v_corrected = sqrt( sqrdif(cm[0], b[i].vel.vx) + sqrdif(cm[1], b[i].vel.vy) + sqrdif(cm[2], b[i].vel.vz) );
//         printf("%f\t%f\t%f\t%f\t%f\t%f\n", b[i].x, b[i].y, b[i].z, b[i].vx, b[i].vy, b[i].vz);
        b[i].pos.x -= cm[0];
        b[i].pos.y -= cm[1];
        b[i].pos.z -= cm[2];
        
        b[i].vel.vx -= cmv[0];
        b[i].vel.vy -= cmv[1];
        b[i].vel.vz -= cmv[2];
        
        b[i].pos.r = r_corrected;
        b[i].vel.v = v_corrected;
//         printf("%f\t%f\t%f\t%f\t%f\t%f\n", b[i].x, b[i].y, b[i].z, b[i].vx, b[i].vy, b[i].vz);
    }
    
}

/*to initialize the structs for the two components*/
void init_comps(struct component & light, struct component & dark, double rscale_l, double rscale_d, double mass_l, double mass_d, int model1, int model2)
{
    light.type = model1;
    light.rscale = rscale_l;
    light.mass = mass_l;
    
    dark.type = model2;
    dark.rscale = rscale_d;
    dark.mass = mass_d;
    
    
    //init the p0 parameter at the start to avoid having to recalc it
    switch(light.type)
    {
        case plummer:
            break;
        case nfw:
            light.p0 = get_p0(light);
            break;
        case gen_hern:
            break;
        default:
            printf("unknown model\n");
    }
    
    switch(dark.type)
    {
        case plummer:
            break;
        case nfw:
            dark.p0 = get_p0(dark);
            break;
        case gen_hern:
            break;
        default:
            printf("unknown model\n");
    }
    
}

/*escape velocity*/
double esc_vel(struct position & pos, struct component & light, struct component & dark)
{
    double light_comp = get_potential(pos, light);
    double dark_comp  = get_potential(pos, dark);
    double potential =  (light_comp + dark_comp);
    
    double escv = sqrt( fabs(2.0 * potential ) );
    return escv;
}


/*this is a binning routine, makes a histogram*/
void binner(int binN, double binwidth, double * x, int N, string s, string extension, int type)
{
    // binN=number of bins
    //binwidthsize of bins
    double bins[binN];
    double range = 0;
    double upper = binN * binwidth;
    
    /*binning*/

    /*initializing bins*/
    for(int i = 0; i != binN; i++){bins[i] = 0;}
    ofstream bin;
    bin.open (s);
    
    /* type 0 are the radii/vels and their theta angles. they would start at zero and go forward.
     * type 1 is for phi, which starts at -pi and goes to pi
     */
    
    for(int j = 0; j < N; j++)/*tests one of the numbers at a time*/
    {
        
        range = 0;/*resets the range so that the bins can be tested again against the number*/
        if(type == 1)
        {
            range = -4.0;
            upper = 4.0;
        }
        
        for(int i = 0; i < binN; i++)/*for each bin, the number is tested*/
        {
            if( ( range + binwidth ) < upper)
            {
                
                /*this if statement tests to see if the random number is in that
                bin range.*/
                if ( x[j] >= range && x[j] < ( range + binwidth ) )
                {
                    bins[i] += 1;
                    break;
                }
                range += binwidth;/*this statement changes the range of testing
                so that a new new bin can be checked against the number*/
            }
            else if( (range + binwidth) == upper)/*includes the upper interval*/
            {
                if(x[j] >= range && x[j] <= (range + binwidth))
                {
                    bins[i] += 1;
                    break;
                }
                range += binwidth;
            }

        }
    }


    double total = 0;
    double binrange = 0;
    
    if(type == 1)
    {
        binrange = -4.0;
    }
    
    for(int i = 0; i != binN; i++)
    {
        binrange = binrange + binwidth;
        bin<<bins[i]<<"\t"<<binrange<<endl;
    }
    bin.close();
}


double max_finder(double (*profile)(double , struct position & , struct component &, struct component &), struct position & pos, struct component & comp1, struct component & comp2, double a, double b, double c)
{
    /*this is a maxfinding routine to find the maximum of the density.
     * It uses Golden Section Search as outlined in Numerical Recipes 3rd edition
     */
    double RATIO = 0.61803399;
    double RATIO_COMPLEMENT = 1.0 - RATIO;
    int counter = 0;
    double tolerance = 1e-4;
    int limit = 50;
    double profile_x1, profile_x2, x0, x1, x2, x3;
    x0 = a;
    x3 = c;
    
    if (fabs(b - c) > fabs(b - a))
    {
        x1 = b;
        x2 = b + (RATIO_COMPLEMENT * (c - b)); 
    }
    else
    {
        x2 = b;
        x1 = b - (RATIO_COMPLEMENT * (b - a));
    }

    profile_x1 = -(*profile)(x1, pos, comp1, comp2);
    profile_x2 = -(*profile)(x2, pos, comp1, comp2);
    
    while (fabs(x3 - x0) > (tolerance * (fabs(x1) + fabs(x2)) ) )
    {
        counter++;
        if (profile_x2 < profile_x1)
        {
            x0 = x1;
            x1 = x2;
            x2 = RATIO * x2 + RATIO_COMPLEMENT * x3;
            profile_x1 = (double)profile_x2;
            profile_x2 = -(*profile)(x2, pos, comp1, comp2);
        }
        else
        {
            x3 = x2;
            x2 = x1;
            x1 = RATIO * x1 + RATIO_COMPLEMENT * x0;
            profile_x2 = (double)profile_x1;
            profile_x1 = -(*profile)(x1, pos, comp1, comp2);
        }
        
        if(counter > limit)
        {
            break;
        }
    }

    if (profile_x1 < profile_x2)
    {
        return (-profile_x1);
    }
    else
    {
        return (-profile_x2);
    }
}

double get_masspp(struct bodies * b, int N, int type)
{
    double masspp;
    
    for(int i = 0; i < N; i++)
    {
        if(b[i].type == type)
        {
            masspp = b[i].mass;
        }
        
        if(masspp != 0.0){break;}
    }  
//     printf("%0.15f\n", masspp);
    return masspp;
}


double get_extra_nfw_mass(struct component & model)
{
    double r = 50.0 * model.r200;
    double rs = model.rscale;
    double m = 4.0 * pi * model.p0 * cube(rs) * (log( (rs + r) / rs) - r / (rs + r));
    return m;
}


void check_mass(struct component & model)
{
    
    switch(model.type)
    {
        case plummer:
            break;
        case nfw:
            model.mass = get_extra_nfw_mass(model);
            break;
        case gen_hern:
            break;
        default:
            printf("unknown model\n");
    }
    
}
    
    