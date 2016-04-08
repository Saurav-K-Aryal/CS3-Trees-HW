#include "sorts.h"


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
            std::swap(data[left], data[right]);
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