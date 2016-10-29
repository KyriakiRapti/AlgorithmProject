#include "readFile.h"
#include "Node.h"
#include <sstream>
#include <bitset>
using namespace std;

int readFile(ifstream& inFile, string& type)
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
                if(type !="euclidean" && type !="hamming" && type !="cosine") return 1; //lathos dedomena
                line = ""; //dn pira seira me dedomena
            }
            else
            {
                type ="euclidean";
            }
            List<Vector*>* tmpList = new List<Vector*>();
            readVectorFile(inFile, line, tmpList);
            //klhsh lsh gia vector
            cout<<type<<endl;
        }
        else if(type == "hamming")
        {
            bitset<64> f;
            List<Hamming*>*tmpList = new List<Hamming*>();
            readHammingFile(inFile, tmpList);
            for(Node<Hamming*>* i = tmpList->get_begin(); i !=NULL; i = i->get_next())
            {
                i->get_data()->get_bitString(f);
                cout<<f<<endl;
            }
        }
        else if(type == "matrix")
        {
            //readMatrixFile(inFile);
        }
        else //error
        {

            return 1;
        }
        //elenxos an to @metric_space einai vector, hamming, matrix
        //an einai vector @metric euclidean, manhattan, cosine an agnoeite tote euclidean
        //meta analoga thn periptwsh h katalhlh read
        while(getline(inFile, line))
        {
            //cout<<line<<endl;
            istringstream iss(line);

            iss>> name;
            while(true)
            {
                iss>>value;
                if(!iss) break;


            }
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

        data = new Vector(dimensions, myArray);
        myList->insertEnd(data);

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

/*
void readMatrixFile(ifstream& inFile)
{

}
*/

