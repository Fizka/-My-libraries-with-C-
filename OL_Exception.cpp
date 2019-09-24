#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include "OL_Exception.h"

using namespace std;

/**
Funckcja, ktora wypisuje nam komunikat dla danego bledu.
*/
void OF_SeeTypesExceptions(EXCEPTION_CODE error){
	
	switch (error) {
	case EXCEPTION_CODE::EmptyError:
		cerr << "Dane nie zostaly wpisane do zmiennej! ";
		break;
	case EXCEPTION_CODE::OpenError:
		cerr << "Blad otwarcia pliku do zapisu! ";
		break;
	case EXCEPTION_CODE::SaveError:
		cerr << "Dane nie zostaly zapisane do pliku! ";
		break;
	case EXCEPTION_CODE::UnderZiro:
		cerr << "Wartosc wpisana jest ujemna! ";
		break;
	case EXCEPTION_CODE::OutRange:
		cerr << " Wartos jest spoza przedzialu! ";
		break;
	case EXCEPTION_CODE::FileName:
		cerr << "Podales za dluga nazwe! ";
		break;
	default:
		cerr << "Nieznany blad";
		break;
	}
}

/**
Funkcja sprawdza czy plik do zapisu dobrze sie otworzyl .
@para filename - nazwa pliku
@para out - strumien do zapisu pliku
*/
void OF_ExceptionCheckFileToSave(string filename, ofstream & out) {

	out.open(filename);
	if (!(out.good())) {
		throw EXCEPTION_CODE::OpenError;
	}
	out.close();

}

/**
Funkcja sprawdza czy plik do wypisu dobrze sie otworzyl .
@para filename - nazwa pliku
@para in - strumien do odczytu pliku
*/
void OF_ExceptionCheckFileToRead(string filename, ifstream & in) {

	in.open(filename);
	if (!in.good()) {
		throw EXCEPTION_CODE::OpenError;
	}
	in.close();

}

/**
Funkcja sprawdza czy dane sa wpisane do pliku.
@para filename - nazwa pliku
*/
void OF_SaveFileChecker(string filename) {

	ifstream in;
	in.open(filename);
	string line;
	cin >> line;
	if (line == "") {
		throw EXCEPTION_CODE::SaveError;
	}
	in.close();

}

/**
Funkcja sprawdza czy dynamicznie zalokowana tablica nie posiada pustych miejsc.
*@para myCreatedArray - tablica Struktur z dwiema wartosciami - prawdopodobientwem i nazwa
*@para columns - rozmiar tablicy
*/
template <typename  Type>
void OF_EmptyCheckerTemplate(Type & myCreatedArray, int columns) {

	for (int i = 0; i < columns; i++)
	{
		if (myCreatedArray[i] = NULL)
			throw EXCEPTION_CODE::EmptyError;
	}

}

/*
funckja sprawdza czy wartosci podane nie sa  ponizej zera.
*@para myCreatedArray - tablica Struktur z dwiema wartosciami - prawdopodobientwem i nazwa
*@para columns - rozmiar tablicy
*/
template <typename T>
void OF_UnderZiroCheckerTemplate(T & myCreatedArray, int columns) {

	for (int i = 0; i < columns; i++)
	{
		if (myCreatedArray[i] < 0)
			throw EXCEPTION_CODE::UnderZiro;
	}
}


/*
*funkcja sprawdza czy podane wartosci znajduja siê w odpowiednim przedziale.
*@para n - rozmiar tablicy
*@para Max - maksymalna wartosc jaka moze znajdmowac sie w tablicy
*@para Min - minimalna wartosc jaka moze znajdowac sie w tablicy
*@para Arr- tablica z struktur, ktora posiada nazwe i prawdopodobienstwo
*/
template <typename T>
void OF_OutOfTheRangeTemplate(T & myCreatedArray, int columns, int max, int min) {

	for (int i = 0; i < columns; i++)
	{
		if ((myCreatedArray[i] < max) || (myCreatedArray[i] > min))
			throw EXCEPTION_CODE::OutRange;
	}
}

/*
funkcja sprawdza czy nazwa nie jest za dlugo albo za krotk (czyli "").
*/
void Of_LackOfFileName(string filename) {

	if (filename.size() > 50 || filename.size() < 0)
		throw EXCEPTION_CODE::FileName;
}

