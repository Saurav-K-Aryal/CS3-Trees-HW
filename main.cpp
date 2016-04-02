#include "trees.h"
#include <time.h>
#include <algorithm>    // random_shuffle
#include <vector>       // vector
#include <ctime>        // time
#include <cstdlib>      // rand, srand

using namespace std;

// Driver program to test above functions

int myrandom (int i) { return rand()%i;}

int main()
{
    cout << "\n-------------------------------------------------------------------\n";


  srand(unsigned(time(0)));
  vector<int> myvector;

  cout << "Initializing a random vector with 1 million values";

  cout << endl << "Values are unique and inclue 1 and 1 million" << endl;
  // set some values:
  for (int i=1; i<=1000000; i++) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using built-in random generator:
  random_shuffle ( myvector.begin(), myvector.end() );

  // using myrandom:
  random_shuffle ( myvector.begin(), myvector.end(), myrandom);

  cout << '\n';
 //initializing two clock variables to measure execution time.
    clock_t t1,t2;
   cout << "---------------------------------------------------------------\n";
   /* For 2-3 B Tree */
   cout << "\nFor a 2-3 B Tree\n\n";
    cout << "Inserting unique values from 1 to 1,000,000 randomly\n";

    // start clock
    t1 = clock();

    BTree Bt(3); 
    
 for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it) {
    Bt.insert(*it);
}
    t2 = clock();         // end clock

    float time_diff = ((float)t2-(float)t1);

    // converting the time to seconds before console printing
    // CLOCKS_PER_SEC is a macro from the time library
    cout << "Net time taken for insert:(in seconds) " << time_diff / CLOCKS_PER_SEC << endl << endl;


    // deleting values in the same order:

    cout << "\nDeleting values from 1 to 1,000,000 serially in ascending order\n";

    t1 = clock();

 for (int i = 1; i <= 1000000; i++) {
    Bt.remove(i);
}
    t2 = clock();         // end clock

    time_diff = ((float)t2-(float)t1);

    // converting the time to seconds before console printing
    // CLOCKS_PER_SEC is a macro from the time library
    cout << "net time taken for delete:(in seconds) " << time_diff / CLOCKS_PER_SEC << endl;

   cout << "**********************************************************************\n";
    /* For BinarySearch Tree */    

    cout << "For a BinarySearch Tree\n\n";
    cout << "Inserting unique values from 1 to 1,000,000 randomly\n";

    // start clock
    t1 = clock();

	BinarySearchTree bst;

   for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it) {
    bst.insert(*it);
}
    t2 = clock();         // end clock

    time_diff = ((float)t2-(float)t1);

    // converting the time to seconds before console printing
    // CLOCKS_PER_SEC is a macro from the time library
    cout << "Net time taken for insert:(in seconds) " << time_diff / CLOCKS_PER_SEC << endl;


    // deleting values in the same order:

    cout << "\nDeleting values from 1 to 1,000,000 serially in ascending order\n";

    t1 = clock();

    for (int i = 1; i <= 1000000; i++ ){
    	bst.remove(i);
    }

    t2 = clock();         // end clock

    time_diff = ((float)t2-(float)t1);

    // converting the time to seconds before console printing
    // CLOCKS_PER_SEC is a macro from the time library
    cout << "Net time taken for delete:(in seconds) " << time_diff / CLOCKS_PER_SEC << endl;


    cout << "\n**********************************************************************\n";

    return 0;
}