#pragma once
#include "OurNode.h"
class OurTree
{
public:
	OurNode* root;

public:
	OurTree();
	~OurTree();

	void Insert(int v);
	void Balance();
	void Print();
	void PrintSize();
};

