#include <math.h>
#include <limits>
#include "lsh.h"
#include <ctime>

using namespace std;

template <class T>
LSH<T>::LSH(std::string Type, List<T>* Input,  int L1, int K1):L(L1), K(K1)
{

}

template <>
LSH<Hamming*>::LSH(std::string Type, List<Hamming*>* Input, int L1, int K1): L(L1), K(K1)
{
    const int noBuckets = pow(2, K);
    const int noBits = 64;
    HashFunction<Hamming*>* hashFunct;

    type  = Type;
    input = Input;
    //searchList = Search;
    //radius = r;

    hashtables = new HashTable<Hamming*>*[L]; //kayaskeuazoume ena pinaka apo listes
    for(int i = 0; i < L; i++) //kataskeuazoume L hashtable
    {
        hashFunct = new HashFunction<Hamming*>(K, noBits);
        hashtables[i] = new HashTable<Hamming*>(noBuckets, hashFunct);
    }
}
//sthn eukleidia tha kanw nea lista kai meta delete ston destructor

template <>
LSH<Vector*>::LSH(std::string Type, List<Vector*>* Input, int L1, int K1):L(L1), K(K1)
{
    const int noBuckets = pow(2, K);
    const int dimensions = Input->get_begin()->get_data()->get_dimensions();
    HashFunction<Vector*>* hashFunct;

    type  = Type;
    input = Input;
    //searchList = Search;
    //radius = r;
//cout<<"t"<<endl;
    hashtables = new HashTable<Vector*>*[L]; //kayaskeuazoume ena pinaka apo listes
    for(int i = 0; i < L; i++) //kataskeuazoume L hashtable
    {
        hashFunct = new HashFunction<Vector*>(K, dimensions);
        hashtables[i] = new HashTable<Vector*>(noBuckets, hashFunct);
    }

    /*for(Node<Vector*>* i = input->get_begin(); i != NULL; i = i->get_next()) //vazoyme kathe stoixeio se ola ta hashtable pou ftiaksame
    {
        for(int j = 0; j < L; j++)
        {
            hashtables[j]->insertNode(i->get_data());
        }
    }*/

}

template <class T>
LSH<T>::~LSH()
{
    for(int i =0; i < L; i++)
    {
        delete hashtables[i]->getHashFunction();
        delete hashtables[i];
    }
    delete []hashtables;
}

template<class T>
void LSH<T>::runLSH(std::ofstream& outFile, List<T>* Search, double radius)
{
    double aproxDistance, trueDistance;
    T aproxNear;
    T trueNear;
    List<T>* result= new List<T>();
    clock_t begin, end;
    double LSHTime, BruteTime;

    for(Node<T>* i = input->get_begin(); i != NULL; i = i->get_next()) //vazoyme kathe stoixeio se ola ta hashtable pou ftiaksame
    {
        for(int j = 0; j < L; j++)
        {
            hashtables[j]->insertNode(i->get_data());
        }
    }

    for(int i = 0; i < L; i++) //kataskeuazoume L hashtable
    {
        hashtables[i]->printSizeOfBuckets();
        cout<<endl;
    }
    //return;


    for(Node<T>* i = Search->get_begin(); i != NULL; i = i->get_next())
    {
        rangeSearch(i->get_data(), result, radius); //anazhthsh R geitonwn
        begin = clock();
        aproxDistance = AproxNN(i->get_data(), aproxNear);  //aproximate dn xreiazetai, xreaizetai eksantitikh anazhthsh
        end = clock();
        LSHTime = (double)(end-begin)/CLOCKS_PER_SEC;
        begin = clock();
        trueDistance = TrueNN(i->get_data(), trueNear);
        end = clock();
        BruteTime = (double)(end-begin)/CLOCKS_PER_SEC;
        //cout<<aproxDistance<<" "<< trueDistance<<endl;
        writeFile(outFile, i->get_data(), result, aproxNear, aproxDistance, trueDistance, LSHTime, BruteTime);  //nearVector = NNCosine(hashtables, key, L, nearDistance, input->getSize());//anazhthsh kontinoterou, mazoume megistes sigkriseis ola ta stoixeia

        //grapsimo se arxeio
        while(result->deleteFirstNode() != NULL) //adeiazw thn lista
        {
        }
    }

}

template<class T>
void LSH<T>::writeFile(std::ofstream& outFile, T queryPoint, List<T>* rangeNeigtbours, T aproxVector, double aproxDistance,  double trueDistance, double LSHTime, double bruteTime)
{
    outFile << "Query: " << queryPoint->get_string()<<endl;
    outFile << "R-near neighbors:"<<endl;
    for(Node<T>* i = rangeNeigtbours->get_begin(); i != NULL; i = i->get_next())
    {
        outFile<<i->get_data()->get_string()<<endl;
    }

    outFile << "Nearest neighbor: "<<aproxVector->get_string()<<endl;
    outFile << "DistanceLSH: "<<aproxDistance<<endl;
    outFile << "DistanceTrue: "<<trueDistance<<endl;
    outFile << "tLSH: "<< LSHTime<<endl;
    outFile << "tTrue: " << bruteTime<<endl;
    outFile<<endl;
    //outFile << "DistanceTrue: "<<aproxDistance<<endl;
    //outFile << "tLSH: "<<aproxDistance<<endl;
    //outFile << "tTrue: "<<aproxDistance<<endl;
}

template <class T>
void LSH<T>::rangeSearch(T key, List<T>* result, double radius)
{
    List<T>* tmpList = new List<T>();

    for(int i = 0; i < L; i++)
    {
        for(Node<T>* j = hashtables[i]->get_bucket(key); j != NULL; j =j->get_next())
        {
            if(elementExists(tmpList, j->get_data())) continue;
            tmpList->insertEnd(j->get_data());

            if(distance(j->get_data(), key) < radius)
            {
                result->insertEnd(j->get_data());
            }
        }
    }

    delete tmpList;
}

template <class T>
double LSH<T>::TrueNN(T key, T& aproxNear) //returns nearest distance
{
    double minDistance = std::numeric_limits<double>::max();
    double tmpDistance;

    for(Node<T>*i = input->get_begin(); i != NULL; i = i->get_next())
    {
        tmpDistance = distance(i->get_data(), key);

        if(tmpDistance < minDistance)
        {
            minDistance = tmpDistance;
            aproxNear = i->get_data();
        }
    }

    return minDistance;
}

template <class T>
double LSH<T>::AproxNN(T key, T& aproxNear) //returns nearest distance
{
    T minElement = 0;// = NULL;
    double minDistance = std::numeric_limits<double>::max();
    double tmpDistance;
    int totalItems = 0;
    List<T>* tmpList = new List<T>();

    for(int i = 0; i < L; i++)
    {
        for(Node<T>* j = hashtables[i]->get_bucket(key); j != NULL; j =j->get_next())
        {
            if(elementExists(tmpList, j->get_data())) continue;

            tmpList->insertEnd(j->get_data()); //to vazw oti to elenksa

            totalItems++;
            if(totalItems > 3*L) //gia to approximate telos twn sigrisewn
            {
                aproxNear = minElement;
                delete tmpList;
                return minDistance;
            }

            tmpDistance = distance(j->get_data(), key);
            if(tmpDistance < minDistance)
            {
                //cout<<tmpDistance<<" "<<j->get_data()->get_string()<<endl;
                minElement = j->get_data();
                minDistance = tmpDistance;
            }
        }
    }

    //distance = minDistance;
    delete tmpList;
    aproxNear= minElement;
    return minDistance;
}

template <class T>
bool LSH<T>::elementExists(List<T>* tmpList, T key)
{
    for(Node<T>* i = tmpList->get_begin(); i!= NULL; i = i->get_next()) //pairnw ta stoixeia pou exoun elengthei
    {
        if(i->get_data() == key)
        {
            return true;
        }
    }

    return false;
}

template<class T>
double LSH<T>::distance(Vector* point1, Vector* point2)
{
    if(point1->get_dimensions() != point2->get_dimensions()) return 0;// error

    double innerProduct = 0, lengthPoint1 = 0, lenghtPoint2 =0;

    for(int i =0; i < point1->get_dimensions(); i++)
    {
        innerProduct += point1->get_coordinance(i)*point2->get_coordinance(i); //vriskw eswteriko ginomeno

        lengthPoint1 += pow(point1->get_coordinance(i), 2); //metro tou point1
        lenghtPoint2 += pow(point2->get_coordinance(i), 2); //metro tou point2
    }
   return 1- innerProduct/(sqrt(lengthPoint1) * sqrt(lenghtPoint2));
}

template<class T>
int LSH<T>::distance(Hamming* point1, Hamming* point2)
{
   	int distance=0;
   	bitset<64> str1;
   	bitset<64> str2;

   	point1->get_bitString(str1);
   	point2->get_bitString(str2);

	for(int i=0;i<64;i++)
	{
		if(str1[i]!=str2[i])
		{
			distance++;
		}
	}

	return distance;
}

/*

void lshCosine(List<Vector*>* input, List<Vector*>* searchList, int L, int K, double radius)
{
    ofstream fileOut("test666.txt");
    const int noBuckets = pow(2, K);
    const int dimensions = input->get_begin()->get_data()->get_dimensions();
    HashTableCosine** hashtables;
    hashtables = new HashTableCosine*[L]; //kayaskeuazoume ena pinaka apo listes
    for(int i = 0; i < L; i++) //kataskeuazoume L hashtable
    {
        hashtables[i] = new HashTableCosine(noBuckets, K, dimensions);
    }

    for(Node<Vector*>* i = input->get_begin(); i != NULL; i = i->get_next()) //vazoyme kathe stoixeio se ola ta hashtable pou ftiaksame
    {
        for(int j = 0; j < L; j++)
        {
            hashtables[j]->insertNode(i->get_data());
        }
    }

    for(int i = 0; i < L; i++) //kataskeuazoume L hashtable
    {
        hashtables[i]->printSizeOfBuckets();
        cout<<endl;
    }
    //return;
    List<Vector*>* result= new List<Vector*>();
    double aproxDistance, nearDistance;
    Vector* aproxVector;
    Vector* nearVector;
    for(Node<Vector*>* i = searchList->get_begin(); i != NULL; i = i->get_next())
    {

        rangeSearchCosine(hashtables, i->get_data(), L, radius, result); //anazhthsh R geitonwn
        cout<<"F"<<endl; aproxVector = NNCosine(hashtables, i->get_data(), L, aproxDistance, 3*L);  //aproximate dn xreiazetai, xreaizetai eksantitikh anazhthsh

        writeFileCosine(fileOut, i->get_data(), result, aproxVector, aproxDistance, 0);  //nearVector = NNCosine(hashtables, key, L, nearDistance, input->getSize());//anazhthsh kontinoterou, mazoume megistes sigkriseis ola ta stoixeia

        //grapsimo se arxeio
        while(result->deleteFirstNode() != NULL) //adeiazw thn lista
        {
        }
    }



}

void writeFileCosine(ofstream& outFile, Vector* queryPoint, List<Vector*>* rangeNeigtbours, Vector* aproxVector, double aproxDistance, double nearDistance)
{
    outFile << "Query: " << queryPoint->get_string()<<endl;
    outFile << "R-near neighbors:"<<endl;
    for(Node<Vector*>* i = rangeNeigtbours->get_begin(); i != NULL; i = i->get_next())
    {
        outFile<<i->get_data()->get_string()<<endl;
    }

    outFile << "Nearest neighbor: "<<aproxVector->get_string()<<endl;
    outFile << "DistanceLSH: "<<aproxDistance<<endl;
    //outFile << "DistanceTrue: "<<aproxDistance<<endl;
    //outFile << "tLSH: "<<aproxDistance<<endl;
    //outFile << "tTrue: "<<aproxDistance<<endl;
}
/*void rangeSearchCosine(HashTableCosine** hashtables, Vector* key, int L, double radius, List<Vector*>* result)
{
    for(int i = 0; i < L; i++)
    {
        for(Node<Vector*>* j = hashtables[i]->get_bucket(key); j != NULL; j =j->get_next())
        {
            if(distanceCosine(j->get_data(), key) < radius)
            {
                result->insertEnd(j->get_data());
            }
        }
    }
}

Vector* NNCosine(HashTableCosine** hashtables, Vector* key, int L, double& distance, int maxChecks)
{
    Vector* minVector = NULL;
    double minDistance = std::numeric_limits<double>::max();
    double tmpDistance;
    int totalItems = 0;

    for(int i = 0; i < L; i++)
    {
        for(Node<Vector*>* j = hashtables[i]->get_bucket(key); j != NULL; j =j->get_next())
        {
            totalItems++;
            if(totalItems > maxChecks) //gia to approximate telos twn sigrisewn
            {
                distance = minDistance;
                return minVector;
            }
            tmpDistance = distanceCosine(j->get_data(), key);
            if(tmpDistance < minDistance)
            {
                //cout<<tmpDistance<<" "<<j->get_data()->get_string()<<endl;
                minVector = j->get_data();
                minDistance = tmpDistance;
            }
        }
    }

    distance = minDistance;
    return minVector;

}


double distanceCosine(Vector* point1, Vector* point2)
{
    if(point1->get_dimensions() != point2->get_dimensions()) return 0;// error

    double innerProduct = 0, lengthPoint1 = 0, lenghtPoint2 =0;

    for(int i =0; i < point1->get_dimensions(); i++)
    {
        innerProduct += point1->get_coordinance(i)*point2->get_coordinance(i); //vriskw eswteriko ginomeno

        lengthPoint1 += pow(point1->get_coordinance(i), point1->get_dimensions()); //metro tou point1
        lenghtPoint2 += pow(point2->get_coordinance(i), point1->get_dimensions()); //metro tou point2
    }
    /*cout<<point1->get_string()<<" "<<point2->get_string()<<endl;
    cout<<innerProduct<<" "<<lengthPoint1<<" "<<lenghtPoint2<<endl;
    cout<<pow(lengthPoint1, 1/point1->get_dimensions()) <<endl;*/
  //  return 1- innerProduct/(pow(lengthPoint1, 1.0/point1->get_dimensions()) * pow(lenghtPoint2, 1.0/point2->get_dimensions()));
//}

template class LSH<Vector* >;
template class LSH<Hamming* >;
//template class LSH<EuclideanNode* >;
//template class LSH<MatrixPoint* >;
