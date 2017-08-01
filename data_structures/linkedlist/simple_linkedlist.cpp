#include <iostream>
using namespace std;

typedef struct Linkedlist
{
  int data;
  Linkedlist *next;
}list;

void addsimple(list **root, int val)
{
  if(*root == nullptr)
  {
    //first element
    *root = new list;
    (*root)->data = val;
    (*root)->next = nullptr;

  }
  else
  {
    //traverse to end and add. Alternatively can use a end pointer
    list *temp = *root;
    while(temp->next != nullptr)
    {
      temp = temp->next;
    }
    list *newnode = new list;
    newnode->data = val;
    newnode->next = nullptr;
    temp->next = newnode;
  }
}

void deletesimple(list **root, int val )
{
  if(*root != nullptr)
  {
    list *temp = *root;
    list *prev = nullptr;
    while(temp != nullptr)
    {
      if(temp->data == val)
      {
        if(temp == *root)
        {
          *root = (*root)->next;
        }
        else
        {
          prev->next = temp->next;
        }
        delete temp;
        temp = nullptr;
        cout<<"deleted"<<endl;
        return;
      }
      prev = temp;
      temp = temp->next;
    }
  }
}
void deleteusingpointertopointer(list **root, int val )
{
  //will come back to this at a later time
}
void print(list *root)
{
  if(root != nullptr)
  {
    list *temp = root;
    while(temp != nullptr)
    {
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
}

int main()
{
  list *root = nullptr;
  addsimple(&root, 0);
  addsimple(&root, 1);
  addsimple(&root, 2);
  addsimple(&root, 3);
  addsimple(&root, 4);
  addsimple(&root, 5);
  deletesimple(&root, 0);
  print(root);
  return 0;
}
