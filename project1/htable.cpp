//Hamming Hash Table for project - emiris

#include <iostream>
#include <string>
using namespace std;

/*struct record
{
	char string[64];
	int id; 
}*/

class hash_node
{
	private:
		char* string; 
		int id; 
		hash_node* next; 
	public
		hash_node(char *str, int did) //constructor  (dhmiourgei node me to antikeimeno kai to hamming string pou 8eloume na apo8hkeusoume)
		{
			this->string=new char[65];
			strcpy(this->string,str);
			this->id=did;
			this->next=NULL;
		}
//---------------------------------------------------------
//sunarthseis set 		
		void set_data(char *str)  //bazei thn eggrafh sto node 
		{
			this->string=new char[65];
			strcpy(this->string,str);			
		}
		
		void set_id(int did)  //bazei to id ths eggrafhs sto node 
		{
			this->id=did;			
		}
		
		void set_next(hash_node* next) //bazei to next 
		{
			this->next=next;
		}
	
//-----------------------------------------------------------
//sunarthseis get 

		char* get_string()
		{
			return string;
		}
		
		int get_id()
		{
			return id; 
		}
		
		hash_node* get_next() //epistrefei to next 
		{
			return next;
		}			
}

class htable
{
	private: 
		hash_node **htable;
	public:
		htable() //
		{
			htable=new(hash_node*(htsize));
			for(int i=0;i<htsize;i++)
			{
				htable[i]=NULL;
				
			}
		}
		
		void set_record(char *str, int id, int position)
		{
			if(htable[position]==NULL)
			{
				htable[position]=new hash_node(str,id);
			}
			else
			{
				hash_node* ptr=htable[position];
				while(ptr->get_next()!=NULL)
				{
					ptr=ptr->get_next();
				}
				ptr->set_next(new hash_node(str,id));
			}
		}
	
		~htable()
		{
			for(int i=0;i<htsize;i++)
			{
				if(htable[i]!=NULL)
				{
					hash_node* temp=NULL;
					hash_node* htemp=htable[i];
					while(htemp!=NULL)
					{
						temp=htemp;
						htemp=htemp->get_next();
						delete temp;
					}
				}
			}
			delete htable[];
		}
}














