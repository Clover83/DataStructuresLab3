#pragma once
#include "OurTree.h"
#include "StandardTree.h"
#include "DynamicDataHandler.h"
#include <chrono>

class Tests
{
public:
	/// <summary>
	/// Insertion time comparison for single insertions, sorted numbers
	/// </summary>
	/// <param name="n"></param>
	static void Test1(int size, int resolution, int repeats);

	/// <summary>
	/// Insertion time comparison for series of insertions, sorted numbers
	/// </summary>
	/// <param name="initialSize"></param>
	/// <param name="numberOfInsertions"></param>
	/// <param name="repeats"></param>
	static void Test2(int initialSize, int numberOfInsertions, int repeats);

};