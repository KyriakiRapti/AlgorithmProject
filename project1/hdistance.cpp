//distances.cpp
#include "hdistance.h"

int hamming_distance(bitset<64> str1,bitset<64> str2)
{
	int distance=0;
	
	for(int i=0;i<64;i++)
	{
		if(str1[i]!=str2[i])
		{
			distance++;
		}
	}
	
	return distance;
}