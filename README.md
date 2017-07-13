# coderunner
Common Programs
1) dijkstra_simple
  This is simple dijkstra algorithm using structs/classes for data and finding the sortest path from one source vertex to all other vertices
  Array was used for storing the vertices and hence the algorithm has a n2 run time in addition to ElogV for traversing each edge
  In follow-up implementations, i will use a priority queue for increasing run time efficiency

2) dijkstra_matrix
  Same as dijkstra_simple but used a matrix for storing the vertices data

2a) to-do: dijkstra_priorityqueue  

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




/algorithms_analysis - Online course through NPTEL
https://onlinecourses.nptel.ac.in/explorer/search?category=COMP_SCI_ENGG

1) insertionsort.cpp
   A simple insertionsort on fixed integer array


/data_structures - implementations of common data structures

1) array/resizing_array.cpp
   Implementing a resizable array aka vector 
