#include <iostream>

/* Selection Sort Protype */
void selectionSort(int array[]);


/* Quick Sort Definition */
class QuickSorter
{
public:
    QuickSorter(int* array, int size);
    void sort();
    virtual ~QuickSorter();
private:
    void quickSort(int left, int right);
    int partitionData(int left, int right, int pivotPoint);
    unsigned int size;
    int* data;
};


/* Merge Sort ProtoTypes */
void merge(int a[], const int low, const int mid, const int high);
void merge_sort( int a[], const int low, const int high);
