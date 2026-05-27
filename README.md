# Data Structures: Stacks and Queues

This repository contains two tasks merged into a single interactive console application, demonstrating the use of Custom Linked List and Array-based Data Structures in C++.

## Project Structure
* `ArrayStack.h`: Array-based stack template (used for Task 2).
* `LinkedStack.h`: Linked list-based stack template (used for Task 1).
* `LinkedQueue.h`: Linked list-based queue template (used for Task 1).
* `Tasks.h` / `Tasks.cpp`: Declarations and implementations for the specific task logic.
* `main.cpp`: The interactive menu system.

## Requirements

### Task 1: Number Processing (Linked Lists)
Consider the following statements:
```cpp
linkedStack<int> stack;
linkedQueue<int> queue;
int num;

```

Suppose the input is `28 30 15 11 10 -9 21 8 -3 33 17 14`; write a C++ program that processes these numbers as follows:

* If the number is even, it is pushed onto the stack.
* If the number is odd and divisible by 3, it is added to the queue.
* Otherwise, the top element, if any, of the stack is removed, and the square of the number is added to the stack.

*Constraint:* Use header files for stacks and queues implemented as a linked list.

### Task 2: Arithmetic Expression Matcher (Array)

Write a program that takes an arithmetic expression as input. The program outputs whether the expression contains matching grouping symbols `()`, `{}`, and `[]`.

* Examples of valid expressions: `{25 + (3 - 6) * 8}` and `7 + 8 * 2`
* Example of invalid expression: `5 + {(13 + 7) / 8 - 2 * 9`
* The `;` symbol will act as the terminator.

*Hint:* Every item in the arithmetic expression is a character. Use the `cin.get(ch)` command to obtain every character. Use the concept of stacks to evaluate if the grouping symbols are present.
*Constraint:* Implement this using the header file of stack as an array-based list.