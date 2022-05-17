#pragma once
#include <string>
#include <iostream>
class StandardNode
{
private:
	std::string PrintHelper(int space);

public:
	int value;
	StandardNode* left;
	StandardNode* right;

	StandardNode();
	StandardNode(int v);
	~StandardNode();

	void Insert(int v);
	void Insert(StandardNode* node);

	void Print();
};

