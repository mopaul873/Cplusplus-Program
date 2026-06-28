#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>
using namespace std;

class GroceryTracker {
private:
	map<string, int> itemFrequency;

public:
	void LoadItemsFromFile(string fileName);
	void WriteBackupFile(string fileName);
	int GetItemFrequency(string itemName);
	void PrintAllFrequencies();
	void PrintHistogram();
};

#endif