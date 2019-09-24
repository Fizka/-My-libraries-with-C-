#pragma once
#ifndef OL_FILES_H
#define OL_FILES_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std; 

template <typename T >
T **OF_ArrayTwoDimensionsCreation(int columns, int  rows);
template <typename Type>
Type * OF_ArrayOneDimensionCreation(int columns);
template <typename Type>
void OF_ArrayTwoDimensionsDestruction(Type & MyCreatedArray, int columns);
template <class Type>
void OF_ArrayTwoDimensionsInsertion(int columns, int rows, Type & MyCreatedArray);
template <class Type>
void OF_ArrayOneDimensionInsertion(int columns, Type & myCreatedArray);
void OF_Exit();
bool OF_CheckFile(string filename);
string OF_AddFilenameExtension(string filename); 
template <typename type>
void OF_SaveToFile(type & ArrayToSave, int columns, int rows);
void OF_DeleteDataFromFile(string filename); 

#endif