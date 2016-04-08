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


/* Radix Sort */

void radixSort(int* a, int N){
    const int INT_BIT_SIZE = sizeof(int)*8, RADIX = 0x100, MASK = RADIX-1, MASK_BIT_LENGTH = 8;
    int *result = new int[N](), *buckets = new int[RADIX](), *startIndex = new int[RADIX]();
    int flag = 0;
    bool hasNeg = false;
    while (flag < INT_BIT_SIZE){
        for (int i = 0; i < N; i++) {
            const int key = ((((a[i] & (MASK << flag)) >> flag)<0) && (hasNeg = true))? //assigns hasNeg to true if and only if first condition is false
                            ((a[i] & (MASK << flag)) >> flag)+MASK : (a[i] & (MASK << flag)) >> flag;
            ++buckets[key];
        }
        startIndex[0] = 0;
        for (int j = 1; j < RADIX; j++) startIndex[j] = startIndex[j - 1] + buckets[j - 1];
        for (int i = N-1; i >= 0; i--){
            const int key = (((a[i] & (MASK << flag)) >> flag)>=0)?
                            (a[i] & (MASK << flag)) >> flag : ((a[i] & (MASK << flag)) >> flag)+MASK;
            result[startIndex[key] + --buckets[key]] = a[i];
        }
        memcpy(a,result,N*sizeof(int));
        flag += MASK_BIT_LENGTH;
    }
    if(hasNeg){
        int indexOfNeg = 0;
        for (int i = 0; i < N; i++) {
            if(a[i] < 0) {
                indexOfNeg = i;
                break;
            }
        }
        memcpy(a,result+indexOfNeg,(N-indexOfNeg)*sizeof(int));
        memcpy(a+(N-indexOfNeg),result,indexOfNeg*sizeof(int));
    }
    delete[] result;
    delete[] buckets;
    delete[] startIndex;
}


/* Insertion Sort */


void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int x = array[i];
        int j = i;
        while (j > 0 && array[j-1] > x)
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = x;
    }
}


/* Bucket Sort */

void bucketSort (int arr[], int n)
{
  //Here range is [1,100]
  int m = 1000001;
 
  //Create m empty buckets
  int buckets[m];
 
  //Intialize all buckets to 0
  for (int i = 0; i < m; ++i)
    buckets[i] = 0;
 
  //Increment the number of times each element is present in the input
  //array. Insert them in the buckets
  for (int i = 0; i < n; ++i)
    ++buckets[arr[i]];
 
  //Sort using insertion sort and concatenate 
  for (int i = 0, j = 0; j < m; ++j)
    for (int k = buckets[j]; k > 0; --k)
      arr[i++] = j;
}



/* Bubble Sort */

void bubbleSort(int a[], int dim) 
{
    for(int ma = dim - 1; ma > 0; ma--)
    { 
         for(int i = 0; i < dim - 1 ;i++)
         {
             if(a[i] > a[i + 1])
            {
                 int tmp = a[i];
                 a[i] = a[i + 1];
                 a[i + 1] = tmp;
            }
         }
    }
}