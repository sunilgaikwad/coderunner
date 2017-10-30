# coderunner
##Common Programs

3) fillpattern
  Given a matrix with bools, fill the ones that are false and return the number of blocks filled. Using recursion for first method.
  However all variables are stored on the stack and for a big matrix its highly likely that it will over flow.
  Next approach will be using iterative dfs.

4) fillpattern_stack
   Same as above but using stl stack instead of recursion

5) fillpattern_queue
   Same as above but using queue i.e to use breadth first search

6) rotateimage
   rotate an image by 90 degrees. since worked on few matrices, just trying out this standard matrix rotation problem

7) data_structures/hashtable/stringmatching_KarbRabin.cpp
   Finding a string in a large string using Rabin-Karp algorithms

##/algorithms_analysis - Online course through NPTEL
https://onlinecourses.nptel.ac.in/explorer/search?category=COMP_SCI_ENGG

1) insertionsort.cpp
   A simple insertionsort on fixed integer array

2) mergesort.cpp
  Mergesort on fixed integer array. Runtime of nlog n with additional array og size n, where n is number of elements to sort  

3) orderstatistics.cpp
  Nth smallest element in a array of unsorted elements. Used divid and conquer technique  

##/data_structures - implementations of common data structures

1) array/resizing_array.cpp
   Implementing a resizable array aka vector

2) linkedlist/fwd_list.cpp		linkedlist/fwd_list.h		linkedlist/fwd_list_main.cpp
   Just implementation of few important functions. Will not implement all functions.

3) stack/evaluate_postfix_notation.cpp
    Process a (reverse polish) postfix notation and find its value. This was achieved using a stack.  

4) stack/infix_to_postfix_notation.cpp
    Converting a infix notation to a post fix notation. This was achieved using a stack and a queue

5) heap/heap.cpp
   Implementation of heap using a vector. Implemented Enqueue/Dequeue for heapsort

6) hashtable/*.*
    Hashtable implementation using array.     

7) graph/
  a) dijkstra_simple.cpp
    This is simple dijkstra algorithm using structs/classes for data and finding the shortest path from one source vertex to all other vertices
    Array was used for storing the vertices and hence the algorithm has a n2 run time in addition to ElogV for traversing each edge
    In follow-up implementations, i will use a priority queue for increasing run time efficiency

  b) dijkstra_matrix.cpp
    Same as dijkstra_simple but used a matrix for storing the vertices data

  c) ShortestPaths_dp.cpp
    Shortest path from a source vertex to a given vertex using dynamic programming

  d)Topologicalsort.cpp
    Sorting a DAG topologically  

##/programming_c++ - Online course through NPTEL
https://onlinecourses.nptel.ac.in/explorer/search?category=COMP_SCI_ENGG

1)pointerfun.c
  simple program to understand pointers in c

##/searching_techniques
1) binarysearch_sortedarray.cpp
   Searching a sorted array using binary search. Both iterative and recursive approach
   Added unit test using googletest.
