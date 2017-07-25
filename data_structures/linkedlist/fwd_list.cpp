//implementation of forward_list
#include <iostream>
#include "fwd_list.h"
#include <exception>

using namespace std;

namespace notastd
{
  template <class Tb>
  forward_list<Tb>::forward_list()
  {
    fsize = 0;
    fstart = fend = nullptr;
  }

  template <class Tb>
  forward_list<Tb>::forward_list(int size, Tb value)
  {
    fstart = fend = nullptr;
    fsize = size;
    for(int i = 0; i < size; i++)
    {
      Node<Tb> *temp = new Node<Tb>(value);
      if(fstart == nullptr)
      {
        fend = fstart = temp;
      }
      else
      {
        fend->next = temp;
        fend = fend->next;
      }
    }
  }

  template <class Tb>
  void forward_list<Tb>::reverse()
  {
    Node<Tb> *newstart = nullptr;
    Node<Tb> *it = fstart;
    while(it != nullptr)
    {
      Node<Tb> *temp = it;
      it = it->next;
      temp->next = newstart;
      if(newstart == nullptr)
      {
        //set end
        fend = temp;
      }
      newstart = temp;
    }
    fstart = newstart;
  }

  template <class Tb>
  void forward_list<Tb>::insertAt(int index, Tb value)
  {
    if(index < 0 || index > fsize)
    {
      throw std::exception();
    }
    Node<Tb> *temp = new Node<Tb>(value);
    if(index == 0)
    {
      //its pushing the element at start
      temp->next = fstart;
      fstart = temp;
    }
    else if(index == fsize)
    {
      //insert at last
      fend->next = temp;
      fend = temp;
    }
    else
    {
      Node<Tb> *prev = nullptr;
      Node<Tb> *it = fstart;
      for(int i = 1; i < index; i++)
      {
        prev = it;
        it = it->next;
      }
      prev->next = temp;
      temp->next = it;
    }
    fsize++;
  }

  template <class Tb>
  void forward_list<Tb>::push_back(Tb value)
  {
    //push at the last

  }

  template <class Tb>
  void forward_list<Tb>::print()
  {
    Node<Tb> *temp = fstart;
    for(int i = 0; i < fsize; i++)
    {
      cout<<temp->data<<"->";
      temp = temp->next;
    }
    cout<<endl;
  }
}

//When you define your template in a .cpp file, you have to explicitly instantiate it with all the types known
//If you don't know with which template parameters the template will be used,
// you have to put all the definitions

  template class notastd::forward_list<int>;
  template class notastd::forward_list<double>;
  template class notastd::forward_list<char>;
