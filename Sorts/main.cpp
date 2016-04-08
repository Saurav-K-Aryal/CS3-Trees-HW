#include "sorts.h"
#include <algorithm>
using namespace std;

int main() {
	int arr[1000000];

	for (int i = 1000000; i > 0; i--) {
		arr[1000000 - i] = i;
	}
	
	
}