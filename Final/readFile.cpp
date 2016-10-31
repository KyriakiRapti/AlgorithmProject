#include "readFile.h"
#include "Node.h"
#include <sstream>
#include <bitset>
#include "lsh.h"

using namespace std;


int readFile(ifstream& inFile, string& type, List<Vector*>* myList1, List<Hamming*>* myList2, List<MatrixPoint*>* myList3)
{
    string line;
    //ifstream inFile;
    string name, tag;
    double value;

    if(inFile.is_open() && (inFile)) //eisodos apo arxeio efoson yparxei
    {
        if(!getline(inFile, line)) return 1;// error sto read
        istringstream iss(line);

        iss>> tag >> type;
        if(!iss) return 1;
        if(tag != "@metric_space") return 1; //perimenoume auto to tag

        if(type == "vector" || type == "euclidean") //euclidean to afairw einai mono gia to arxeio pou dwthhke
        {
            if(!getline(inFile, line)) return 1;// error sto read

            istringstream iss(line);
            iss>> tag;
            if(!iss) return 1;
            if(tag=="@metric")
            {
                iss>> type;
                if(!iss) return 1;
                if(type !="euclidean" && type !="cosine") return 1; //lathos dedomena
                line = ""; //dn pira seira me dedomena
            }
            else
            {
                type ="euclidean";
            }
            //List<Vector*>* tmpList = new List<Vector*>();
            readVectorFile(inFile, line, myList1);
            /*for(Node<Vector*>*i = myList1->get_begin(); i != NULL; i =i->get_next())
            {
                cout<<i->get_data()->get_coordinance(1)<<endl;
            }*/

            //
            //lshCosine(tmpList, NULL, 5, 4, 0);
            //klhsh lsh gia vector
            //cout<<type<<endl;
        }
        else if(type == "hamming")
        {
            bitset<64> f;
            //List<Hamming*>*tmpList = new List<Hamming*>();
            readHammingFile(inFile, myList2);
            /*for(Node<Hamming*>* i = myList2->get_begin(); i !=NULL; i = i->get_next())
            {
                i->get_data()->get_bitString(f);
                cout<<f<<endl;
            }*/
        }
        else if(type == "matrix")
        {
            //List<MatrixPoint*>* myList = new List<MatrixPoint*>();
            readMatrixFile(inFile, myList3);


            //for(Node<MatrixPoint*>* i = myList->get_begin(); i !=NULL; i = i->get_next())

            MatrixPoint* d = myList3->get_begin()->get_data();
            /*for(int i=0;i< d->get_noItems(); i++)
            {
                cout<<d->get_distance(i)<<endl;
            }*/


        }
        else //error
        {
        //getline(inFile, line);
        //getline(inFile, line);
//cout<<line;
            return 1;
        }
    }
    return 0;
}

void readVectorFile(ifstream& inFile, string& line, List<Vector*>* myList)
{
    string name;
    double value;
    bool knowDimensions = false;
    List<double>* tmpList = new List<double>();
    double* myArray;
    int i, dimensions;
    Vector* data;

    if(line == "")
    {
        if(!getline(inFile, line)) return; //diavazw mia grammh
    }

    do
    {
        istringstream iss(line);

        iss>> name;
        i=0;
        while(true)
        {
            iss>>value;
            if(!iss) break;

            if(knowDimensions == false)
            {
                tmpList->insertEnd(value);
            }
            else
            {
                if(i >= dimensions) return ; //dn einai idies diastaseis
                myArray[i]=value;
                i++;
            }
        }

        if(knowDimensions == false)
        {
            myArray = new double[tmpList->getSize()];
            dimensions = tmpList->getSize();
            for(int i=0; i<dimensions; i++)
            {
                myArray[i] = tmpList->deleteFirstNode();
            }
            delete tmpList;

            knowDimensions = true;
        }

        data = new Vector(name, dimensions, myArray);
        myList->insertEnd(data);
        //cout<<dimensions<<endl;

    }while(getline(inFile, line));

    delete myArray;
}

void readHammingFile(ifstream& inFile, List<Hamming*>* myList)
{
    string line, name;
    Hamming* data;
    bitset<64> value;

    while(getline(inFile, line))
    {
        //cout<<line<<endl;
        istringstream iss(line);

        iss>> name >> value; //to value tha einai 64 bit
        if(!iss) return;

        data= new Hamming(name, value);
        myList->insertEnd(data);
    }
}


void readMatrixFile(ifstream& inFile, List<MatrixPoint*>* myList)
{
    //jagged array ennalaktika
    string line, name, commaLine;
    int value, i, items;
    int* tempArray;
    List<string> itemIds;
    MatrixPoint* point;

    if(!getline(inFile, line)) return;
    istringstream iss(line);
    iss >> name;
    if(!iss) return;

    if(name != "@items") return;

    while(getline(iss, name, ','))
    {

        itemIds.insertEnd(name);
    }
    items = itemIds.getSize();
    tempArray = new int[items];
    while(getline(inFile, line))
    {
        //cout<<line<<endl;
        i = 0;
        istringstream iss(line);
        for(int i = 0; i < items; i++)
        {
            iss>>value;
            if(!iss) return; //diavastikan ligotera exoume kapoio error

            tempArray[i] = value;
        }
        point = new MatrixPoint(itemIds.get_begin()->get_data(), tempArray, items);
        itemIds.deleteFirstNode(); //afairoume to stoixeio apo thn lista
        myList->insertEnd(point);
    }

    delete tempArray;
}

bool readMatrixQuery(std::ifstream& inFile, List<MatrixPoint*>* queryList)
{
    string name, line;
    MatrixPoint* data;
    int value, counter = 0;
    int* tmpArray;
    //bitset<64> value;

    if(!getline(inFile, line)) return false;
    istringstream iss(line);
    iss>>name;
    while(true) //metrame to plithos twn apostasewn
    {
        iss>> value;
        if(!iss) break;
        counter++;
    }
    tmpArray = new int[counter];

    do
    {
        istringstream iss(line);
        iss>>name;
        for(int i= 0; i <counter; i++)
        {
            iss>>value;
            if(!iss) return false;
            tmpArray[i] = value;
        }

        data = new MatrixPoint(name, tmpArray, counter);
        queryList->insertEnd(data);
    }while(getline(inFile, line));

    delete[] tmpArray;
    return true;
}

bool readRadius(std::ifstream& inFile, double& radius)
{
    string line, name;
    if(inFile.is_open() && (inFile)) //eisodos apo arxeio efoson yparxei
    {
        if(!getline(inFile, line)) return false;// error sto read
        istringstream iss(line);

        iss>> name >> radius;
        if(!iss) return 1;
        if(name != "Radius:") return false; //perimenoume auto to tag
    }

}
