//distance for euclidean hash method 
#include <iostream>
#include <cstdlib>
#include <bitset> 
#include <string>
#include <cmath>
#include "eudistance.h"

using namespace std;

int main(void){
	
	int d=5;
	double item1[]={1.3,3.4,2.3,6.5,4.0};
	double item2[]={1.9,2.5,8.7,3.1,5.2};
	
	double result=euclidean_distance(item1,item2,d);
	
	cout << "The result of the euclidean distance is " << result <<endl;
	
	return 0;
}