#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
 {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    ListNode* result = nullptr;
    ListNode* last = nullptr;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr)
    {
      if(l1 != nullptr)
      {
        carry = carry + l1->val;
        l1 = l1->next;
      }
      if(l2 != nullptr)
      {
        carry = carry + l2->val;
        l2 = l2->next;
      }
      ListNode *newnode = new ListNode(carry % 10);
      if(result == nullptr)
      {
        result = newnode;
        last = newnode;
      }
      else
      {
        last->next = newnode;
        last = newnode;
      }
      carry = carry / 10;
    }
    if(carry == 1)
    {
      ListNode *newnode = new ListNode(1);
      last->next = newnode;
    }
    return result;
 }

 int main()
 {
   addTwoNumbers(nullptr, nullptr);
   return 0;
 }


 //non negative integers
 // reverse order 123 represented as 3->2->1
 //single digit
 //no leading zeros
