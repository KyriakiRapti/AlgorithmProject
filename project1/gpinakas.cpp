//peiramatiko arxeio gia apo8hkeush ths g 

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

int main(void)
{
	int *g;
	int k=5;
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
	
	return 0;
}