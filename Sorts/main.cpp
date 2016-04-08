#include "sorts.h"

#include <time.h>


using namespace std;

int main() {
	int arr[1000000];
    
    // initialiazing the array
	for (int i = 1000000; i > 0; i--) {
		arr[1000000 - i] = i;
	}
	
    //initializing two clock variables to measure execution time.
    clock_t t1,t2;
    
    cout << "---------------------------------------------------------------\n" << endl;
    
    
    //re-initializing the array.
    for (int i = 1000000; i > 0; i--) {
        arr[1000000 - i] = i;
    }
    
    cout << "\nPerforming Quick Sort\n\n";
    
    
    // start clock
    t1 = clock();
    
    QuickSorter sorter = QuickSorter(arr, 999999);
    
    sorter.sort();
    
    t2 = clock(); //end clock
    
    float time_diff = ((float)t2-(float)t1);
    
    cout << endl << "Net time to Sort::: " << time_diff / CLOCKS_PER_SEC << endl << endl;
    
    cout << "---------------------------------------------------------------\n" << endl;


       //re-initializing the array.
    for (int i = 1000000; i > 0; i--) {
        arr[1000000 - i] = i;
    }
    
    cout << "\nPerforming Merge Sort\n\n";
    
    
    // start clock
    t1 = clock();
    
    merge_sort(arr, 0, 999999);
    
    t2 = clock(); //end clock
    
    time_diff = ((float)t2-(float)t1);
    
    cout << endl << "Net time to Sort::: " << time_diff / CLOCKS_PER_SEC << endl << endl;
    
    cout << "---------------------------------------------------------------\n" << endl;


       //re-initializing the array.
    for (int i = 1000000; i > 0; i--) {
        arr[1000000 - i] = i;
    }
    
    cout << "\nPerforming Heap Sort\n\n";
    
    
    // start clock
    t1 = clock();
    Heap *heap = new Heap();
    heap->heapsort(arr, 999999);
    
    t2 = clock(); //end clock
    
    time_diff = ((float)t2-(float)t1);
    
    cout << endl << "Net time to Sort::: " << time_diff / CLOCKS_PER_SEC << endl << endl;
    
    cout << "---------------------------------------------------------------\n" << endl;

    
    //re-initializing the array.
    for (int i = 1000000; i > 0; i--) {
        arr[1000000 - i] = i;
    }
    
    cout << "\nPerforming Bucket Sort\n\n";
    
    
    // start clock
    t1 = clock();

    bucketSort(arr, 1000000);
    
    t2 = clock(); //end clock
    
    time_diff = ((float)t2-(float)t1);
    
    cout << endl << "Net time to Sort::: " << time_diff / CLOCKS_PER_SEC << endl << endl;
    
    cout << "---------------------------------------------------------------\n" << endl;



    //re-initializing the array.
    for (int i = 1000000; i > 0; i--) {
        arr[1000000 - i] = i;
    }
    
    cout << "\nPerforming Raidx Sort\n\n";
    
    
    // start clock
    t1 = clock();

    radixSort(arr, 1000000);
    
    t2 = clock(); //end clock
    
    time_diff = ((float)t2-(float)t1);
    
    cout << endl << "Net time to Sort::: " << time_diff / CLOCKS_PER_SEC << endl << endl;
    
    cout << "---------------------------------------------------------------\n" << endl;



        //re-initializing the array.
    for (int i = 1000000; i > 0; i--) {
        arr[1000000 - i] = i;
    }
    
    cout << "\nPerforming Bubble Sort\n\n";
    
    
    // start clock
    t1 = clock();

    bubbleSort(arr, 1000000);
    
    t2 = clock(); //end clock
    
    time_diff = ((float)t2-(float)t1);
    
    cout << endl << "Net time to Sort::: " << time_diff / CLOCKS_PER_SEC << endl << endl;
    
    cout << "---------------------------------------------------------------------\n" << endl;

    //re-initializing the array.
    for (int i = 1000000; i > 0; i--) {
        arr[1000000 - i] = i;
    }
    
    cout << "\nPerforming Insertion Sort\n\n";
    
    
    // start clock
    t1 = clock();

    insertionSort(arr, 1000000);
    
    t2 = clock(); //end clock
    
    time_diff = ((float)t2-(float)t1);
    
    cout << endl << "Net time to Sort::: " << time_diff / CLOCKS_PER_SEC << endl << endl;
    
    cout << "---------------------------------------------------------------\n" << endl;

    /* For Selection Sort */
    cout << "\nPerforming Selection Sort\n\n";

    
    // start clock
    t1 = clock();
    
    selectionSort(arr);
    
    t2 = clock(); //end clock
    
    time_diff = ((float)t2-(float)t1);
    
    cout << endl << "Net time to Sort::: " << time_diff / CLOCKS_PER_SEC << endl << endl;


    cout << "**************************************************************\n" << endl;


    return 0;
	
}