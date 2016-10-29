#include "metrics_functions.h"

x::x(int k)
{
	x1=new int[k];
	x2=new int[k];
}

void x::set_value(int k,int no)
{
	srand(time(NULL));
	
	for(int i=0;i<k;i++)
	{
		int r1= no*(rand() / (RAND_MAX + 1.0)); // ta shmeia pou 8eloume na tsekaroume. 
		int r2= no*(rand() / (RAND_MAX + 1.0));
		x1[i]=r1; //x1 einai h position, x1+1 einai to shmeio 
		x2[i]=r2; //x2 einai h position, x2+1 einai to shmeio 
	}
}

int* x::get_x1()
{
	return x1;
}

int* x::get_x2()
{
	return x2;
}

int* gfunction(int* x1,int* x2,int k,int no,int metrics[][WIDTH],int item)
{
	float *h;
	int z=0;
	float t1=0.0;
	int *g;
	float* t;
	int w;
	int i,j,l;
	float temp;
	
	h=new float[k];
	g=new int[k];
	t=new float[no];
	
	for(i=0; i<k; i++)
	{
		cout << "Mphkame sth rhmada thn epanalhpsh" << endl;
		h[i]=(pow(metrics[item][x1[i]],2)+pow(metrics[item][x2[i]],2)-pow(metrics[x2[i]][x1[i]],2))/(2*metrics[x2[i]][x1[i]]);
		cout << "h function is " << i << "and the value is " << h[i] << endl;
		
		for(w=0;w<no;w++) 
		{
			t[w]=(pow(metrics[w][x1[i]],2)+pow(metrics[w][x2[i]],2)-pow(metrics[x2[i]][x1[i]],2))/(2*metrics[x2[i]][x1[i]]);

		}
		//taxinomhsh
		for(l=0;l<no;l++) //gia ka8e stoixeio tsekaroume 
		{	
			for(j=0;j<no-i;j++)
			{
				if((t[j]>t[j+1])&&(j!=(no-1)))
				{
					temp=t[j];
					t[j]=t[j+1];
					t[j+1]=temp;
				}
			}
		}
		
		if(no%2==0) //artios
		{
			int a=no/2;
			t1=(t[a]+t[a+1])/2;
		}
		else //perittos
		{
			int a=(no+1)/2;
			t1=t[a];
		}
		
		cout << "t1 is " << t1 << endl;
		
		if(h[i]>=t1) //sugkrish gia na doume ti timh pairnei h g
		{
			g[i]=1;
		}
		else
		{
			g[i]=0;
		} 
		
	} 
	
	return g;
	
}

int hkey(int* g, int k)
{
	int n=0;
	int key=0; 
	int y=0;
	
	for(int i=0;i<k;i++)
	{
		y=k-i-1;
		n=n+(g[i]*(pow(10,y)));
	}
	
	cout << n << endl;
	
	for (int w=0;n>0;w++)
	{
		if(n%10==1)
		{
			key=key+pow(2,w);
		}
		n=n/10;
	}
		
	return key;
}








