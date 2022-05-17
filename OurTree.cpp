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