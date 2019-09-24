#pragma once
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

enum EXCEPTION_CODE
{
	EmptyError,
	OpenError,
	SaveError,
	UnderZiro,
	OutRange,
	FileName
};

void Of_LackOfFileName(string filename);
void OF_SeeTypesExceptions(EXCEPTION_CODE error);
void OF_ExceptionCheckFileToSave(string filename, ofstream & out);
void OF_ExceptionCheckFileToRead(string filename, ifstream & in);
void OF_SaveFileChecker(string filename);
template <typename  Type>
void OF_EmptyCheckerTemplate(Type & myCreatedArray, int columns);
template <typename T>
void OF_UnderZiroCheckerTemplate(T & myCreatedArray, int columns);
template <typename T>
void OF_OutOfTheRangeTemplate(T & myCreatedArray, int columns, int max, int min);


#endif