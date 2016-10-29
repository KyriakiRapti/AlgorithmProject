#include <iostream>
#include<fstream>
#include <sstream>
#include <string.h>
#include <bitset>
using namespace std;
#include "hashtable.h"

#include "Node.h"
#include "dataTypes.h"
#include "psedoRandomNumbers.h"

//#include "List.h"
//#include "Car.h"
//#include "bankAccount.h"
//#include <stdlib.h>
//#include "graph.h"
#include "hashNode.h"
#include "hashTableCosine.h"
//#include "hashNode.cpp"

//void menu(Graph*& bankSystem, string& line, int bucketSize);

int main(int argc, char *argv[])
{
    /*const int n= 4;
    bitset<n> foo(3);

    //cout<<foo[2]<<endl;
    HashNode<int>* t = new HashNode<int>(4, 3);

    Node<HashNode<int>* >* test = new Node<HashNode<int>* >(t);
    cout<<test->get_data()->get_data()<<endl;*/
    initialize();
    /*for(int i=0; i< 10000;i++)
    {
        cout<<Marsaglia()<<endl;
    }*/
    double anArray[2] = {1, 2};
    Cosine* t = new Cosine(2, anArray);
    //cout<<t->get_coordinance(0)<<endl;
    HashTableCosine* hashd = new HashTableCosine(16, 4, 2);
    cout<<hashd->hashFunction(t);

    /*HashTable<int>* hashT = new HashTable<int>(16);

    int t;
    hashT->insertNode(1, 12);
    hashT->insertNode(2, 3);
//    hashT->insertNode(12, 33);
    hashT->insertNode(3, 31);
    hashT->insertNode(40, 4);
    hashT->deleteFirstNode();
    hashT->deleteFirstNode();
    hashT->deleteFirstNode();
    hashT->deleteFirstNode();
    t = hashT->deleteFirstNode();
    hashT->printSizeOfBuckets();

    delete hashT;
    cout<<t<<endl;*/

    //List<HashNode<int>> myList= new List<HashNode<int>>();
    //myList.insertBeginning(t);

/*
    Car* c = new Car(2);
    Car* c1 = new Car(1);
    Car* c3 = c1;
    List<Car*>* myList = new List<Car*>();

    myList->insertBeginning(c);
    myList->insertBeginning(c1);

    c3 = myList->deleteFirstNode();
    c3 = myList->deleteFirstNode();

    cout<<c3->getR()<<endl;
*/    /*int bucketSize = -1;
    Graph* bankSystem;
    string line;
    ifstream inFile;

    if(argc != 3 && argc != 5)
    {
        cout<<"error arguments"<<endl;
        return - 2;
    }
    for(int i =1; i < argc; i++) //eisodos twn arguments
    {
        if(i+1 != argc)
        {
            if(strcmp(argv[i], "-o") == 0)
            {
                inFile.open(argv[i+1]);
            }
            else if(strcmp(argv[i], "-b") == 0)
            {
                bucketSize = atoi(argv[i+1]);
            }
        }
    }
    if(bucketSize <= 0)
    {
        cout<<"error number of buckets"<<endl;
        return -3;
    }

    bankSystem = new Graph(bucketSize);
    if(inFile.is_open() && (inFile)) //eisodos apo arxeio efoson yparxei
    {
        while(getline(inFile, line))
        {
            //cout<<line<<endl;
            menu(bankSystem, line, bucketSize);
        }
    }

    while(!getline(cin, line).eof()) //eisodos apo pliktrologio
    {
        menu(bankSystem, line, bucketSize);
    }

    if(bankSystem != NULL)
    {
        delete bankSystem;
    }
    inFile.close();

    return 0;*/
}
/*
void menu(Graph*& bankSystem, string& line, int bucketSize)
{
    string command;
    string subString;
    int data;
    bankAccount* account;
    istringstream iss(line);

    iss>> command;
    if(iss.fail()) return;

    if(bankSystem == NULL) //efoson dn exei dimiourgithei to grafima na dimiourgithei
    {
        bankSystem = new Graph(bucketSize);
    }

    if(command == "createnodes")
    {
        while(true)
        {
            iss >> subString;
            if(!iss) break;

            data = atoi(subString.c_str());
            if(data == 0 ) continue; //error
            account = new bankAccount(data);
            if(bankSystem->insertBankAccount(account))
            {
                cout<<"success: created "<<data<<endl;
            }
            else
            {
                delete account;
                cout<<"error: creating "<<data<<endl;
            }

        }
    }
    else if(command == "delnodes")
    {
        while(true)
        {
            iss >> subString;
            if(!iss) break;

            data = atoi(subString.c_str());
            if(data == 0 ) continue; //error

            if(bankSystem->deleteBankAccount(data))
            {
                cout<<"success: deleted "<<data<<endl;
            }
            else
            {
                cout<<"error: deleting "<<data<<endl;
            }
        }

    }
    else if(command == "addtran")
    {
        string id1, id2;
        int account1, account2;
        double weight;
        iss >> id1 >> id2 >> subString;
        if(!iss)
        {
            cout<<"error command"<<endl;
        }
        else
        {
            account1 = atoi(id1.c_str());
            account2 = atoi(id2.c_str());
            weight = atof(subString.c_str());
            if(account1 == 0 || account2 == 0 || weight == 0)
            {
                cout<<"error command"<<endl;
            }
            else
            {
                if (bankSystem->addEdge(account1, account2, weight))
                {
                    cout<<"success: add transaction "<<account1<<" "<<account2<<" with "<<weight<<endl;
                }
                else
                {
                    cout<<"error: add transaction, account doesnt exists"<<endl;
                }
            }
        }
    }
    else if(command == "deltran")
    {
        string id1, id2;
        int account1, account2;
        iss >> id1 >> id2;
        if(!iss)
        {
            cout<<"error command"<<endl;
        }
        else
        {
            account1 = atoi(id1.c_str());
            account2 = atoi(id2.c_str());
            if(account1 == 0 || account2 == 0)
            {
                cout<<"error command"<<endl;
            }
            else
            {
                if (bankSystem->deleteEdge(account1, account2))
                {
                    cout<<"success: deleted transaction "<<account1<<" "<<account2<<endl;
                }
                else
                {
                    cout<<"error: deleted transaction, account doesnt exists"<<endl;
                }
            }
        }
    }
    else if(command == "lookup")
    {
        string id;
        double result;
        iss >> subString >> id;
        if(!iss)
        {
            cout<<"error command"<<endl;
        }
        else
        {
            data = atoi(id.c_str());
            if(data == 0 )
            {
                cout<<"error command"<<endl;
                return;
            }

            if(subString == "in")
            {
                result = bankSystem->inWeight(data);
                if(result < 0)
                {
                    cout<<"error: out, account doesnt exists"<<endl;
                }
                else
                {
                    cout<<"success: in("<< data<<") = "<<result<<endl;
                }
            }
            else if(subString == "out")
            {
                result = bankSystem->outWeight(data);
                if(result < 0)
                {
                    cout<<"error: out, account doesnt exists"<<endl;
                }
                else
                {
                    cout<<"success: out("<< data<<") = "<<result<<endl;
                }

            }
            else if(subString == "sum")
            {
                bool error;
                result = bankSystem->totalWeight(data, error);
                if(error == true)
                {
                    cout<<"error: sum, account doesnt exists"<<endl;

                }
                else
                {
                    cout<<"success: sum("<< data<<") = "<<result<<endl;

                }

            }
            else
            {
                cout<<"error command"<<endl;
            }
        }
    }
    else if(command == "triangle")
    {
        string id;
        int account;
        double weight;

        iss >> id>>subString;
        if(!iss)
        {
            cout<<"error command"<<endl;
        }
        else
        {
            account = atoi(id.c_str());
            weight = atof(subString.c_str());
            if(account == 0 || weight == 0)
            {
                cout<<"error command"<<endl;
            }
            else
            {
                bankSystem->triangle(account, weight);
            }
        }
    }
    else if(command == "conn")
    {
        string id1, id2;
        int account1, account2;

        iss >> id1>>id2;
        if(!iss)
        {
            cout<<"error command"<<endl;
        }
        else
        {
            account1 = atoi(id1.c_str());
            account2 = atoi(id2.c_str());
            if(account1 == 0 || account2 == 0)
            {
                cout<<"error command"<<endl;
            }
            else
            {
                bankSystem->connectionPath(account1, account2);
            }
        }
    }
    else if(command == "allcycles")
    {
        iss >> subString;
        if(!iss)
        {
            cout<<"error command"<<endl;
        }
        else
        {
            data = atoi(subString.c_str());
            if(data == 0)
            {
                cout<<"error command"<<endl;
            }
            else
            {
                bankSystem->cycles(data);
            }
        }
    }
    else if(command == "traceflow")
    {
        string id;
        int account;

        iss >> id>>subString;
        if(!iss)
        {
            cout<<"error command"<<endl;
        }
        else
        {
            account = atoi(id.c_str());
            data = atoi(subString.c_str());
            if(account == 0)
            {
                cout<<"error command"<<endl;
            }
            else
            {
                bankSystem->traceflow(account, data);
            }
        }
    }
    else if(command == "bye")
    {
        delete bankSystem;
        cout<<"success: cleaned memory"<<endl;
        bankSystem = NULL;
    }
    else if(command == "print")
    {
        bankSystem->printGraph();
    }
    else if(command == "dump")
    {
        ofstream writeFile;
        iss >> subString;
        if(!iss)
        {
            writeFile.open("dump.txt");
        }
        else
        {
            writeFile.open(subString.c_str());
        }

        bankSystem->writeGraph(writeFile);
        writeFile.close();
        cout<<"success: dumped to file"<<endl;
    }
    else
    {
        cout<<"error no command"<<endl;
    }
}
*/
