#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <bitset>
using namespace std;
#include "hashtable.h"
#include <cmath>
#include "Node.h"
#include "dataTypes.h"
#include "psedoRandomNumbers.h"

#include "lsh.h"
//#include "List.h"
//#include "Car.h"
//#include "bankAccount.h"
//#include <stdlib.h>
//#include "graph.h"
#include "hashTableCosine.h"
#include "readFile.h"
#include <stdlib.h>
#include <time.h>
#include "dataTypes.h"
//#include "hashNode.cpp"
#include "List.h"
//void menu(Graph*& bankSystem, string& line, int bucketSize);
#include <bitset>
#include "lsh.h"
#include <limits>

class Tr
{
    private: int x = 0;
    public:
        int get_x()
        {
            return x;
        }
};

int main(int argc, char *argv[])
{
    /*const int n= 4;
    bitset<n> foo(3);

    //cout<<foo[2]<<endl;
    HashNode<int>* t = new HashNode<int>(4, 3);

    Node<HashNode<int>* >* test = new Node<HashNode<int>* >(t);
    cout<<test->get_data()->get_data()<<endl;*/


    //readFile(inFile, type);
    /*List<Vector*>* myList = new List<Vector*>();
    List<Vector*>* myList2 = new List<Vector*>();
    double dims[2] = {1, 2};
    Vector* m = new Vector("i1", 2, dims);
    myList->insertEnd(m);
    dims[0] = 4;
    m = new Vector("i2", 2, dims);
    myList->insertEnd(m);
    dims[1] = 4;
    m = new Vector("i3", 2, dims);
    myList->insertEnd(m);
    dims[1] = 1;
    m = new Vector("i4", 2, dims);
    myList2->insertEnd(m);
    */
/*
    double dims[2] = {1, 2};

    HashFunction<EuclideanNode*>* hashFunction = new HashFunction<EuclideanNode*>(4, 2, 4, 4);
    HashTable<EuclideanNode *> Hashb(4, hashFunction);

    //Hashb->insertNode()
    int x = M;
    //cout<<x<<endl;


    Vector* m = new Vector("i1", 2, dims);
    Hashb.insertNode(new EuclideanNode(m));
    dims[0] = 4;
    m = new Vector("i2", 2, dims);
    Hashb.insertNode(new EuclideanNode(m));
    dims[1] = 4;
    m = new Vector("i3", 2, dims);
    Hashb.insertNode(new EuclideanNode(m));
    dims[1] = 1;
    m = new Vector("i4", 2, dims);

    Hashb.insertNode(new EuclideanNode(m));

    /*for(int i =0; i < 64; i++)
    {
        cout<<bitString[i]<<endl;
    }*/


/*
  Hamming* m = new Hamming("i1", bitString);//01100100
  Hashb.insertNode(m);
  bitString[0] = 1; //01100101
  m = new Hamming("i2", bitString);
  Hashb.insertNode(m);
  bitString[1] = 1; //01100111
  m = new Hamming("i3", bitString);
  Hashb.insertNode(m);
  bitString[2] = 0; //01100011
  m = new Hamming("i4", bitString);
  Hashb.insertNode(m);*/
  //bitString[2] = 1;


    //Hashb.printSizeOfBuckets();
    /*for(Node<Vector*>* i = Hashb.get_bucket(m); i!= NULL; i = i->get_next())
    {
        cout<<i->get_data()->get_string()<<endl;
    }*/
/*    for(Node<Hamming*>* i = Hashb.get_bucket(m); i!= NULL; i = i->get_next())
    {
        cout<<i->get_data()->get_string()<<endl;
    }
*/


    initialize();
    //ifstream inFile("DataHamming.csv");
    ifstream inFile("DataCosine.csv");
    ifstream queryFile("QueryEuclidean.csv");
    ofstream outFile("Test.text");
    string type;
    double radius;
    bitset<64> t;
    int L = 6, K = 6;
    //readHammingQuery(myList2, radius);
    List<Vector*>* myList1 = new List<Vector*>();
    List<Hamming*>* myList2 = new List<Hamming*>();
    List<MatrixPoint*>* myList3 = new List<MatrixPoint*>();


    /*for(Node<Hamming*>* i = myList2->get_begin(); i != NULL; i=i->get_next())
    {
        i->get_data()->get_bitString(t);
        cout<<i->get_data()->get_string()<<" "<<t<<endl;
    }*/
    cout<<"end"<<endl;
    readFile(inFile, type, myList1, myList2, myList3);

/*    for(Node<MatrixPoint*>* i=myList3->get_begin(); i != NULL; i = i->get_next())
    {
        cout<<i->get_data()->get_distance(1)<<endl;
    }

*/

    if(type =="hamming")
    {
        cout<<"hamming"<<endl;
        LSH<Hamming*>* lsh = new LSH<Hamming*>(type, myList2,  L, K);
        List<Hamming*>* queryList = new List<Hamming*>();

        readRadius(queryFile, radius);
        readHammingFile(queryFile, queryList);

        //readHammingQuery(queryFile, queryList, radius);
        //readHammingQuery(queryFile, queryList, radius);
        lsh->runLSH(outFile, queryList, radius);
    }
    else if(type == "cosine")
    {
        cout<<"cosine"<<endl;
        string line = "";
        LSH<Vector*>* lsh = new LSH<Vector*>(type, myList1,  L, K);
        List<Vector*>* queryList = new List<Vector*>();

        readRadius(queryFile, radius);
        readVectorFile(queryFile, line, queryList);

        lsh->runLSH(outFile, queryList, radius);
    }
    else if(type == "euclidean")
    {
        cout<<"euclidean"<<endl;
    }
    else if(type == "matrix")
    {
        cout<<"matrix"<<endl;
        //LSH<MatrixPoint*>* lsh = new LSH<MatrixPoint*>(type, myList3,  L, K);
        List<MatrixPoint*>* queryList = new List<MatrixPoint*>();

        readRadius(queryFile, radius);
        readMatrixQuery(queryFile, queryList);

        //lsh->runLSH(outFile, queryList, radius);
    }


//    lshCosine(myList,myList2, 5, 4, 1);
   // double me = numeric_limits<double>::max();
    //if(me < 100000)cout<<"SFSFS";
    /*initialize()
    int t[11] = {0,0,0,0,0,0,0,0,0,0};
    for(int i =0; i< 10000; i++)
    {
        cout<<randomNumberInteger()<<endl;
    }

    for(int i =0; i <11;i++)
    {
        cout<<i<<" "<<t[i]<<endl;

    }
*/
/*
initialize();
const int sizes=2;
double keyd[sizes]={100, 100};
Vector mitsos("sds", sizes, keyd);

HashFunctionCosine** tr= new HashFunctionCosine*[1000];
for(int i =0; i < 10; i++)
{
    tr[i] = new HashFunctionCosine(sizes);
    tr[i]->stats();
}
cout<<endl;

for(int i =0; i < 10; i++)
{
    cout<<tr[i]->value(&mitsos)<<endl;
}



    double anArray[sizes];// = {1, 2};
    Vector* t;// = new Cosine(2, anArray);
    int counter = 0;

    List<Vector*>* myList = new List<Vector*>();
    //HashTableCosine* hashd = new HashTableCosine(16, 4, 60);
    for(int i =0; i <1000;i++)
    {
        counter = 0;
        for(int j=0; j < sizes; j++)
        {
            anArray[j] = randomNumberDouble(0,10);
        }

        t = new Vector("f", sizes, anArray);
        for(int j =0; j <10; j++)
        {

            if(tr[i]->value(t)>0)
            {
               counter++;
            }
        }
        //cout<<counter<<endl;
        //myList->insertBeginning(t);

    }

    //cout<<hashd->hashFunction(t);*/

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
