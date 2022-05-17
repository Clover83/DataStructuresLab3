#include "Tests.h"

using namespace std::chrono;
void Tests::Test1(int size, int resolution, int repeats) {
	std::cout << "Runnging Test1\n";
	int increment = size / resolution;
	std::string suffix;
	suffix += std::to_string(size) + "_r" + std::to_string(resolution) + "_c" + std::to_string(OurNode::cValue).substr(0, 3);
	std::string ourName = "T1_our_s" + suffix;
	std::string stdName = "T1_std_s" + suffix;
	DynamicDataHandler ourDH(ourName);
	DynamicDataHandler stdDH(stdName);

	for (int r = 0; r < repeats; r++) {
		std::cout << "Running iteration " << r << "/" << repeats << std::endl;
		OurTree oT;
		StandardTree sT;
		for (int i = 0; i < size; i += increment) {
			int completeness = 100 * i / size;
			std::cout << completeness << "%" << std::endl;

			auto start = high_resolution_clock::now();
			oT.Insert(i);
			auto middle = high_resolution_clock::now();
			sT.Insert(i);
			auto stop = high_resolution_clock::now();

			auto ourDuration = duration_cast<microseconds>(middle - start);
			auto stdDuration = duration_cast<microseconds>(stop - middle);

			ourDH.Push(r, ourDuration.count());
			stdDH.Push(r, stdDuration.count());
		}
		std::cout << "Writing...\n";
		ourDH.Write();
		stdDH.Write();
	}
	std::cout << "Test1 complete!\n";
}

