# coderunner
Common Programs
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
