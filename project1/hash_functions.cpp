#include "hash_functions.h" 

int* gfunction(int k)
{
	int *g;
	int i=0;
	int r;
	
	srand(time(NULL));
	
	g=new int[k];
	
	for(i=0;i<k;i++)
	{
		r= 64*(rand() / (RAND_MAX + 1.0));
		g[i]=r;
		cout << "the element of g is " << g[i] << endl;
	}
	
	return g;
}

int hkey(int* g, char* rec, int k)
{
	char* str;
	int n;
	int key=0; 
	int y;
	
	str=new char[k+1];
		
	for(int i=0;i<k;i++)
	{
		cout << "The proper g function is " << g[i] << endl;
		strncat(str,&rec[g[i]],1); 
		
	}
	
	cout << "The final result of the g function is" << str << endl; 
	
	n=atoi(str);
	
	for (y=0;n>0;y++)
	{
		if(n%10==1)
		{
			key=key+pow(2,y);
		}
		n=n/10;
	}
	
	cout << "The key of the hash function is " << key << endl;
	return key;
}
