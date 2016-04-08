#include "sorts.h"

void selectionSort(int array[]) {
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