// InventoryItems.h
#ifndef PROJECT_THREE_HEADER_FILE_INVENTORY_ITEMS_H
#define PROJECT_THREE_HEADER_FILE_INVENTORY_ITEMS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

class InventoryItems {

public:

	// Function to read items from a file
	void readItemsFromFile(const string& fileName);

	// Function to create a data file with item frequencies
	void createDataFile(const string& fileName);

	// Menu Option One: Search for an Item
	void searchForItem(const string& item);

	// Menu Option Two: Display all frequencies
	void displayAllFrequencies();

	// Menu Option Three: Print Histogram
	void printHistogram();

	// Function to print the menu
	void PrintMenu();

	// Function to handle the main menu options
	void MainMenuOptions(int userChoiceVar, bool& exitRequest);


private:
	// This map to store item frequencies
	map<string, int> itemFrequencyMap;

};


#endif //PROJECT_THREE_HEADER_FILE_INVENTORY_ITEMS_H