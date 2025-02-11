# Linked Lists Implementation

This repository contains implementations of different types of linked lists in C/C++:
1. Singly Linked List
2. Doubly Linked List
3. Circular Singly Linked List
4. Circular Doubly Linked List

## Introduction
A linked list is a linear data structure consisting of nodes. Each node contains data and a pointer to the next node in the sequence. Depending on the type of linked list, the structure and pointer behavior vary.

## Types of Linked Lists

### 1. Singly Linked List (SLL)
- Each node contains:
  - Data
  - A pointer to the next node
- Operations:
  - Insert at the beginning, middle, or end
  - Delete a node by value or position
  - Search for an element
  - Traverse the list
- The last node points to `NULL`.

### 2. Doubly Linked List (DLL)
- Each node contains:
  - Data
  - A pointer to the next node
  - A pointer to the previous node
- Operations:
  - Insert at the beginning, middle, or end
  - Delete a node by value or position
  - Search for an element
  - Traverse forward and backward
- The first node's previous pointer is `NULL`, and the last node's next pointer is `NULL`.

### 3. Circular Singly Linked List (CSLL)
- Similar to Singly Linked List, but the last node points to the first node instead of `NULL`.
- Operations:
  - Insert at any position
  - Delete a node
  - Traverse the list (loop until reaching the first node again)

### 4. Circular Doubly Linked List (CDLL)
- Similar to Doubly Linked List, but:
  - The first node's previous pointer points to the last node.
  - The last node's next pointer points to the first node.
- Operations:
  - Insert at any position
  - Delete a node
  - Traverse forward and backward in a circular manner
## Installation
Clone this repository:
```bash
https://github.com/Biraj-Bhatta/Linked_List.git

