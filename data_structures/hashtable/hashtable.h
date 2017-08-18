#include <iostream>
#include <algorithm>
using namespace std;

namespace notastd
{
  // template <class T>
  // class map;

  //class node
  template <class Tn>
  class node
  {
    private:
      Tn m_data;
      int m_key;
      node *m_next;

    node()
    {
      m_next = nullptr;
    }
    node(Tn data, int key) : m_data(data), m_key(key), m_next(nullptr)
    {
    }

  public:
    template <class T>
    friend class map;
  };

  //class map
  template <class T>
  class map
  {
    public:
      map():m_count(0), m_capacity(20)
      {
        std::fill_n(arry, 20, nullptr);
      }

      void insert(T value);
      void print();

    private:
      int m_count;
      int m_capacity;
      node<T>* arry[20];


      void insertnode(int index, T value);
      void UpdateCapacity();
      int Hash(T value);
      void Rehash();
  };
}
