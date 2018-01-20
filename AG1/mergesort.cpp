#include <iostream>
#include <cstdlib>

using namespace std;

/* THIS PROGRAM IMPLEMETNS MERGE SORT AND IT'S METHODS, SUCH AS
 * MERGE
*/

// ===================================================================

struct Node{
	// constructor
	Node ( int a ) {
		this->key = a;
		next = NULL;
	}
	// destructor
	~Node() { delete next;}
	// attributes
	int key;
	Node *next;

};
// ===================================================================

Node * makeLinked ( int * elements, int size ) {

	return new Node(1); // !!!
}

// ===================================================================

void MergeSortLinkedList ( Node *root, int size ) {

}
// ===================================================================

void MergeSortLinkedList ( Node *root ) {

}
// ===================================================================

			/* MERGE ARRAYS */

// merges two arrays together, returns merged array
// size is size of output array, |a| + |b|
int * mergeArrays ( int *a, int *b, int size ) {

	int *outputArray = new int [size];

	int half = size/2;
	int sorted = 0;

	int indexA = 0, indexB = 0;

	// sort until all elements are sorted
	while ( indexA < half && indexB < size-half ) {
		// copy the lower element, change current A/B indexes
		if ( a[indexA] <= b[indexB] ){
			outputArray[sorted] = a[indexA];
			indexA++;
		} else {
			outputArray[sorted] = b[indexB];
			indexB++;
		}

		sorted++;
	}

	// copy the remains of unmerged array
	if ( indexA < half ){
		for ( int i = sorted; i < size; i++ ) {
			outputArray[i] = a[indexA];
			indexA++;
		}
	} 
	if ( indexB < size-half ){
		for ( int i = sorted; i < size; i++ ) {
			outputArray[i] = b[indexB];
			indexB++;
		}
	}

	return outputArray;
}

// ===================================================================

			/* MERGE SORT - arrays */

// performs recursive mergesort on an array
int * MergeSortArray ( int * elements, int size ) {

	if ( size == 1 ) return elements;
		
	// divide array into half and run merge sort on either
	int half = size/2; 		// where the array will be divided 
	int *a   = new int [half];			// |a| <= |b| 
	int *b   = new int [size-half]; 

	for ( int i = 0; i < half; i ++)
		a[i] = elements[i];

	for ( int i = half; i < size; i ++)
		b[i-half] = elements[i];

	// perform mergesort on each new arrays
	a = MergeSortArray ( a, half );
	b = MergeSortArray ( b, size-half );

	// at last, return those two merged arrays
	return mergeArrays ( a, b , size );
} 
// ===================================================================
// ===================================================================

int main(){

	int array []= {
		10, 2, 13, 4, 15, 6, 1, 1, -13, 1,
		20, 92, 8, 11, 15, 283, 11, 77, 42, 0
	};

//	Node* linkedList  = makeLinked ( array, 20 ); // will use with size
//	Node* anotherList = makeLinked ( array, 20 );	// size not known

	int * out = MergeSortArray ( array, 20 );

	cout << "Sorted array\n";
	for ( int i = 0; i < 20; i++ ) 
		cout << out[i] << " ";
	cout << endl;

//	MergeSortLinkedList	( linkedList, 20 );
//	MergeSortLinkedList ( anotherList );

	return 0;
}
