#include "fwd_list.h"

using namespace notastd;

int main()
{
   forward_list<int> list;
   list.print();
   forward_list<double> dlist;
   dlist.print();
   forward_list<char> clist;
   clist.print();
   return 0;
}
