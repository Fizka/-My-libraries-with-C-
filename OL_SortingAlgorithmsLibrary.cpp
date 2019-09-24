#include <iostream>

using namespace std;

/*
Funkcja sortowania szybkiego z algorytmem podzialu Hoare.
Tablice ktora otrzymujemy dzielimy na dwa podciagi - z liczbami mniejszymi lub wiêkszymi od pewnego elementu
@para ArrayWithValue - Tablica z liczbami do posortowania
@para IndexStart - indeks poczatkowy tablicy
@para IndexEnd - Indeks koncowy tablicy
*/
int PartitionHoare(long * ArrayWithValue, int IndexStart, int IndexEnd) {

	int CompareValue = ArrayWithValue[IndexStart];
	int StartCounter = IndexStart - 1, EndCounter = IndexEnd + 1;
	while (true)
	{
		do
		{
			StartCounter++;
		} while (ArrayWithValue[StartCounter] < CompareValue);
		do
		{
			EndCounter--;
		} while (ArrayWithValue[EndCounter] > CompareValue);
		if (StartCounter >= EndCounter)
			return EndCounter;

		swap(ArrayWithValue[StartCounter], ArrayWithValue[EndCounter]);
	}

}

/*
Nastêpnie w zale¿noœci od wielkosci wynikowych podci¹gów wywo³ujemy rekurencyjnie funkcjê dla odpowiedniego podci¹gu.
Rekursjê powtarzamy tak d³ugo a¿ w wyniku otrzymamy tablicy z jednym elementem
@para ArrayWithValue - tablica z wartosciami do posortowania
@para IndexStart - indeks poczatkowy
@para IndexEnd - indeks koncowy
*/
void QuickSortWithHoaresPartition(long * ArrayWithValue, int IndexStart, int IndexEnd){

	if (IndexStart < IndexEnd)
	{
		int Part = PartitionHoare(ArrayWithValue, IndexStart, IndexEnd);
		QuickSortWithHoaresPartition(ArrayWithValue, IndexStart, Part);
		QuickSortWithHoaresPartition(ArrayWithValue, Part + 1, IndexEnd);
	}

}

/*
Algorytm do sortowania - sortowanie babelkowe wariant wahadlowy - umozliwia sortowanie tablicy
@para ArrayWithValue - tablica z wartosciami
@para SizeOfArray - rozmiar tablicy
*/
void CocktailSort(long ArrayWithValue[], int SizeOfArray){

	bool Change = true;
	int Counter = 0;
	int EndOfArray = SizeOfArray - 1;

	while (Change) {
		Change = false;
		for (int i = Counter; i < EndOfArray; ++i) {
			if (ArrayWithValue[i] > ArrayWithValue[i + 1]) {
				swap(ArrayWithValue[i], ArrayWithValue[i + 1]);
				Change = true;
			}
		}
		if (!Change)
			break;
		Change = false;
		--EndOfArray;
		for (int i = EndOfArray - 1; i >= Counter; --i) {
			if (ArrayWithValue[i] > ArrayWithValue[i + 1]) {
				swap(ArrayWithValue[i], ArrayWithValue[i + 1]);
				Change = true;
			}
		}
		++Counter;
	}
}

/*Funkcja sortowania szybkiego z algorytmem podzialu Lomuto.
Bierzemy ostatni element jako przerywnik(tzw. pivot), umieszczamy go na odpowiednim miejscu, a nastêpnie mniejsze elementy umieszczamy po lewej, a wiêksze po prawej.
Nazwy zmiennych zaadoptowane z podzia³u Hoare.
*/
int PartitionLomuto(long * ArrayWithValue, int IndexStart, int IndexEnd){

	int CompareValue = ArrayWithValue[IndexEnd];
	int StartCounter = IndexStart - 1;
	int EndCounter;
	for (EndCounter = IndexStart; EndCounter <= IndexEnd - 1; EndCounter++) {
		
		if (ArrayWithValue[EndCounter] <= CompareValue) {
			StartCounter++;
			swap(ArrayWithValue[StartCounter], ArrayWithValue[EndCounter]);
			
		}
	}
	swap(ArrayWithValue[StartCounter + 1], ArrayWithValue[IndexEnd]);

	return StartCounter++;
}

/* W zale¿noœci od wielkosci wynikowych podci¹gów wywo³ujemy rekurencyjnie funkcjê dla odpowiedniego podci¹gu.
Rekursjê powtarzamy tak d³ugo a¿ w wyniku otrzymamy tablicy z jednym elementem. */
void QuickSortWithLomutoPartition(long * ArrayWithValue, int IndexStart, int IndexEnd){

	if (IndexStart < IndexEnd) {
		int Part = PartitionLomuto(ArrayWithValue, IndexStart, IndexEnd);
		QuickSortWithLomutoPartition(ArrayWithValue, IndexStart, Part - 1);
		QuickSortWithLomutoPartition(ArrayWithValue, Part + 1, IndexEnd);
	}

}

/*Funkcja pomocnicza do sortowania sto¿kowego, porównuje wartoœci dzieci i zamienia wiêksze z rodzicem, jeœli ten jest mniejszy.
@para ArrayWithValue - tablica z wartosciami
@para SizeOfArray - rozmiar tablicy
@para ParentIndex - indeks rodzica
*/
void Heapify(long ArrayWithValue[], int SizeOfArray, int ParentIndex){

	int LargestNumber = ParentIndex;
	int LeftChildIndex = 2 * ParentIndex + 1;
	int RightChildIndex = 2 * ParentIndex + 2;

	if (LeftChildIndex < SizeOfArray && ArrayWithValue[LeftChildIndex] > ArrayWithValue[LargestNumber]) {
		LargestNumber = LeftChildIndex;

	}

	if (RightChildIndex < SizeOfArray && ArrayWithValue[RightChildIndex] > ArrayWithValue[LargestNumber]) {
		LargestNumber = RightChildIndex;
	}

	if (LargestNumber != ParentIndex) {
		swap(ArrayWithValue[ParentIndex], ArrayWithValue[LargestNumber]);
		Heapify(ArrayWithValue, SizeOfArray, LargestNumber);
	}

}


/*
Algorytm do sortowania - sortowanie kopcowe, wrzuca najwiêksz¹ wartoœæ na szczyt kopca, zamienia z wartoœci¹ umieszczon¹ pod ostatnim indeksem i nastêpne sortowanie jest o jeden indeks krótsze.
@para ArrayWithValue - tablica z wartosciami
@para SizeOfArray - rozmiar tablicy
*/
void HeapSort(long ArrayWithValue[], int SizeOfArray) {

	for (int ParentIndex = (SizeOfArray / 2) - 1; ParentIndex >= 0; ParentIndex--)
		Heapify(ArrayWithValue, SizeOfArray, ParentIndex);

	for (int ParentIndex = SizeOfArray - 1; ParentIndex >= 0; ParentIndex--) {
		swap(ArrayWithValue[0], ArrayWithValue[ParentIndex]);
		Heapify(ArrayWithValue, ParentIndex, 0);
	}

}