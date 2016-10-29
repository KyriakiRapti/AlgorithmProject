//arxiko stadio klashs gia hamming, as to paroume apo thn arxh 
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <sstream>
#include "hash_functions.h"

using namespace std; 

extern int htsize;

class HashNode{
	
	private:
		string id;
		string str;
		HashNode* next;
		
	public:
		HashNode(string x,string y){
			this->id=x;
			this->str=y;
			this->next=NULL;
		}
	
		void setId(string a){
			this->id=a;
		}
		
		void setStr(string b){
			this->str=b;
		}
		
		void setNext(HashNode* next){
			this->next=next; 
		}
		
		string getId(){
			return id;
		}
		
		string getStr(){
			return str;
		}
		
		HashNode* getNext(){
			return next;
		}

};

class HashTable{
	
	private:
		HashNode** htable;
		int htsize; 
		int *g; 
		
	public: 
		HashTable(int htsize){
			htable=new HashNode*[htsize];
			for(int i=0;i<htsize;i++)
			{
				htable[i]=NULL;
			
			}
			cout << "Hash table created with size" << htsize << endl;
		}
//-------------------------------------------------------	
		void setSize(int x)
		{
			this->htsize=x;
		}
		
		int getSize()
		{
			return htsize;
		}
		
//-----------------------------------------------------------

		void setGfunction(int k)
		{
			int *g;
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
	
		this->g=g;
		}
		
		int* getGfunction()
		{
			return g;
		}
		

//--------------------------------------------------------

		void setRec(string w,string z, int k) //opou w to id kai z to string apo 010101
		{
			string str;
			int n;
			int key=0; 
			int y,i;
			int* t;
			
			t=getGfunction();
		
			for(i=0;i<k;i++)
			{
				cout << "The proper g function is " << z[t[i]] << endl;
				str=str+z[t[i]];
		
			}
	
			cout << "The final result of the g function is" << str << endl; 
	
			stringstream convert(str);
			
			if ( !(convert >> n) )
			{
				n = 0;
			}
		
	
			for (y=0;n>0;y++)
			{
				if(n%10==1)
				{
					key=key+pow(2,y);
				}
				n=n/10;
			}
			
			cout << "The key of the hash function is " << key << endl;
		
			//int hash=0;
			if(htable[key]==NULL) //an to sugkekrimeno bucket einai adeio 
			{
				htable[key]=new HashNode(w,z);
			}
			else //an uparxoun hdh stoixeia mesa 
			{
				HashNode* record=htable[key];
				while(record->getNext()!=NULL) //oso briskei stoixeio, phgainei sto epomeno 
				{
					record=record->getNext();
				}
				record->setNext(new HashNode(w,z)); 
			}
		}

		void getRec(string z,int k)
		{
				string str;
			int n;
			int key=0; 
			int y,i;
			int* t;
			
			t=getGfunction();
		
			for(i=0;i<k;i++)
			{
				cout << "The proper g function is " << z[t[i]] << endl;
				str=str+z[t[i]];
		
			}
	
			cout << "The final result of the g function is" << str << endl; 
	
			stringstream convert(str);
			
			if ( !(convert >> n) )
			{
				n = 0;
			}
		
	
			for (y=0;n>0;y++)
			{
				if(n%10==1)
				{
					key=key+pow(2,y);
				}
				n=n/10;
			}
		
			if(htable[key]==NULL)
			{
				cout << "There was a problem with insert" <<endl;
			}
			while(htable[key]!=NULL)
			{
				if((htable[key]->getStr())==z)
				{
					cout << htable[key]->getId() << endl;
					cout << htable[key]->getStr() << endl;
				}
				htable[key]=htable[key]->getNext();
			}
		}  
		
//-------------------------------------------------------		
		
		~HashTable()
		{
			for(int i=0; i<(this->getSize()); i++ ) //sth 83sh tou 10 to htsize 
			{
				if (htable[i] != NULL) 
				{
                        HashNode* ptemp = NULL;
                        HashNode* temp = htable[i];
                        while (temp!= NULL) 
						{
                             ptemp = temp;
                             temp = temp->getNext();
                             delete ptemp;
						}
				}
			}
			delete[] htable;
			cout << "Hash Table deleted" << endl; 
		}
	
};


int main(void){
	
	int k=3;
	int htsize=pow(2,k);
	int* g;
	int *t;
	int z;
	
	g=new int[k];
	//t=new int[k];
	
	HashNode no("xazo","paidi");
	HashTable htable(htsize);
	
	string x;
	
	
	htable.setGfunction(k);
	g=htable.getGfunction();
	
	cout << g[0] << endl;
	cout << g[1] << endl;
	cout << g[2] << endl;
 	
	x=(no.getId())+(no.getStr());
	cout << "The k given is " << k << endl;
//	cout << x << endl; 
	
	htable.setSize(htsize);
	htable.setRec("Alice","101011101010010000101011000010010000100100010001110110001110000",k);
/*	htable.setRec("Marta","Bob");
	htable.setRec("Marta","Bob");
	htable.setRec("Marta","Bobana");
	htable.setRec("Masgsfrta","Badgob");
	htable.setRec("Martvada","Bosbb"); */
	htable.getRec("101011101010010000101011000010010000100100010001110110001110000",k); 

	return 0;
}