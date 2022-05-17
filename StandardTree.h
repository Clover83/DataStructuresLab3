#pragma once
#include "StandardNode.h"
class StandardTree
{
private:
	StandardNode* root;

public:
	StandardTree();
	~StandardTree();

	void Insert(int v);
	void Print();

	static StandardTree* TreeFromRandom(int size);
	static StandardTree* TreeFromSorted(int size);
	static StandardTree* TreeFromArr(int* arr, int size);
};