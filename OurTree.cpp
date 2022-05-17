#include "OurTree.h"

OurTree::OurTree() {
	root = nullptr;
}

OurTree::~OurTree() {
	if (root != nullptr) {
		delete root;
	}
}

void OurTree::Insert(int v) {
	if (root == nullptr) {
		root = new OurNode(v);
		return;
	}
	root->Insert(v);
	root = root->GetRoot();
}

void OurTree::Print() {
	root->Print(false);
}

void OurTree::PrintSize() {
	root->Print(true);
}

void OurTree::Balance() {
	root->Balance();
	root = root->GetRoot();
}

// Static methods, generators etc
OurTree* OurTree::TreeFromRandom(int size) {
	srand(time(0));
	OurTree* tree = new OurTree();
	for (int i = 0; i < size; i++) {
		tree->Insert(rand() % size);
	}
	return tree;
}

OurTree* OurTree::TreeFromSorted(int size) {
	srand(time(0));
	OurTree* tree = new OurTree();
	for (int i = 0; i < size; i++) {
		tree->Insert(i);
	}
	return tree;
}

OurTree* OurTree::TreeFromArr(int* arr, int size) {
	srand(time(0));
	OurTree* tree = new OurTree();
	for (int i = 0; i < size; i++) {
		tree->Insert(arr[i]);
	}
	return tree;
}