#include <iostream>
#include "Tasks.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n=======================================\n";
        cout << " Data Structures: Stacks & Queues Menu \n";
        cout << "=======================================\n";
        cout << "1. Run Task 1 (Linked List Processor)\n";
        cout << "2. Run Task 2 (Array Expression Matcher)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1:
            runTask1();
            break;
        case 2:
            runTask2();
            break;
        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}