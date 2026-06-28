#include <iostream>
#include <string>
#include "GroceryTracker.h"
using namespace std;

int main() {
	GroceryTracker groceryTracker;
	int menuChoice;
	string searchItem;

	// Load item data from the input file
	
	groceryTracker.LoadItemsFromFile("CS210_Project_Three_Input_File.txt");

	// Create backup file automatically at the beginning of the program
	
	groceryTracker.WriteBackupFile("C:\\Users\\Administrator\\source\\repos\\CornerGrocer\\x64\\Debug\\frequency.dat");


	do {
		cout << endl;
		cout << "==== Corner Grocer Item Tracking Menu ====" << endl;
		cout << "1. Search for an item frequency" << endl;
		cout << "2. Display all item frequencies" << endl;
		cout << "3. Display item frequencies histogram" << endl;
		cout << "4. Exit program" << endl;
		cout << "Enter your choice: ";
		cin >> menuChoice;

		cout << endl;

		switch (menuChoice) {
		case 1:
			cout << "Enter the item you wish to search for: ";
			cin >> searchItem;
			cout << searchItem << " appears "
				<< groceryTracker.GetItemFrequency(searchItem)
				<< " time(s). " << endl;
			break;

		case 2:
			groceryTracker.PrintAllFrequencies();
			break;

		case 3:
			groceryTracker.PrintHistogram();
			break;

		case 4:
			cout << "Thank you for the Corner Grocer tracking program. Goodbye!" << endl;
			break;

		default:
			cout << "Invalid menu option. Please enter a number from 1 to 4." << endl;
			break;

		}

	} while (menuChoice != 4);

	return 0;
}
