#include "hash_functions.h" 

/*#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>*/


int main(void)
{
	int k=5;
	int *g;
	int x;
	char *str;
	
	str=new char[65];
	
	strcpy(str,"101011101010010000101011000010010000100100010001110110001110000");
	
	g=new int[k];
	
	g=gfunction(k);
	
	for(int i=0;i<k;i++)
	{
		cout << "the hash function element is" << g[i] << endl;
	}
	
	x=hkey(g, str, k);
	
	cout << "Finally the key is" << x << endl; 
	
	return 0;
	
	
}