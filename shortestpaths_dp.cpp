//Implement shortestpaths using dp

#include <iostream>
#include <climits>
using namespace std;

class edge;
class indegree;

class vertex
{
public:
  int value;
  char name;
  edge *arry[6];
  bool visited;
  indegree *indegrees[6];

  vertex()
  {
    value = INT_MAX;
    visited = false;
    for(int i = 0; i < 6; i++)
    {
      arry[i] = nullptr;
    }
    for(int i = 0; i < 6; i++)
    {
      indegrees[i] = nullptr;
    }
  }
};

class indegree {
public:
  int value;
  vertex *v;
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

int ShortestPaths(vertex *start, vertex *end)
{
  cout<<start->name <<","<<end->name<<endl;
  if(start == end) {
    return 0;
  }
  int min = INT_MAX;
  int it = 0;
  while(end->indegrees[it] != nullptr)
  {
    int tempmin = end->indegrees[it]->value + ShortestPaths(start, end->indegrees[it]->v);
    it++;
    if(tempmin < min)
      min = tempmin;
  }
  return min;
}

int main()
{
  //Array to hold vertex
  vertex *vrry[6];
  int distances[6];

  //Create the graph
  //Create f
  vertex *f = new vertex();
  //Add f
  vrry[0] = f;
  f->name = 'f';

  //Create d
  vertex *d = new vertex();
  edge *ed1 = new edge();
  ed1->weight = 2;
  ed1->to = f;
  d->arry[0] = ed1;
  //Add d
  vrry[1] = d;
  d->name = 'd';

  //Create e
  vertex *e = new vertex();
  edge *ee1 = new edge();
  ee1->weight = 2;
  ee1->to = f;
  e->arry[0] = ee1;
  edge *ee2 = new edge();
  ee2->weight = 3;
  ee2->to = d;
  e->arry[1] = ee2;
  //Add e
  vrry[2] = e;
  e->name = 'e';

  //Create c
  vertex *c = new vertex();
  edge *ec1 = new edge();
  ec1->weight = 3;
  ec1->to = e;
  c->arry[0] = ec1;
  //Add c
  vrry[3] = c;
  c->name = 'c';

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
  edge *eb3 = new edge();
  eb3->weight = 1;
  eb3->to = c;
  b->arry[2] = eb3;
  //Add b
  vrry[4] = b;
  b->name = 'b';

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

  //Add indegrees
  indegree *id1 = new indegree;
  id1->v = d;
  id1->value = 2;
  f->indegrees[0] = id1;
  indegree *id2 = new indegree;
  id2->v = e;
  id2->value = 2;
  f->indegrees[1] = id2;


  indegree *id3 = new indegree;
  id3->v = b;
  id3->value = 4;
  d->indegrees[0] = id3;
  indegree *id4 = new indegree;
  id4->v = c;
  id4->value = 2;
  d->indegrees[1] = id4;
  indegree *id5 = new indegree;
  id5->v = e;
  id5->value = 3;
  d->indegrees[2] = id5;

  indegree *id6 = new indegree;
  id6->v = b;
  id6->value = 2;
  e->indegrees[0] = id6;
  indegree *id7 = new indegree;
  id7->v = c;
  id7->value = 3;
  e->indegrees[1] = id7;

  indegree *id8 = new indegree;
  id8->v = a;
  id8->value = 2;
  b->indegrees[0] = id8;

  indegree *id9 = new indegree;
  id9->v = a;
  id9->value = 4;
  c->indegrees[0] = id9;
  indegree *id10 = new indegree;
  id10->v = b;
  id10->value = 1;
  c->indegrees[1] = id10;

  int result = ShortestPaths(a, f);
  cout<<result<<endl;
  return 0;
}
