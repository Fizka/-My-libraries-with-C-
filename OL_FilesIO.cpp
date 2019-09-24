#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include "OL_FilesIO.h"
#include "OL_Exception.h"

using namespace std;

/**
* Tworzenie dynamicznej dwuwymiarowej tablicy.
*
* @param rows - wiersze
* @param  columns -kolumny
* @return dynamiczna tablica dwuwymiarowa.

*/
template <typename T >
T **OF_ArrayTwoDimensionsCreation(int columns, int  rows) {

	T **MyCreatedArray = nullptr;
	try
	{
		MyCreatedArray = new T*[columns];
	}
	catch (bad_alloc)
	{
		cout << "An array was not created. " << endl;
		exit(0);
	}
	for (int i = 0; i < columns; i++)
	{
		try
		{
			MyCreatedArray[i] = new T[rows];
		}
		catch (bad_alloc)
		{
			cout << "An array was not created. " << endl;
			exit(0);
		}
	}
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			MyCreatedArray[i][j] = 0;
		}
	}

	return MyCreatedArray;
}

/**
* Tworzenie dynamicznej tablic jednowymiarow¹.
*
* @param  columns -kolumny
* @return dynamiczna tablica jednowymiarowa.
*/
template <typename Type>
Type * OF_ArrayOneDimensionCreation(int columns) {

	Type *MyCreatedArray = nullptr;
	try
	{
		MyCreatedArray = new Type[columns];
	}
	catch (bad_alloc)
	{
		cout << "An array was not created." << endl;
		Of_Exit();
	}
	for (int j = 0; j < columns; j++)
	{
		MyCreatedArray[j] = 0;
	}

	return MyCreatedArray;
}

/**
* Funkcja sluzaca do delokacji zalokowanej pamiêci tablicy dwuwymiarowej
*
* @param MyCreatedArray - tablica do zniszczenia - dwuwymiarowa
* @param columns -  kolumny
*/
template <typename Type>
void OF_ArrayTwoDimensionsDestruction(Type & MyCreatedArray, int columns){

	for (int i = 0; i < columns; i++)
	{
		delete[] MyCreatedArray[i];
	}

	delete[] MyCreatedArray;
}

/**
* Wypelnianie dynamicznej dwuwymiarowej tablicy.
*
* @param columns - kolumny
* @param rows - wiersze
* @param MyCreatedArray - tablica do wypelnienia
*/
template <class Type>
void OF_ArrayTwoDimensionsInsertion(int columns, int rows, Type & MyCreatedArray){

	for (int i = 0; i<columns; i++)
	{
		for (int j = 0; j<rows; j++)
		{
			cin >> MyCreatedArray[i][j];
		}
	}

}

/**
*  Wypelnianie dynamicznej jednowymiarowej tablicy.
*
* @param  columns - kolumny
* @param  MyCreatedArray - tablica do wypelnienia
*/
template <class Type>
void OF_ArrayOneDimensionInsertion(int columns, Type & myCreatedArray){

	for (int j = 0; j<columns; j++)
	{
		cin >> myCreatedArray[j];
	}

}

/**
*Funckja wychodzi z prograuw  w razie bledu
*/
void OF_Exit(){

	cin.ignore();
	getchar();
	exit(0);
}

/**
* Funkcja sprawdzajaca czy plik istnieje
*
* @param fileName - nazwa pliku
* @return true - plik istnieje, false - plik nie istnieje
*/
bool OF_CheckFile(string filename){

	ifstream newfile;
	newfile.open(filename, fstream::in | fstream::out | fstream::app);
	if (!newfile)
		return false;
	else
		return true;

}

/**
* Funkcja przypisujaca do nazwy pliku rozszerzenie - "txt"
*
* @param filename - nazwa pliku
* @return nazwa pliku z rozszerzeniem txt
*/
string OF_AddFilenameExtension(string filename){

	if (filename[filename.size()-1] != 't')
	{
		std::string j = ".txt";
		filename += j;
		return filename;
	}
	else
	{
		return filename;
	}

}

/**
* Funkcja sluzaca do zapisu tablicy liczb
*
* @param 
* @param columns - kolumny
* @param rows -  wiersze
*/
template <typename type>
void OF_SaveToFile(type & ArrayToSave, int columns, int rows){

	string filename;
	cin >> filename;
	filename = OF_AddFilenameExtension(filename);
	ofstream newFile;

	try {
		
		newFile.open(filename, fstream::in | fstream::out | fstream::app);
		OF_ExceptionCheckFileToSave(fileName, files);
	}
	catch (EXCEPTION_CODE error)
	{
		Of_seeExceptions(error);
		Of_Exit();
	}

	if (newFile.good())
	{
		for (int i = 0; i < colums; i++)
			for (int j = 0; j < rows; j++)
				newFile << ArrayToSave;
	}

	try {
		newFile.close();
		Of_SaveFilesChecker(filename);

	}
	catch (EXCEPTION_CODE error)
	{
		Of_seeExceptions(error);
		Of_Exit();
	}

}


/**
* Wyczyszczenie pliku. Zapobieganie nawarstwianiu sie danych po kolejnych przejsciach
*/
void OF_DeleteDataFromFile(string filename)
{
	ofstream file(filename);
	file.open(filename, ofstream::out | ofstream::trunc);
	file.close();
}





