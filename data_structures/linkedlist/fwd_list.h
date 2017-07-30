//Implementation of linked list (forward list)
#include <iostream>
using namespace std;

namespace notastd
{
  template <class Ta>
  class Node
  {
  public:
    Ta data;
    Node *next;

    Node(Ta value) : data(value), next(nullptr) {}
    ~Node()
    {
      delete next;
      cout<<"Node destructor called"<<endl;
    }
    template <class Tb>
    friend class forward_list;
  };

  template <class Tb>
  class forward_list
  {
  private:
    Node<Tb> *fstart;
    Node<Tb> *fend;
    int fsize;

  public:
    forward_list();
    ~forward_list();
    forward_list(int size, Tb value);
    void reverse();
    void insertAt(int index, Tb value);
    void push_back(Tb value);
    void print();
    Node<Tb>* begin();
  };
}
