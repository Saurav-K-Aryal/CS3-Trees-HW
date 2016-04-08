#include <iostream>

void selectionSort(int array[]);


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
