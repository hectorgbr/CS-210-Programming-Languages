/*
 * Corner Grocer App
 * Date: 12/10/2023
 * Author: Hector Banos Ramos
 * This is a item-tracking program for the Corner Grocer
 */

// Main_Project_Three.cpp
#include <iostream>
#include <iomanip>
#include "InventoryItems.h"
#include <limits>  // for numeric_limits

using namespace std;

int main() {
    // Variable declaration
    int userChoiceVar;
    bool exitRequest = false;
    // This variable is the name of the text file in the project folder
    string fileName = "CS210_Project_Three_Input_File.txt";

    // Dynamically allocate an instance of the InventoryItems class
    InventoryItems* inventory = new InventoryItems();

    // This function reads items from the file
    inventory->readItemsFromFile(fileName);

    // This function creates a file at the beginning of the program execution
    inventory->createDataFile("frequency.dat");

    // Main program loop
    while (!(exitRequest)) {
        // The option menu is printed until the user selects the exit option
        inventory->PrintMenu();

        // This try/catch block helps validate user input
        try {
            // Prompt the user for input and validate it
            cout << "Enter your choice (1-4): ";
            cin >> userChoiceVar;

            // Check for invalid input
            if (cin.fail()) {
                throw runtime_error("Invalid input. Please enter a number.");
            }

            // Check if the choice is within the valid range
            if (userChoiceVar < 1 || userChoiceVar > 4) {
                throw runtime_error("Invalid choice. Please enter a number between 1 and 4.");
            }

            // Execute the selected menu option
            inventory->MainMenuOptions(userChoiceVar, exitRequest);

        }
        catch (const exception& e) {
            // This line handles exceptions related to user input
            cerr << "Error: " << e.what() << endl;
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        }
    }

    // This line deletes the allocated memory before exiting
    // to avoid memory leaks
    delete inventory;

    return 0;
}
