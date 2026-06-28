#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
using namespace std;

// Reads each item from the input file and stores the frequency in a map
void GroceryTracker::LoadItemsFromFile(string fileName) {
	ifstream inputFile(fileName);
	string itemName;

	if (!inputFile.is_open()) {
		cout << "Error: Could not open input file." << endl;
		return;
	}

	while (inputFile >> itemName) {
		itemFrequency[itemName]++;
	}

	inputFile.close();
}

// Creates the backup file frequency.dat with all item frequencies
void GroceryTracker::WriteBackupFile(string fileName) {
	ofstream outputFile(fileName);

	if (!outputFile.is_open()) {
		cout << "Error: Could not create backup file." << endl;
		return;
	}

	for (const auto& item : itemFrequency) {
		outputFile << item.first << " " << item.second << endl;
	}

	outputFile.close();
}

// Returns the frequency of one specific item
int GroceryTracker::GetItemFrequency(string itemName) {
	if (itemFrequency.count(itemName) > 0) {
		return itemFrequency[itemName];
			
	}

	return 0;
}

// Prints every item with its frequency
void GroceryTracker::PrintAllFrequencies() {
	for (const auto& item : itemFrequency) {
		cout << item.first << " " << item.second << endl;
	}
}

// Prints a text-based histogram using asterisks
void GroceryTracker::PrintHistogram() {
	for (const auto& item : itemFrequency) {
		cout << item.first << " ";

		for (int i = 0; i < item.second; ++i) {
			cout << "*";
		}

		cout << endl;
	}
}