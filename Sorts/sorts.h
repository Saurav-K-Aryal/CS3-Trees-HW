#include <iostream>
#include <string.h>
#include <vector>
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


/* Heap Sort Definitions */
class Heap{
    int items[1000000];
    int n;
    int get_parent(int);
    int get_left_child(int);
    int get_right_child(int);
    void bubble_up(int);
    void bubble_down(int);
    void make_heap(int [], int);
    public:
        Heap();
        void insert(int);
        int extract_min();
        void heapsort(int [], int);
};


/* Radix Sort */
void radixSort(int* a, int N);


/* Insertion Sort */
void insertionSort(int a[], int size);

/* Bucket Sort */
void bucketSort(int arr[], int n);

/* Bubble Sort */
void bubbleSort(int a[], int dim); 
