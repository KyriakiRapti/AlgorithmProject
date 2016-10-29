//arxeio gia test 2D arrays 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>

using namespace std;

#define WIDTH 5
#define HEIGHT 5

int main(void)
{
	srand(time(NULL));
	
	int n,m,i,l;
	int r1,r2; //ta shmeia gia ekastote h
	int k=4; //to k pou xrhsimopoioume kai stis upoloipes me8odous
	int no=5; //to plh8os twn stoixeiwn
	float *g; //h timh ths gfunction
	float *h; //h timh ths hi (oles oi hi sugrotoun thn g)
	int *x1; //pinakas x1 gia tis h 
	int *x2; //pinakas x2 gia tis h
	int item=1;
	int j;
	int z=0;
	float t1=0.0;
	
	
	int metrics[WIDTH][HEIGHT] = {  
			{0, 3, 8, 5, 7} ,   
			{3, 0, 9, 12, 11} ,   
			{8, 9, 0, 6, 4}	,		
			{5, 12, 6, 0, 5} ,	
			{7, 11, 4, 5, 0} 	
	};
	
	g=new float[k];
	h=new float[k];
	x1=new int[k];
	x2=new int[k];
	
	for(i=0;i<k;i++)
	{
		int r1= no*(rand() / (RAND_MAX + 1.0)); // ta shmeia pou 8eloume na tsekaroume. 
		int r2= no*(rand() / (RAND_MAX + 1.0));
		x1[i]=r1; //x1 einai h position, x1+1 einai to shmeio 
		x2[i]=r2; //x2 einai h position, x2+1 einai to shmeio 
		
		h[i]=(pow(metrics[item][x1[i]],2)+pow(metrics[item][x2[i]],2)-pow(metrics[x2[i]][x1[i]],2))/(2*metrics[x2[i]][x1[i]]);  //h timh tou tupou
		
		for(l=0;l<no;l++) //upologismos tou t1, arxika to a8roisma twn h gia ola ta x ws pros ta x1,x2
		{
			z=z+(pow(metrics[l][x1[i]],2)+pow(metrics[l][x2[i]],2)-pow(metrics[x2[i]][x1[i]],2))/(2*metrics[x2[i]][x1[i]]);
		}
		
		t1=z/no; //no einai to a8roisma twn items, shmeiwn
		
		if(h[i]>=t1) //sugkrish gia na doume ti timh pairnei h g
		{
			g[i]=1;
		}
		else
		{
			g[i]=0;
		}
		
//		cout << "x1 is " << r1 << "and x2 is " << r2 << endl;
		
		
	}
	
	for(j=0;j<k;j++)
		cout << g[j] << "This is the value of g function" << endl;

	return 0;
}