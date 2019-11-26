#include<iostream>
#include <fstream>
#include <sstream>
#include <math.h> 
#include<cmath>

using namespace std;
    

void difu(string nombre_txt, float dx,float dt,int num, int s, int D)
{
	ofstream file;
	file.open(nombre_txt.c_str());         
    float a=0;
	float max=0;
	int i=0;
	while(a<pow(10,-6)) 
	{
		float datosxn[2][num];
		for (int j = 1; j < num-1; ++j)
		{	
		   datosxn[1][j]=datosxn[0][j]+((datosxn[0][j+1]+datosxn[0][j-1])/2-datosxn[0][j])+pow(dx,2)*s/(2*D);
		   a=datosxn[1][j]-datosxn[0][j];
		   if (max<a)
		   {
			   max=a
			b=datosxn[0][j]
		   }
		}
		i+=1;
	}
	file << i << a <<"\n";
	file.close();
}
     
		

int main()
{
    static int numx = 30;
    static float dx = 2.0/numx; 
    static float dt = 1.0/numt;
    static float s=1;
    static float D=1;
	difu("parte1.dat",dx,dt,numx,s,D);
	return 0;
}