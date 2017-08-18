#include "hashtable.h"

namespace notastd
{
  template <class T>
  void map<T>::print()
  {
    for(int i = 0; i < m_capacity; i++)
    {
      node<T> *temp = arry[i];
      while(temp != nullptr)
      {
        cout<<"(Key : "<<temp->m_key<<" Value : "<<temp->m_data<<")"<<" -> ";
        temp = temp->m_next;
      }
      cout<<endl;
    }
  }

  template <class T>
  int map<T>::Hash(T value)
  {
    return (((int)value) % m_capacity);
  }

  template <class T>
  void map<T>::Rehash()
  {

  }

  template <class T>
  void map<T>::UpdateCapacity()
  {
    if(m_count == m_capacity)
    {
      //we will double capacity if no of elements are same as capacity
      //m_capacity = m_capacity * 2;
      //Rehash();
    }
  }

  template <class T>
  void map<T>::insertnode(int index, T value)
  {
    node<T> *newnode = new node<T>(value, index);
    if(arry[index] == nullptr)
    {
      arry[index] = newnode;
    }
    else
    {
      node<T> *temp = arry[index];
      while(temp->m_next != nullptr)
      {
        temp = temp->m_next;
      }
       temp->m_next = newnode;
    }
  }

  template <class T>
  void map<T>::insert(T value)
  {
    m_count++;
    UpdateCapacity();
    int index = Hash(value);
    insertnode(index, value);
  }

  template class map<int>;
  template class map<double>;
}
