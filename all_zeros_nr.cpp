#include <iostream>
#include <fstream>
#include <cmath>
#include <tgmath.h>
#include <cstdlib>
#include <cfloat>
#include <time.h>

using namespace std;

//creates function call
double function1(double x){
double fun;
fun= x*x -5.0*x+6.0;
return fun;

}
//derivative
double dfunct1(double x){
double dfun;
double h=0.01;
dfun= (function1(x+h)-function1(x-h)) /(2*h);
return dfun;
}

double randDouble(double low, double high)
{
double temp;
/* calculate the random number & return it */
temp = ((double) rand() / (static_cast<double>(RAND_MAX) + 1.0))* (high - low) + low;
return temp;
}


int main (){
//variabe library
double xo;
double fun;
double m,b;
double temp, tempf;
double zero1;
srand(time(NULL));

for(int i=1;i!=2;i++)
{
    xo=randDouble(-100,100);
    while(1)//loop runs the Newton_Raph method.
    {

	//assigns values to method parameters
        fun=function1(xo);
        m=dfunct1(xo);
        b=function1(xo)-(m*xo);
	
	//tests the function to see if at zero
        if(abs(fun)<1e-3)
        {break; }
	
	//this section does backtracking.
        temp= -1*b/m;
        tempf=function1(temp);
        while(abs(tempf)>abs(fun))
        {
            temp=temp/2;
            tempf=function1(temp);
        }
	//reassigns xo to the new value.
        xo=temp;

    }

    if(i==1)
    {
        zero1=xo;
        cout<<"Zero located at x= "<< zero1<<"\n";
        continue;
    }
    else if(i!=1)
    {
        if(zero1==xo)
        {continue;}
        else if(zero1!=xo)
        {
            cout<<"Zero located at x= "<<xo<<"\n";
            break;
        }
    }
}


}

