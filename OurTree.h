#pragma once
#include "OurNode.h"
class OurTree
{
private:
	OurNode* root;

public:
	OurTree();
	~OurTree();

	void Insert(int v);
	void Balance();
	void Print();
	void PrintSize();

	static OurTree* TreeFromRandom(int size);
	static OurTree* TreeFromSorted(int size);
	static OurTree* TreeFromArr(int* arr, int size);
};

