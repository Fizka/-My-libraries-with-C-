#pragma once
#ifndef OL_SORTINGALGORITHMSLIBRARY_H
#define OL_SORTINGALGORITHMSLIBRARY_H

int PartitionHoare(long * ArrayWithValue, int IndexStart, int IndexEnd);
void QuickSortWithHoaresPartition(long * ArrayWithValue, int IndexStart, int IndexEnd);
void CocktailSort(long ArrayWithValue[], int SizeOfArray);
int PartitionLomuto(long * ArrayWithValue, int IndexStart, int IndexEnd);
void QuickSortWithLomutoPartition(long * ArrayWithValue, int IndexStart, int IndexEnd); 
void Heapify(long ArrayWithValue[], int SizeOfArray, int ParentIndex);
void HeapSort(long ArrayWithValue[], int SizeOfArray); 

#endif