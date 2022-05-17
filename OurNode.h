#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

class OurNode
{
private:
	// Does not check for balance
	std::vector<OurNode*> InsertRaw(OurNode* node);
	std::string PrintHelper(int space, bool printSize);

	OurNode* BalanceHelper(std::vector<OurNode*>& nodes, int start, int end);

public:
	static float cValue;

	OurNode* previous;
	OurNode* right;
	OurNode* left;
	int value;
	int size;

	OurNode();
	OurNode(int v);
	~OurNode();

	void Insert(int value);
	
	OurNode* Balance();
	std::vector<OurNode*> GetSorted();

	int GetHeight();
	OurNode* GetRoot();
	void Print(bool printSize);
};

