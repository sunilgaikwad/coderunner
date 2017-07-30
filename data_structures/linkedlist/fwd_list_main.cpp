#include "fwd_list.h"

using namespace notastd;

int main()
{
   //forward_list<char> clist(6, 'a');
   //clist.print();
   //forward_list<int> ilist(8, 1);
   //ilist.print();
   forward_list<double> dlist(10, 2.1);
   dlist.print();
   dlist.insertAt(9, 3.0);
   dlist.reverse();
   dlist.print();
   return 0;
}
