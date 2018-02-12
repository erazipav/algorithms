#include <iostream>
#include <cstdlib>

/*  THIS IS A SIMPLE PROGRAM WITH IMPLEMENTED 'BINARY MIN HEAP' AND 
    BINARY MIN HEAP BASED HEAPSORT
*/

using namespace std;


// ===================================================================

		/* PRINT HEAP */

// use for debugging purposes
void printHeap ( int * H, int size ) {
	cout << " === HEAP ===\nSize (" << size << ")\n";
	for ( int i = 0; i < size; i++ ) 
		cout << H[i] << endl;
}

// ===================================================================

		/* BUBBLE DOWN */

// compares element with it's sons - if there are any, selects lowest
// lower son, swaps key values and continues until sons are greater

void bubbleDown( int * H, int from, int max){

	// index of element is +1 greater than in array
	int currentIndex = from;

	// while element has at least one son ( l = 2*index, r = 2*index +1 ) 
	while ( 2*currentIndex <= max ) {

		int sonIndex;				//  index of the lowest son

		// both sons exist ( r_index = 2*index + 1), choose lowest 
		if ( 2*currentIndex + 1 <= max ){

			// left is lower
			if ( H[(currentIndex*2) -1 ] < H[(currentIndex*2)] )
				sonIndex = currentIndex*2;
			// right is lower
			else
				sonIndex = currentIndex*2 + 1;

			// swap if son is lower
			if ( H[currentIndex-1] > H[sonIndex-1] ) {
				// swap
				int tmp = H[currentIndex-1];
				H[currentIndex-1] = H[sonIndex-1];
				H[sonIndex-1] = tmp;
			} 
			// end if son is equal or greater
			else return;

			currentIndex = sonIndex;
		}
		// only left son exists
		else if ( H[currentIndex-1] > H[2*currentIndex -1] ) {
				int tmp = H[currentIndex-1];
				H[currentIndex-1] = H[2*currentIndex-1];
				H[2*currentIndex-1] = tmp;
				currentIndex = 2*currentIndex;
		}
		// both are greater, terminate
		else return;
	} 
}

// ===================================================================

		/* BUBBLE UP */

// H ... heap to bubble in, index ... of an element
// for algorithm to work, indexes must be numbered from 1,2 ... n
// similar to bubbleDown

void bubbleUp (int * H, int index) {

	// index is given as a number of current element count
	int currentIndex = index;	

	// repeat until root is reached
	while ( currentIndex > 1 ) {
		// find the parent of current element, it is key/2
		// parent is saved as index, but in array it is index - 1 !!!
		int parent = currentIndex/2;

		// already reached needed position
		if ( H[parent-1] <= H[currentIndex-1]) return;

		// swap elements and continue
		int tmp 		= H[ parent -1 ];				// save index of parent
		H[ parent - 1] = H[ currentIndex -1 ]; // swap parent with son
		H[ currentIndex -1 ] = tmp;
		currentIndex 				 = parent;			// set index as parent
	}
}
// ===================================================================

		/* HEAP INSERT */

// inserts an element with key "key" into heap
// inserts on last available position and then bubles up 

void heapInsert ( int * H, int key, int * count) {

	// inserts elemnt to last available position
	H[*count] = key;

	*count 		+= 1;			// increment heap size
	bubbleUp(H,*count);	// BubbleUp element

}

// ===================================================================

		/* HEAP BUILD */

// builds a heap from unsorted array in "O(n)"

void heapBuild ( int * array, int size ) {

	for ( int i = size/2; i > 0; i-- ) {
		bubbleDown ( array, i, size); 
	}

}

// ===================================================================

		/* FIND MIN */

// return lowest element in heap

int findMin ( int * H ) {
	return H[0];
}

// ===================================================================

		/* EXTRACT MIN */

// extracts lowest value from heap and re-adjusts heap ordering

int extractMin (int * H, int * count) {

	int retval = H[0];				// min value that will be returned
	H[0] = H[ (*count) -1 ];	// swap last and first element
	*count -= 1;							// delete last element
	bubbleDown(H,1,*count);		// re-adjust heap's ordering

	return retval;
}
// ===================================================================

		/* HEAP SORT */

// sorting algorithm based on min binary heap
// builds a heap of an "unsorted" array, then extracts all elements
// into "sorted" output array

void HeapSort ( int * unsorted, int * sorted, int size) {
	heapBuild (unsorted, size);
	int remaining = size;
	for ( int i = 0; i < size; i++ ){
		sorted[i] = extractMin (unsorted, &remaining);
	}


}
// ===================================================================

		/* HEAP SORT - with preservation */

// same as heap sort, only creates extra array to preserve original one

void HeapSortPreserve ( int * unsorted, int * sorted, int size ) {

	int * tmp = new int [size];
	for ( int i = 0; i < size; i++ )
		tmp[i] = unsorted[i];

	heapBuild ( tmp, size );
	int remaining = size;
	for ( int i = 0; i < size; i++ ){
		sorted[i] = extractMin ( tmp, &remaining );
	}
	delete [] tmp;

}

// ===================================================================
// ===================================================================

int main () {
/*
	int cnt = 0;

	int heap[20];

	heapInsert(heap, 10,&cnt);
	heapInsert(heap, 3,&cnt);
	heapInsert(heap, 9,&cnt);
	heapInsert(heap, 8,&cnt);
	heapInsert(heap, 2,&cnt);
	heapInsert(heap, 19,&cnt);

	printHeap (heap,cnt);

	while ( cnt > 0 ) {
		cout << "MIN = " << extractMin (heap,&cnt) << endl;
	}


	cout << "**********\n";

	int unsorted [] = {63, 12,1, 17, 29, 10, 15};
	heapBuild(unsorted,7);
	printHeap (unsorted,7);

	int x = 7;
	while ( x > 0 ) {
		cout << "MIN " << extractMin (unsorted,&x) << endl;
	//	printHeap (heap,cnt);
	}
*/

	// array of 20 elements
	int someArray [] = 
               { 1, 9222229, 1, 78, 1,3, 2, 14, 9, 10,
                 12, 101,3,3, 5, 1 ,2, 8, 6, 0 };

	int sortedArray[20];

        // heap sort with preserving original arary
	HeapSortPreserve( someArray, sortedArray, 20 );

	for ( int i = 0; i < 20; i++ ) 
	  cout << sortedArray[i] << " ";
	cout << endl;

}
