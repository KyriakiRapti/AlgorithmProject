//functions gia ta metric spaces
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>

#define WIDTH 5
#define HEIGHT 5

using namespace std;

class x 
{
	private:
		int *x1;
		int *x2;
	public:
		x(int k);
		
		void set_value(int k,int no);
		
		int* get_x1();
		int* get_x2();
		
};

int* gfunction(int* x1,int* x2,int k,int no,int metrics[][WIDTH], int item);
int hkey(int* g, int k);