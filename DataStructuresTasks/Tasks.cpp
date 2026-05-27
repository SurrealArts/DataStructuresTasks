#include "Tasks.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTask1() {
    LinkedStack<int> stack;
    LinkedQueue<int> queue;
    vector<int> inputs;
    string inputLine;

    cout << "\n--- Executing Task 1: Number Processing ---\n";
    cout << "Enter numbers separated by spaces and terminated by a semicolon (';').\n";
    cout << "(Press ENTER without typing anything to use the default requirements dataset): ";

    cin.ignore(10000, '\n');
    getline(cin, inputLine);

    if (inputLine.empty()) {
        inputs = { 28, 30, 15, 11, 10, -9, 21, 8, -3, 33, 17, 14 };
        cout << "\n[Info] Using default dataset...\n";
    }
    else {
        size_t semiPos = inputLine.find(';');
        if (semiPos != string::npos) {
            inputLine = inputLine.substr(0, semiPos);
        }

        stringstream ss(inputLine);
        int tempNum;
        while (ss >> tempNum) {
            inputs.push_back(tempNum);
        }
        cout << "\n[Info] Using custom dataset...\n";
    }

    if (inputs.empty()) {
        cout << "No valid numbers found. Returning to menu.\n";
        return;
    }

    cout << "\n==================================================\n";
    for (int num : inputs) {
        cout << "Processing Number : " << num << "\n";

        if (num % 2 == 0) {
            stack.push(num);
            cout << "Condition       : Even number detected.\n";
            cout << "Action          : Pushed " << num << " to Stack.\n";
        }
        else if (num % 3 == 0) {
            queue.enqueue(num);
            cout << "Condition       : Odd & divisible by 3.\n";
            cout << "Action          : Enqueued " << num << " to Queue.\n";
        }
        else {
            cout << "Condition       : Odd but NOT divisible by 3.\n";
            cout << "Action          : ";
            if (!stack.isEmpty()) {
                int removedElement = stack.top();
                stack.pop();
                cout << "Popped " << removedElement << " from Stack. ";
            }
            else {
                cout << "Stack empty (nothing popped). ";
            }
            int square = num * num;
            stack.push(square);
            cout << "Pushed square (" << square << ") to Stack.\n";
        }

        cout << "\n  --- Current Data Structure States ---\n";
        stack.display();
        queue.display();
        cout << "--------------------------------------------------\n";
    }
    cout << "Task 1 complete.\n\n";
}

void runTask2() {
    ArrayStack<char> stack;
    char ch;
    bool isMatching = true;

    cout << "\n--- Executing Task 2: Arithmetic Expression Matcher ---\n";
    cout << "Enter an arithmetic expression terminated by ';' : ";

    cin.ignore(10000, '\n');

    while (cin.get(ch) && ch != ';') {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                isMatching = false;
            }
            else {
                char topChar = stack.top();
                stack.pop();

                if ((ch == ')' && topChar != '(') ||
                    (ch == '}' && topChar != '{') ||
                    (ch == ']' && topChar != '[')) {
                    isMatching = false;
                }
            }
        }
    }

    if (!stack.isEmpty()) {
        isMatching = false;
    }

    if (isMatching) {
        cout << "\nResult: The expression contains MATCHING grouping symbols.\n";
    }
    else {
        cout << "\nResult: The expression DOES NOT contain matching grouping symbols.\n";
    }
}