//arxeio gia random numbers using rand and time  

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>

using namespace std; 

int main(void)
{
	srand(time(NULL));
	
	
	
	int r= 64*(rand() / (RAND_MAX + 1.0));
	
	cout << "The random number is" << r << endl; 
}