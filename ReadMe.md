# Data Structures and Algorithms

This repository contains comprehensive coverage of various Data Structures and Algorithms topics.

## Table of Contents
- [Pre-Midterm Topics](#pre-midterm-topics)
- [Midterm Topics](#midterm-topics)
- [Pre-Final Topics](#pre-final-topics)
- [Final Topics](#final-topics)

## Pre-Midterm Topics

### 1. Abstract Data Type (ADT)

### 2. ADT List
- List vs ADT List comparison
- **List Operations:**
  - Initialize
  - Insert
  - Delete
  - Member
  - Locate
  - Other operations

#### Implementations of ADT List

1. **Array Implementation** (4 versions)
   - Version 1: List as structure with array and count
   - Version 2: List as pointer to structure
   - Version 3: List as structure with dynamic array
   - Version 4: List as pointer to structure with dynamic array

2. **Linked List Implementation** (Singly Link)

3. **Cursor-based Implementation**

Time Complexity: O(1), O(N), and O(N²)

### 3. ADT Stack

#### Overview
- Stack concept and principles
- **Stack Operations:**
  - Top
  - Pop
  - Push
  - Utility functions (initStack, isEmpty, isFull)

#### Implementations
1. Array Implementation (4 versions)
2. Linked List Implementation
3. Cursor-based Implementation

Time Complexity: O(1) and O(N)

### 4. ADT Queue

#### Overview
- Queue concept and principles
- **Queue Operations:**
  - Front
  - Dequeue
  - Enqueue
  - Utility functions (initQueue, isEmpty, isFull)

#### Implementations
1. **Linked List Implementation**
   - Queue as pointer to dynamic node
   - Queue as structure with front/rear pointers

2. **Circular Array Implementation**
   - Solution 1: Counter-based
   - Solution 2: MAX-1 elements approach

Time Complexity: O(1) and O(N)

> **Note:** Stack and Queue cannot be traversed as per their definitions.

## Midterm Topics

### 1. Set and ADT Set
- Comparison with ADT List
- **ADT UID Operations:**
  - Union
  - Intersection
  - Difference

#### Implementations
- Array Implementation
- Linked List Implementation
- Cursor-based Implementation
- Bit-Vector Implementation
- Computer Word Implementation
  - Shift operators (>>, <<)
  - Bit-wise operators (&, ^, |, ~)

### 2. ADT Dictionary
- Set-based ADT with Insert, Delete, and Member operations

### 3. Hashing
1. **Open Hashing** (External Hashing)
2. **Closed Hashing** (Internal Hashing)
   - Key concepts: Collision, Synonyms, Linear Probing
   - Performance metrics: Load Factor, Average Search Length
   - External Memory Implementation

## Pre-Final Topics

### 1. ADT Tree
- Tree concepts and terminology
- **Traversals:**
  - Preorder
  - Inorder
  - Postorder

#### Implementations
- Parent Pointer Implementation
- List of Children Implementation
- Binary Trees
- Expression Trees
- Huffman Code

### 2. Binary Search Tree (BST)
- Implementation and operations
- Comparison with AVL trees
- Binary vs Sequential Search

### 3. ADT Priority Queue
- Min/Max Heap implementations
- Heap operations
- Heapsort algorithm

## Final Topics

### Graph Theory
1. **Graph Types**
   - Directed
   - Undirected

2. **Implementations**
   - Adjacency Matrix
   - Adjacency List

3. **Algorithms**
   - Shortest Path Algorithms
     - Dijkstra's
     - Floyd's
     - Warshall's
   - Graph Traversals
     - Depth First Search (DFS)
     - Breadth First Search (BFS)
   - Minimum Spanning Tree
     - Prim's Algorithm
     - Kruskal's Algorithm

## References
- Ma'am Christine Pena
- Data Structures by Aho, Hopcroft, and Ullman
