#pragma once
#include <vector>
#include <string>
#include <fstream>

class DynamicDataHandler
{
private:
	std::vector<std::vector<long long>> columns;
	std::string filename;
	int maxRow;
public:
	DynamicDataHandler(std::string name);

	void Push(int column, long long data);
	void Write();

};

