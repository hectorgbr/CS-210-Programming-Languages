#include <iostream>
#include "InventoryItems.h"
#include <fstream>
#include <sstream>
using namespace std;
// InventoryItems.cpp


void InventoryItems::readItemsFromFile(const string& fileName) {
    // Open the file
    ifstream inputInventoryFile(fileName);

    // Check if the file is opened successfully
    if (!inputInventoryFile.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    // Read the file line by line
    string line;
    while (getline(inputInventoryFile, line)) {
        // Process each line
        // Creates an istringstream object named iss 
        istringstream iss(line);
        // Assuming each line contains one item
        string item;
        if (iss >> item) {
            // Update the frequency map
            itemFrequencyMap[item]++;
        }
    }

    // Close the file
    inputInventoryFile.close();
}

void InventoryItems::createDataFile(const string& newfileName) {
    // Open the file for writing
    ofstream outputFile("frequency.dat");

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening file: frequency.dat" << endl;
        return;
    }

    // Write item frequencies to the file. The for loop iterates through
    // each item-frequency pair in the itemFrequencyMap
    for (const auto& pair : itemFrequencyMap) {
        // Write the item name and its frequency to the output file
        outputFile << pair.first << " " << pair.second << endl;
    }

    // Close the file
    outputFile.close();
}

// Menu Option (1): Search for an Item
void InventoryItems::searchForItem(const string& item) {
    // Use the find function of the map to search for the item
    auto itemIterator = itemFrequencyMap.find(item);

    if (itemIterator != itemFrequencyMap.end()) {
        // Item found, return its frequency
        cout << "Frequency of '" << item << "': " << itemIterator->second << endl;
    }
    else {
        cout << "Item not found" << endl;
    }
}

// Menu Option (2)
void InventoryItems::displayAllFrequencies() {
    // Iterate through the map and print each item with its frequency
    for (const auto& pair : itemFrequencyMap) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Menu Option (3)
void InventoryItems::printHistogram() {
    // Iterate through the map and print a text-based histogram
    for (const auto& pair : itemFrequencyMap) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to print the menu
void InventoryItems::PrintMenu() {
    // Display the menu options for the Corner Grocer App
    cout << "Corner Grocer App" << endl;
    cout << " 1 - Search for an Item" << endl;
    cout << " 2 - Display all the frecuencies" << endl;
    cout << " 3 - Print Histogram" << "     " << endl;
    cout << " 4 - Exit Program" << "       " << endl;
    cout << endl;
}

void InventoryItems::MainMenuOptions(int userChoiceVar, bool& exitRequest) {
    switch (userChoiceVar) {
    case 1: {
        // Menu Option One: Search for an Item
        string searchItem;
        cout << "Enter the item you wish to look for: ";
        cin >> searchItem;
        searchForItem(searchItem);
        break;
    }
    case 2: {
        // Menu Option Two: Display all frequencies
        displayAllFrequencies();
        break;
    }
    case 3: {
        // Menu Option Three: Print Histogram
        printHistogram();
        break;
    }
    case 4: {
        // This exits the program
        exitRequest = true;
        break;
    }
    
    }
}