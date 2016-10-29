#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "psedoRandomNumbers.h"
void initialize()
{
    srand(time(NULL));
}

double Marsaglia()
{
    double y1, y2, s;

    do
    {
        y1 = randomNumber(-1,1); //einai anoixto diasthma mhpws thelei allagh?
        y2 = randomNumber(-1,1);
        s = y1*y1+y2*y2;
    }while(s == 0 || s>=1); //s oxi mhden giati mpainei ston paranomasth

    return y1*sqrt((-2* log(s))/s);
}

double randomNumber(double from, double to)
{
    return from + ((double)rand() / RAND_MAX)*(to-from); //Μ + (rand() / RAND_MAX + 1.0)*(N-M+1) from + ((double)rand() / RAND_MAX+1.0)*(to-from+1);
}

int randomNumberInt(int from, int to)
{
    return from + (rand() / (RAND_MAX+1.0))*(to-from+1);
}


int randomNumberInteger() //prepei na epistrefei kai arnhtikous
{
    int x = rand();
    if(rand()%2)
    {
        return x;
    }
    else
    {
        return -x;
    }
}
