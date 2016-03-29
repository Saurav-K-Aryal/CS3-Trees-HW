#include "trees.h"
#include <time.h>

using namespace std;

// Driver program to test above functions


int main()
{
    //initializing two clock variables to measure execution time.
    clock_t t1,t2;

    
    /* For 2-3 B Tree */    

    cout << "For a 2-3 B Tree\n\n";
    cout << "Insert values from 1 to 1,000,000 serially in ascending order\n";

    // start clock
    t1 = clock();

    BTree Bt(3); 
    
    for (int i = 1; i <= 1000000; i++) {
        Bt.insert(i);
    }
    t2 = clock();         // end clock

    float ascending_B_tree_diff = ((float)t2-(float)t1);

    // converting the time to seconds before console printing
    // CLOCKS_PER_SEC is a macro from the time library
    cout << "net time taken for insert:(in seconds) " << ascending_B_tree_diff / CLOCKS_PER_SEC << endl;


    // deleting values in the same order:

    cout << "Delete values from 1 to 1,000,000 serially in ascending order\n";

    t1 = clock();

    for (int i = 1; i <= 1000000; i++) {
        Bt.remove(i);
    }
    t2 = clock();         // end clock

    ascending_B_tree_diff = ((float)t2-(float)t1);

    // converting the time to seconds before console printing
    // CLOCKS_PER_SEC is a macro from the time library
    cout << "net time taken for delete:(in seconds) " << ascending_B_tree_diff / CLOCKS_PER_SEC << endl;

 
    /* For Red Black Tree */    
    return 0;
}