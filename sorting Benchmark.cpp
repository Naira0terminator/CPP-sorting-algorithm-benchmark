#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#include "random.hpp"
#include "timer.hpp"
#include "sorting functions.h"


using Random = effolkronium::random_static;

std::vector<int> createArray(int arrayLength = 250)
{
	std::vector<int> array;
	array.reserve(arrayLength);

	for (int i = 0; i < arrayLength; i++)
	{
		int element = Random::get(1, arrayLength * 5);
		array.emplace_back(element);
	}

	return array;
}

void error(std::string msg)
{
	system("CLS");
	std::cerr << msg << '\n';
	system("PAUSE");
	std::exit(1);
}

void printArray(std::vector<int>& array)
{
	// using printf over cout for the speed
	printf("\n[");
	for (int i : array)
		printf("%d, ", i);
	printf("]\n");
}

int main()
{
	bool display;
	char yn;

	std::cout << "Do you want to Display the array(y/n): " << std::endl;
	std::cin >> yn;

	if (yn == 'y') display = true;
	else if (yn == 'n') display = false;
	else error("You must enter either y or n");

	while (true)
	{
		system("CLS");
		int arraySize;
		std::string sortType;

		std::cout << "Enter array size:\n";
		std::cin >> arraySize;

		std::cout << "Enter a sorting method (std, radix, selection, quick, heap):\n";
		std::cin >> sortType;

		std::vector<std::string> types{ "std", "radix", "selection", "quick", "heap" };

		if (!(std::find(types.begin(), types.end(), sortType) != types.end()))
			error("That is not a valid sort type");

		if (std::cin.fail())
			error("That is not a valid number");

		system("CLS");
		std::cout << "Creating array..." << std::endl;

		Timer timer1{ "Array" };

		std::vector<int> generateArray{ createArray(arraySize) };

		const auto timeElapsed{ timer1.elapsed() };

		if(display)
			printArray(generateArray);

		std::cout << "\n======== Created Array in " << timeElapsed << " seconds ========" << std::endl;

		system("PAUSE");
		system("CLS");

		std::cout << "\nSorting Array..." << std::endl;

		Timer timer2{ "Sorting" };

		if (sortType == "std")
			std::sort(generateArray.begin(), generateArray.end(), [](int x, int y) { return x < y; });
		if (sortType == "selection")
			selection(generateArray);
		if (sortType == "radix")
			radix(generateArray);
		if (sortType == "quick")
			quick(generateArray, 0, generateArray.size() - 1);
		if (sortType == "heap")
			heapSort(generateArray);

		auto timeElapsed_sort{ timer2.elapsed() };

		if(display)
			printArray(generateArray);

		std::cout << "\n======== Sorted Array in " << timeElapsed_sort << " seconds ========" << std::endl;
		system("PAUSE");
	}

	return 0;
}