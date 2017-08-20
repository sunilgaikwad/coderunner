# coderunner
##Common Programs
1) dijkstra_simple
  This is simple dijkstra algorithm using structs/classes for data and finding the sortest path from one source vertex to all other vertices
  Array was used for storing the vertices and hence the algorithm has a n2 run time in addition to ElogV for traversing each edge
  In follow-up implementations, i will use a priority queue for increasing run time efficiency

2) dijkstra_matrix
  Same as dijkstra_simple but used a matrix for storing the vertices data

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


##/algorithms_analysis - Online course through NPTEL
https://onlinecourses.nptel.ac.in/explorer/search?category=COMP_SCI_ENGG

1) insertionsort.cpp
   A simple insertionsort on fixed integer array

2) mergesort.cpp
  Mergesort on fixed integer array. Runtime of nlog n with additional array og size n, where n is number of elements to sort  

3) quicksort.cpp - Also code for randomised quicksort where we randomly select a pivot index
  Performing quicksort using the first element of the array as pivot.   

##/data_structures - implementations of common data structures

1) array/resizing_array.cpp
   Implementing a resizable array aka vector

2) linkedlist/fwd_list.cpp		linkedlist/fwd_list.h		linkedlist/fwd_list_main.cpp
   Just implementation of few important functions. Will not implement all functions.

3) stack/evaluate_postfix_notation.cpp
   Process a (reverse polish) postfix notation and find its value. This was achieved using a stack.  

4) stack/infix_to_postfix_notation.cpp
   Converting a infix notation to a post fix notation. This was achieved using a stack and a queue

5) queue/circular_queue.cpp       queue/circular_queue.h         queue/circular_queue_main.cpp
   Implemented circular queue using a fixed array

6) hashtable - in progress

##/programming_c++ - Online course through NPTEL
https://onlinecourses.nptel.ac.in/explorer/search?category=COMP_SCI_ENGG

1)pointerfun.c
  simple program to understand pointers in c
