//dmain.cpp
#include <iostream>
#include <cstdlib>
#include <bitset> 
#include <string>
#include "hdistance.h"

using namespace std;

int main(void)
{
	int distance;
	int k=5;
	
	string temp="1010111010100100001010110000100100001001000100011101100011100000";
	string temp2="0010111010101100011010111101100000011001110001010101100001100100";
	
	bitset<64> str1(temp);
	bitset<64> str2(temp2);
		
	distance=hamming_distance(str1,str2);
	
	cout << "The distance of the hamming items is " << distance << endl;
	
	return 0;
	
}