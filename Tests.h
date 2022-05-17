#pragma once
#include "OurTree.h"
#include "StandardTree.h"
#include "DynamicDataHandler.h"
#include <chrono>

class Tests
{
public:
	/// <summary>
	/// Non-culmulative insertion time comparison for single insertions, sorted numbers
	/// </summary>
	/// <param name="n"></param>
	static void Test1(int size, int repeats);

	/// <summary>
	/// Non-culmulative insertion time comparison for single insertions, random numbers
	/// </summary>
	/// <param name="initialSize"></param>
	/// <param name="numberOfInsertions"></param>
	/// <param name="repeats"></param>
	static void Test2(int size, int repeats);

	/// <summary>
	/// TOTAL insertion time for a series of insertions, sorted numbers
	/// </summary>
	/// <param name="size"></param>
	/// <param name="resolution"></param>
	/// <param name="repeats"></param>
	static void Test3(int size, int resolution, int repeats);

	/// <summary>
	/// TOTAL insertion time for a series of insertions, random numbers
	/// </summary>
	/// <param name="size"></param>
	/// <param name="resolution"></param>
	/// <param name="repeats"></param>
	static void Test4(int size, int resolution, int repeats);

};