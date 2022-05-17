#include "StandardTree.h"

StandardTree::StandardTree() {
	root = nullptr;
}

StandardTree::~StandardTree() {
	delete root;
}

void StandardTree::Insert(int v) {
	if (root == nullptr) {
		root = new StandardNode(v);
		return;
	}
	root->Insert(v);
}

void StandardTree::Print() {
	root->Print();
}

// Static methods, generators etc
StandardTree* StandardTree::TreeFromRandom(int size) {
	srand(time(0));
	StandardTree* tree = new StandardTree();
	for (int i = 0; i < size; i++) {
		tree->Insert(rand() % size);
	}
	return tree;
}

StandardTree* StandardTree::TreeFromSorted(int size) {
	srand(time(0));
	StandardTree* tree = new StandardTree();
	for (int i = 0; i < size; i++) {
		tree->Insert(i);
	}
	return tree;
}

StandardTree* StandardTree::TreeFromArr(int* arr, int size) {
	srand(time(0));
	StandardTree* tree = new StandardTree();
	for (int i = 0; i < size; i++) {
		tree->Insert(arr[i]);
	}
	return tree;
}