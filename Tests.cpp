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

void Tests::Test2(int size, int resolution, int repeats) {
	srand(time(0));
	std::cout << "Runnging Test2\n";
	int increment = size / resolution;
	std::string suffix;
	suffix += std::to_string(size) + "_r" + std::to_string(resolution) + "_c" + std::to_string(OurNode::cValue).substr(0, 3);
	std::string ourName = "T2_our_s" + suffix;
	std::string stdName = "T2_std_s" + suffix;
	DynamicDataHandler ourDH(ourName);
	DynamicDataHandler stdDH(stdName);

	for (int r = 0; r < repeats; r++) {
		std::cout << "Running iteration " << r << "/" << repeats << std::endl;
		OurTree oT;
		StandardTree sT;
		for (int i = 0; i < size; i += increment) {
			int completeness = 100 * i / size;
			std::cout << completeness << "%" << std::endl;

			int randval = rand() % size;
			auto start = high_resolution_clock::now();
			oT.Insert(randval);
			auto middle = high_resolution_clock::now();
			sT.Insert(randval);
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
	std::cout << "Test2 complete!\n";
}

void Tests::Test3(int size, int resolution, int repeats) {
	std::cout << "Runnging Test3\n";
	int increment = size / resolution;
	std::string suffix;
	suffix += std::to_string(size) + "_r" + std::to_string(resolution) + "_c" + std::to_string(OurNode::cValue).substr(0, 3);
	std::string ourName = "T3_our_s" + suffix;
	std::string stdName = "T3_std_s" + suffix;
	DynamicDataHandler ourDH(ourName);
	DynamicDataHandler stdDH(stdName);

	for (int r = 0; r < repeats; r++) {
		std::cout << "Running iteration " << r << "/" << repeats << std::endl;
		for (int step = 0; step < size; step += increment) {
			std::cout << 100 * step / size << "%" << std::endl;
			OurTree oT;
			StandardTree sT;
			auto oStart = high_resolution_clock::now();
			for (int i = 0; i < step; i++) {
				oT.Insert(i);
			}
			auto oStop = high_resolution_clock::now();
			auto sStart = high_resolution_clock::now();
			for (int i = 0; i < step; i++) {
				sT.Insert(i);
			}
			auto sStop = high_resolution_clock::now();

			auto ourDuration = duration_cast<microseconds>(oStop - oStart);
			auto stdDuration = duration_cast<microseconds>(sStop - sStart);

			ourDH.Push(r, ourDuration.count());
			stdDH.Push(r, stdDuration.count());
		}
		std::cout << "Writing...\n";
		ourDH.Write();
		stdDH.Write();
	}
	
	std::cout << "Test3 complete!\n";
}

void Tests::Test4(int size, int resolution, int repeats) {
	srand(time(0));
	std::cout << "Runnging Test4\n";
	int increment = size / resolution;
	std::string suffix;
	suffix += std::to_string(size) + "_r" + std::to_string(resolution) + "_c" + std::to_string(OurNode::cValue).substr(0, 3);
	std::string ourName = "T4_our_s" + suffix;
	std::string stdName = "T4_std_s" + suffix;
	DynamicDataHandler ourDH(ourName);
	DynamicDataHandler stdDH(stdName);

	for (int r = 0; r < repeats; r++) {
		for (int step = 0; step < size; step += increment) {
			OurTree oT;
			StandardTree sT;

			// generate random numbers before measuring
			std::vector<int> randvals;
			for (int i = 0; i < step; i++) {
				randvals.push_back(rand() % size);
			}

			auto oStart = high_resolution_clock::now();
			for (int i = 0; i < step; i++) {
				oT.Insert(randvals[i]);
			}
			auto oStop = high_resolution_clock::now();
			auto sStart = high_resolution_clock::now();
			for (int i = 0; i < step; i++) {
				sT.Insert(randvals[i]);
			}
			auto sStop = high_resolution_clock::now();

			auto ourDuration = duration_cast<microseconds>(oStop - oStart);
			auto stdDuration = duration_cast<microseconds>(sStop - sStart);

			ourDH.Push(r, ourDuration.count());
			stdDH.Push(r, stdDuration.count());
		}
		std::cout << "Writing...\n";
		ourDH.Write();
		stdDH.Write();
	}

	std::cout << "Test4 complete!\n";
}