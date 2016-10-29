//arxiko stadio klashs gia hamming, as to paroume apo thn arxh 
#include <iostream>
#include <cstdlib>
#include <cstring>

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
		
//--------------------------------------------------------

		void setRec(string w,string z) //opou w to id kai z to string apo 010101
		{
			int hash=8;
			if(htable[hash]==NULL) //an to sugkekrimeno bucket einai adeio 
			{
				htable[hash]=new HashNode(w,z);
			}
			else //an uparxoun hdh stoixeia mesa 
			{
				HashNode* record=htable[hash];
				while(record->getNext()!=NULL) //oso briskei stoixeio, phgainei sto epomeno 
				{
					record=record->getNext();
				}
				record->setNext(new HashNode(w,z));
			}
		}

		void getRec(string a)
		{
			int hash=8;
			if(htable[hash]==NULL)
			{
				cout << "There was a problem with insert" <<endl;
			}
			while(htable[hash]!=NULL)
			{
				if((htable[hash]->getStr())==a)
				{
					cout << htable[hash]->getStr() << endl;
					cout << htable[hash]->getId() << endl;
				}
				htable[hash]=htable[hash]->getNext();
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
	
	int htsize=10;
	
	HashNode no("xazo","paidi");
	HashTable htable(htsize);
	
	string x;
	
	x=(no.getId())+(no.getStr());
	
	cout << x << endl; 
	
	htable.setSize(htsize);
	htable.setRec("Alice","Bob");
	htable.setRec("Marta","Bob");
	htable.setRec("Marta","Bob");
	htable.setRec("Marta","Bobana");
	htable.setRec("Masgsfrta","Badgob");
	htable.setRec("Martvada","Bosbb");
	htable.getRec("Bob");
	
	return 0;
}