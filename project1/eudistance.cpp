#include "eudistance.h"

double euclidean_distance(double item1[],double item2[], int d)
{
	double sum=0.0;
	double result=0.0;
	
	for(int i=0;i<d;i++)
	{
		sum=sum + pow((item1[i]-item2[i]),2.0);
	}
	
	result=sqrt(sum);
	
	return result;
}