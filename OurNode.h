#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

class OurNode
{
private:
	// Does not check for balance
	void InsertRaw(OurNode* node);
	std::string PrintHelper(int space);

public:
	OurNode* previous;
	OurNode* right;
	OurNode* left;
	int value;
	int size;

	OurNode();
	OurNode(int v);
	~OurNode();

	void Insert(int value);
	
	void Balance();
	std::vector<OurNode*> GetSorted();

	int GetHeight();
	void Print();
};

