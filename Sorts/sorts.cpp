#include "sorts.h"

using namespace std;


/* Selection Sort */
void selectionSort(int array[]) { // don't need to say much about selection sort.
	for (int i = 0; i < 1000000; i++)
  	{
    	for (int j = i+1; j < 1000000; j++)
    	{
      		if (array[i] > array[j])
      		{
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      		}
    	}
  	}
};


/* QuickSort */
QuickSorter::QuickSorter(int* array, int size) : data(array), size(size) //Used to initialize variables
{
}

QuickSorter::~QuickSorter() //Destructor
{
    delete[] data;
}

void QuickSorter::sort() //Public method for sorting the QuickSorter's data
{
    this->quickSort(0, size); //Initial Quick Sort
}

void QuickSorter::quickSort(int left, int right)
{
    if (left < right)
    {
        int pivotPoint = (left + right) / 2;
        int nextPivotPoint = partitionData(left, right, pivotPoint);
        quickSort(left, nextPivotPoint - 1); // Sort recursively down on the left side
        quickSort(nextPivotPoint + 1, right);	// Sort recursively down on the right side
    }
}



int QuickSorter::partitionData(int left, int right, int pivotPoint)
{
    int pivotData = data[pivotPoint];
    while (left < right)
    {
        while (data[left] < pivotData)
        {
            left++;
        }
        while (data[right] > pivotData)
        {
            right--;
        }
        if (left < right && data[left] != data[right])
        {
            swap(data[left], data[right]);
        }
        else
        {
            return right;
        }
    }
    return right;
}



/* MergeSort */
void merge(int a[], const int low, const int mid, const int high)
{
    // Variables declaration. 
    int * b = new int[high+1-low];
    int h,i,j,k;
    h=low;
    i=0;
    j=mid+1;
    // Merges the two array's into b[] until the first one is finish
    while((h<=mid)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    // Completes the array filling in it the missing values
    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h;k<=mid;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    // Prints into the original array
    for(k=0;k<=high-low;k++) 
    {
        a[k+low]=b[k];
    }
    delete[] b;
}


void merge_sort( int a[], const int low, const int high )       // Recursive sort ...
{
    int mid;
    if( low < high )
    {
        mid = ( low + high ) / 2;
        merge_sort( a, low, mid );
        merge_sort( a, mid + 1, high );
        merge( a, low, mid, high );
    }
}


/* HeapSort */
Heap::Heap(){
    for(int i = 0; i <= 1000000; i ++){
        items[i] = 0;
    }
    items[0] = -1;
    this->n = 0;
}

int Heap::get_parent(int k){
    return (int)(k / 2);
}

int Heap::get_left_child(int k){
    return 2*k;
}

int Heap::get_right_child(int k){
    return 2*k + 1;
}

void Heap::bubble_up(int pos){
    int k = this->items[pos];
    if(k != -1){ //if have not hit root yet
        int parent_ind = get_parent(pos);
        int parent = this->items[parent_ind];
        if(k < parent){
            //swap k with parent
            this->items[parent_ind] = k;
            this->items[pos] = parent;
            bubble_up(parent_ind);
        }
    }
}

void Heap::insert(int k){
    this->n ++;
    this->items[this->n] = k; //add new item to rightmost leaf of heap
    bubble_up(this->n);
}


void Heap::bubble_down(int pos){
    int k = this->items[pos];
    int min_child_pos;
    int left_pos = get_left_child(pos);
    int right_pos = get_right_child(pos);
    if(left_pos <= this->n || right_pos <= this->n){
        if(left_pos <= this->n && right_pos <= this->n){
            int left_val = this->items[left_pos];
            int right_val = this->items[right_pos];
            if(left_val < right_val){
                min_child_pos = left_pos;
            }
            else{
                min_child_pos = right_pos;
            }
        }
        else if(left_pos <= this->n){
            min_child_pos = left_pos;
        }
        else if(right_pos <= this->n){
            min_child_pos = right_pos;
        }
        if(k > this->items[min_child_pos]){
            this->items[pos] = this->items[min_child_pos];
            this->items[min_child_pos] = k;
            bubble_down(min_child_pos);
        }
    }
}


int Heap::extract_min(){
    int min = -1;
    if(this->n > 0){
        min = this->items[1];
        int rightmost = this->items[this->n];
        this->items[1] = rightmost;
        this->n --;
        bubble_down(1);
    }
    return min;
}


void Heap::make_heap(int array[], int length){
    for(int i = 0; i < length; i ++){
        insert(array[i]);
    }
}


void Heap::heapsort(int array[], int length){
    make_heap(array, length);
    for(int i = 0; i < length; i ++){
        array[i] = extract_min();
    }
}