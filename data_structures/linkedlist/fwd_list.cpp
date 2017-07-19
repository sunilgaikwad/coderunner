//implementation of forward_list
#include <iostream>
#include "fwd_list.h"

namespace notastd
{
  template <class Tb>
  forward_list<Tb>::forward_list()
  {

  }

  template <class Tb>
  forward_list<Tb>::forward_list(int size, Tb value)
  {

  }

  template <class Tb>
  void forward_list<Tb>::reverse()
  {

  }

  template <class Tb>
  void forward_list<Tb>::insertAt(int index, Tb value)
  {

  }

  template <class Tb>
  void forward_list<Tb>::push_back(Tb value)
  {

  }

  template <class Tb>
  void forward_list<Tb>::print()
  {
    std::cout << "Hello" << '\n';
  }
}

//When you define your template in a .cpp file, you have to explicitly instantiate it with all the types known
//If you don't know with which template parameters the template will be used,
// you have to put all the definitions

  template class notastd::forward_list<int>;
  template class notastd::forward_list<double>;
  template class notastd::forward_list<char>;
