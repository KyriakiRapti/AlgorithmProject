#ifndef Included_ReadFile_H
#define Included_ReadFile_H

#include <iostream>
#include <fstream>
#include "List.h"
#include "dataTypes.h"

int readFile(std::ifstream& inFile, std::string& type, List<Vector*>* myList1, List<Hamming*>* myList2, List<MatrixPoint*>* myList3);
void readVectorFile(std::ifstream& inFilem, std::string& line, List<Vector*>* myList);
void readHammingFile(std::ifstream& inFile, List<Hamming*>* myList);
void readMatrixFile(std::ifstream& inFile, List<MatrixPoint*>* myList);

bool readMatrixQuery(std::ifstream& inFile, List<MatrixPoint*>* queryList);

bool readRadius(std::ifstream& inFile, double& radius);

#endif
