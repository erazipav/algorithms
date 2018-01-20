#include <iostream>
#include <cstdlib>

using namespace std;

/*  THIS IS A SIMPLE PROGRAM THAT IMPLEMENTS BINOMIAL HEAP
 *  WITH BINOMIAL TREES
*/

struct Node {
	Node *parent, *leftSibling, *mostRight;
	int key;
};


void Insert(){}

void GetMin(){}

void ExtractMin(){}

void Merge(){}

void Build(){}

void DecreaseKey(){}

void IncreaseKey(){}

void Delete(){}
// ===================================================================

// merges two tree of same order together
Node* MergeTree( Node * a, Node * b ){

	Node * tmp;
	if ( a->key <= b->key ){
		tmp = b->mostRight;
		b -> mostRight = a;
		(b->mostRight) -> leftSibling = tmp;
		tmp = NULL;
		delete tmp;
		return b;
	}
	else {
		tmp = a->mostRight;
		a -> mostRight = b;
		(a->mostRight) -> leftSibling = tmp;
		tmp = NULL;
		delete tmp;
		return a;
	}

	delete tmp;

	return NULL;
}
// ===================================================================



// ===================================================================
// ===================================================================

int main () {



	return 0;
}
