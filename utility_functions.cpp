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
    double datavx,datavy,datavz, datam;
    int i = 0;
    int N = Nd + Nl;
    s = string("raw_data/light_matter_" + extension + ".dat");
    ifstream data;
    data.open(s);
    int type_dark = 1;
    int type_light = 0;
    
    while(data>>datax>>datay>>dataz>>datal>>datab>>datar>>datavx>>datavy>>datavz>>datam)
    {
        b[i].x    = datax;
        b[i].y    = datay;
        b[i].z    = dataz;
        b[i].l    = datal;
        b[i].b    = datab;
        b[i].r    = in_quad(datax, datay, datay);
        b[i].vx   = datavx;
        b[i].vy   = datavy;
        b[i].vz   = datavz;
        b[i].v    = in_quad(datavx, datavy, datavy);
        b[i].mass = datam;
        b[i].type = type_dark;
        i++;
    }
    data.close();

    s = string("raw_data/dark_matter_" + extension + ".dat");
    data.open(s);
    while(data>>datax>>datay>>dataz>>datal>>datab>>datar>>datavx>>datavy>>datavz>>datam)
    {
        b[i].x    = datax;
        b[i].y    = datay;
        b[i].z    = dataz;
        b[i].r    = in_quad(datax, datay, datay);
        b[i].vx   = datavx;
        b[i].vy   = datavy;
        b[i].vz   = datavz;
        b[i].v    = in_quad(datavx, datavy, datavy);
        b[i].mass = datam;
        b[i].type = type_light;
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
        cm_x += b[i].mass * b[i].x;
        cm_y += b[i].mass * b[i].y;
        cm_z += b[i].mass * b[i].z;
        
        cmv_x += b[i].mass * b[i].vx;
        cmv_y += b[i].mass * b[i].vy;
        cmv_z += b[i].mass * b[i].vz;
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
        r_corrected = sqrt( sqrdif(cm[0], b[i].x)  + sqrdif(cm[1], b[i].y)  + sqrdif(cm[2], b[i].z) );
        v_corrected = sqrt( sqrdif(cm[0], b[i].vx) + sqrdif(cm[1], b[i].vy) + sqrdif(cm[2], b[i].vz) );
//         printf("%f\t%f\t%f\t%f\t%f\t%f\n", b[i].x, b[i].y, b[i].z, b[i].vx, b[i].vy, b[i].vz);
        b[i].x -= cm[0];
        b[i].y -= cm[1];
        b[i].z -= cm[2];
        
        b[i].vx -= cmv[0];
        b[i].vy -= cmv[1];
        b[i].vz -= cmv[2];
        
        b[i].r = r_corrected;
        b[i].v = v_corrected;
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
    
}

/*escape velocity*/
double esc_vel(double r, struct component & light, struct component & dark)
{
    double light_comp = get_potential(r, light);
    double dark_comp  = get_potential(r, dark);
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
    for(int i = 0; i != binN; i++)
    {bins[i] = 0;}
    ofstream bin;
    bin.open (s);
    
    for(int j = 0; j < N; j++)/*tests one of the numbers at a time*/
    {
        
        range = 0;/*resets the range so that the bins can be tested again against the number*/
        if(type == 1)
        {
            range = -4.0;
            upper = 4.0;
        }
        if(type == 2 )
        {
            range = -15.0;
            upper = 0.0;
        }
        
        for(int i = 0; i < binN; i++)/*for each bin, the number is tested*/
        {
            if( ( range + binwidth ) < upper)
            {
                
                /*this if statement tests to see if the random number is in that
                bin range.*/
                if ( x[j] >= range && x[j] < ( range + binwidth ) )
                {
                    bins[i] = bins[i] + 1;
                    break;
                }
                range = range + binwidth;/*this statement changes the range of testing
                so that a new new bin can be checked against the number*/
            }
            else if( (range + binwidth) == upper)/*includes the upper interval*/
            {
                if(x[j] >= range && x[j] <= (range + binwidth))
                {
                    bins[i] = bins[i] + 1;
                    break;
                }
                range = range + binwidth;
            }

        }
    }


    double total = 0;
    double binrange = 0;
    
    if(type == 1)
    {
        binrange = -4.0;
    }
    
    if(type == 2 )
    {
        binrange = -15.0;
    }
    
    for(int i = 0; i != binN; i++)
    {
        binrange = binrange + binwidth;
        bin<<bins[i]<<"\t"<<binrange<<endl;
    }
    bin.close();
}