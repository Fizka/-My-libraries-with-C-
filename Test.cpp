#include <random>
#include <iostream>

using namespace std; 

void OF_SortTablicy(int number); 
void OF_RandomOrganize(int *array, int number); 
void OF_GrowinglyOrganize(int *array, int number); 
void OF_DescendingOrganize(int *array, int number); 
void OF_AlmostGrowinglyOrganize(int *array, int number); 
void OF_PrintArray(int *array, int number); 

int main() {

	return 0; 
}

void OF_SortTablicy(int number)
{
	int NumberOfvalue, NumberOfRandomValue; 
	cout << " Wielkosc tablicy do zapelnienia to : " << number << endl;
	int * Array = new int[number];

	cout << "Ile liczb bedziesz wprowadzac? " << endl;
	cin >> NumberOfvalue;
	cout << "Ile liczb bedziesz losowal? " << endl;
	cin >> NumberOfRandomValue;

	if (0 != NumberOfvalue)
	{
		for (int i = 0; i < NumberOfvalue; i++)
		{
			cin >> Array[i];
		}
	}

	int rang1, rang2;
	if (0 != NumberOfRandomValue)
	{
		cout << "Prosze podac zakres" << endl
			<< " Od : " << endl;
		cin >> rang1;
		cout << " Do : " << endl;
		cin >> rang2;

		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<int>dist(rang1, rang2);

		cout << "Twoj numer " << NumberOfvalue << endl;
		for (int i = NumberOfvalue; i < (NumberOfRandomValue + NumberOfvalue); i++)
		{
			int RandomNumber = dist(mt);
			Array[i] = RandomNumber;
		}

	}

	if ((NumberOfRandomValue + NumberOfvalue) != number)// w przypadku, kiedy uzytkowni po wpisaniu i wylosowaniu liczb nie zapelni³ tablicy 
	{
		int Difference = NumberOfRandomValue + NumberOfvalue;

		cout << " Za malo liczb wprowadziles! " << endl
			<< " wprowadz jeszcze " << number - Difference << endl;
		for (Difference; Difference < number; Difference++)
		{
			cin >> Array[Difference];
		}
	}

}

/**
* Funkcja ktora uporzadkowuje losowo ( stan uporzadkowania tablicy )
*/
void OF_RandomOrganize(int *array, int number) {

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int>dist(0, number);
	int indeks, temp;

	for (int i = 0; i<number + 1; i++)
	{
		indeks = dist(mt);
		temp = array[i];
		array[i] = array[indeks];
		array[indeks] = temp;
	}

}

/**
* Funckja ktora uporzadkowuje rosnaco (stan uporzadkowania tablicy)
*/
void OF_GrowinglyOrganize(int *array, int number){

	for (int i = 0; i<number + 1; i++)
		for (int j = 0; j<number + 1; j++)
			if (array[j]>array[j + 1])
				swap(array[j], array[j + 1]);
}

/**
* Funkcja, ktora daje nad uporzadkowane dane  ( stan uporzadkowania tablicy )
*/
void OF_DescendingOrganize(int *array, int number){

	for (int i = 0; i<number + 1; i++)
		for (int j = 0; j<number + 1; j++)
			if (array[j]<array[j + 1])
				swap(array[j], array[j + 1]);
}

/**
* Funkcja, ktora prawie uporzadkowuje dane  ( stan uporzadkowania tablicy )
*/
void OF_AlmostGrowinglyOrganize(int *array, int number){

	for (int i = 0; i<number + 1; i++)
		for (int j = 0; j<number + 1; j++)
			if (array[j]>array[j + 1])
				swap(array[j], array[j + 1]);

	int NumberOfChange = number / 10;

	if (NumberOfChange < 1)
		NumberOfChange = 2;

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int>dist(0, number);

	int indeksconst = 0, temp;

	for (int i = 0; i < NumberOfChange; i++)
	{
		int indeks = dist(mt);
		temp = array[indeksconst];
		array[indeksconst] = array[indeks];
		array[indeks] = temp;
		indeksconst = indeks;
	}
}

/**
* Funkcja, ktora wypisuje liczby z tablicy.
*/
void OF_PrintArray(int *array, int number){

	for (int i = 0; i < number; i++)
		cout << array[i] << " ";
	cout << endl;
}

