#include <iostream>

using namespace std;

int main()
{

	int p[]={10,20,30,40};
	int *q = p;
	int x;

	x=*q;
	cout << x << endl;

//------------------------------

	x=*q++;
	cout << x << endl;

//-------------------------------

	x=*(q++);
        cout << x << endl;

//-----------------------------

	x=(*q)++;
	 cout << x << endl;

//-----------------------------

	x=*q;
	 cout << x << endl;

//-------------------------

	x=*++q;
	 cout << x << endl;

//-------------------------

	x=++*q;
	 cout << x << endl;

//----------------------



 
	return 0;

}
