//Implement shortestpaths using dp

#include <iostream>
#include <climits>
#include <set>
#include <stack>
using namespace std;

class edge;

class vertex
{
public:
  int value;
  char name;
  edge *arry[6];

  vertex()
  {
    value = INT_MAX;
    for(int i = 0; i < 6; i++)
    {
      arry[i] = nullptr;
    }
  }
};

class edge
{
public:
  int weight;
  vertex *to;

  edge()
  {
    to = nullptr;
  }
};

stack<vertex *> stk;

void TraverseChildren(vertex *v, set<vertex *> &visited) {
  int i = 0;
  set<vertex *>::iterator it;
  while(v->arry[i] != nullptr) {
    it = visited.find(v->arry[i]->to);
    if(it == visited.end()) {
      TraverseChildren(v->arry[i]->to, visited);
      visited.insert(v->arry[i]->to);
    }
    i++;
  }
  stk.push(v);
}

int main()
{
  //Array to hold vertex
  vertex *vrry[6];
  set<vertex *> visited;

  //Create the graph
  //Create f
  vertex *f = new vertex();
  //Add f
  vrry[0] = f;
  f->name = 'f';

  //Create e
  vertex *e = new vertex();
  edge *ee1 = new edge();
  ee1->weight = 2;
  ee1->to = f;
  e->arry[0] = ee1;

  //Add e
    vrry[2] = e;
    e->name = 'e';

  //Create d
  vertex *d = new vertex();
  edge *ed1 = new edge();
  ed1->weight = 2;
  ed1->to = f;
  d->arry[0] = ed1;
  edge *ee2 = new edge();
  ee2->weight = 3;
  ee2->to = e;
  d->arry[1] = ee2;
  //Add d
  vrry[1] = d;
  d->name = 'd';

  //Create b
  vertex *b = new vertex();
  edge *eb1 = new edge();
  eb1->weight = 4;
  eb1->to = d;
  b->arry[0] = eb1;
  edge *eb2 = new edge();
  eb2->weight = 2;
  eb2->to = e;
  b->arry[1] = eb2;

  //Add b
  vrry[4] = b;
  b->name = 'b';
  //Create c
  vertex *c = new vertex();
  edge *ec1 = new edge();
  ec1->weight = 3;
  ec1->to = e;
  c->arry[0] = ec1;
  edge *eb3 = new edge();
  eb3->weight = 1;
  eb3->to = b;
  c->arry[1] = eb3;
  //Add c
  vrry[3] = c;
  c->name = 'c';



  //Create a
  vertex *a = new vertex();
  a->value = 0;
  edge *ea1 = new edge();
  ea1->weight = 2;
  ea1->to = b;
  a->arry[0] = ea1;
  edge *ea2 = new edge();
  ea2->weight = 4;
  ea2->to = c;
  a->arry[1] = ea2;
  //Add d
  vrry[5] = a;
  a->name = 'a';

  //go through each vertex
  set<vertex *>::iterator it;
  for(int i = 0; i < 6; i++) {
    it = visited.find(vrry[i]);
    if(it == visited.end()) {
      TraverseChildren(vrry[i], visited);
      visited.insert(vrry[i]);
    }
  }

  while(!stk.empty())
  {
    vertex *temp = stk.top();
    cout<<temp->name<<" -> ";
    stk.pop();
  }
  return 0;
}
