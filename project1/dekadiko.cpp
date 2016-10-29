//metatroph apo duadiko se dekadiko ari8mo

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (void)
{
	int i=0; 
	int n=11111;
	int x=0;
	for (i=0;n>0;i++)
	{
		if(n%10==1)
		{
			x=x+pow(2,i);
		}
		n=n/10;
	}
	
	cout << "The key is " << x << endl;
}