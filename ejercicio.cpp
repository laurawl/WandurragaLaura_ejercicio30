#include<iostream>
#include <fstream>
#include <sstream>
#include <math.h> 
#include<cmath>

using namespace std;
    

void difu(string nombre_txt, float dx,float dt,int num, int numt, int s, int D)
{
	ofstream file;
	file.open(nombre_txt.c_str());
	float datosxn[numt][num];
    for (int i = 0; i < numt; ++i)
	{
		for (int j = 0; j < num; ++j)
		{	
           datosxn[i][j]=0;
        }
    }          
          
	for (int i = 0; i < numt-1; ++i)
	{
		for (int j = 1; j < num-1; ++j)
		{	
            
       datosxn[i+1][j]-datosxn[i][j]=((datosxn[i][j+1]+datosxn[i][j-1])/2-datosxn[i][j])+pow(dx,2)*s/(2*D);
			file << datosxn[i][j]<< " ";
		}
			file << "\n";
		}
		file.close();
}
     
		

int main()
{
    static int numx = 30;
    static int numt = 500;
    static float dx = 2.0/numx; 
    static float dt = 1.0/numt;
    static float s=1;
    static float D=1;
	difu("parte1.dat",dx,dt,numx,numt,s,D);
	return 0;
}