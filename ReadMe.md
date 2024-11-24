# Coverage

## Pre-Midterm Topics

#### 1. Abstract Data Type (ADT)

#### 2. ADT List

- Differentiate a List from an ADT List.
    - **List Operations:** Initialize, insert, delete, member, locate, and other operations

- **Implementations of ADT List**

    **a. Array Implementation (4 versions)**
    - **Version 1:** List is a structure containing an array and variable count. 
    
    **Note:** count represents the actual number of elements in the array. If *MAX* is the size of the array, count <= MAX.
    
    - **Version 2:** List is a pointer to a structure containing an array and variable count
- Version 3: List is a structure containing a pointer to the 1st element of a dynamic array, and variable count
- Version 4: List is a pointer to a structure containing a pointer to the 1st element of a dynamic array, and variable count
Linked List Implementation (Singly Link)
Cursor-based Implementation
Time Complexity of the List operations in different implementations: O(1), O(N), and O(N*N)
ADT Stack and Implementations

What is an ADT Stack?
Stack Operations: Top, Pop, Push, and other utility functions such as initStack, isEmpty, and isFull
Implementations
Array Implementation (4 versions)
Linked List Implementation
Cursor-based Implementation
Time Complexity: O(1) and O(N)
ADT Queue and Implementations

What is an ADT Queue?
Queue Operations: Front, Dequeue, Enqueue, and other utility functions such as initQueue, isEmpty, and isFull
Implementations
Linked List Implementation
Queue is a pointer to a dynamically allocated node
Queue is a structure containing front and rear pointers to dynamically allocated node/s
Circular Array Implementation
Solution 1: Add a counter
Solution 2: Queue is full if there are MAX-1 elements
Note: where MAX is the size of the array
Time Complexity: O(1) and O(N)
Caution: The Stack and the Queue CANNOT be traversed! (See definition of stack and queue)

Midterm Topics

Set and ADT Set

ADT Set vs. ADT List
What are the differences between the two?
ADT's based on Set
ADT UID
An ADT based on set with operations Union, Intersection, and set Difference
Implementations
Array, Linked list, and cursor-based implementations
Bit-Vector Implementation
Computer Word Implementation
Shift operators: >> and <<
Bit-wise operators: & ^ | ~
ADT Dictionary

An ADT based on set with operations Insert, Delete, and Member

Two types of Hashing:

Open Hashing (or External Hashing)
Closed Hashing (or Internal Hashing)
Closed Hashing Terms: Collision, Synonyms, Linear Hashing or Probing, Displacement, Packing Density (Load Factor), Average Search Length, Perfect Hash Function

Closed Hashing variants

Closed Hashing in external Memory (Files: fopen, fclose, fread, fwrite, fseek)
Pre-Final Topics

ADT Tree and Implementations [Source: Data Structure by Aho, Hopcroft, and Ullman]

Definition of a tree
Basic concepts and terms related to tree
Tree Traversals [Preorder, Inorder, Postorder]
ADT Tree Implementations
Parent Pointer Implementation
List of Children Implementation
Binary Tree definition and Implementations
Expression Trees
Huffman Code
Binary Search Tree (BST) [Sources: There are many sites on the internet such as Geeks for Geeks]

Description and Implementation
Operations: Insert, Delete, and Member
Similarity and Difference between BST and AVL trees
Binary Search vs. Sequential Search
ADT Priority Queue

Partially Ordered Tree (POT)
Min and Max heap
MinHeap: Operations: insert and deleteMin [Source: Data Structure by Aho, Hopcroft, and Ullman]
MaxHeap: Operations: insert and deleteMax [Sources: Internet]
MinHeapify and MaxHeapify
Version 1: Insert all elements in an initially empty POT [Source: ebook]
Version 2: Heapify starting with lowest level parent [Sources: Internet]
Heapsort Sorting Technique (in place)

A sorting algorithm is an "in place" sorting algorithm if there is no additional array used when implementing the sorting process.
Final Topics

Directed and Undirected Graph [Source: Data Structure by Aho, Hopcroft, and Ullman]
Concepts
Graph Implementations:
Adjacency Matrix
Adjacency List
Graph Algorithms [Source: Data Structure by Aho, Hopcroft, and Ullman]
Shortest Paths: Dijkstra's Floyd's, and Warshall's Algorithms
Traversals: Depth First Search (DFS) and Breadth First Search (BFS)
Minimum Cost Spanning Tree: Prim's and Kruskal's Algorithms
References

Mme. Christine Pena