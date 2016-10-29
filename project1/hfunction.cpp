// hash function file for hamming

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int main (void)
{
	char *str;
	char *str2;
	int key;
	int i;
	
	str=new char[16];
	str2=new char[30];
	
	strcpy(str,"1001001110010");
	
	cout << "The string is " << str << endl;
	
/*	for(i=0;i<15;i++)
	{
		cout << "The character" << i << "is" << str[i] <<endl;
	}
*/	
	strncat(str2,&str[4],1); //edw 8a xrhsimopoiountai ta stoixeia ths g 
	strncat(str2,&str[8],1);
	strncat(str2,&str[7],1);
	
	cout << "The new word is " << str2 << endl;
	
	key=atoi(str2);
	
	cout << "The key is " << key << endl;
 	
	return 0;

	
}