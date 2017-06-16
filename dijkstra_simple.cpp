#include <iostream>
#include <climits>
using namespace std;

class edge;

class vertex
{
public:
  int value;
  edge *arry[6];
  bool visited;

  vertex()
  {
    value = INT_MAX;
    visited = false;
    for(int i = 0; i < 6; i++)
    {
      arry[i] = NULL;
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
    to = NULL;
  }
};

bool FindSmallest(vertex *vrry[6], int &index)
{
   bool allvisited = true;
   int smallest;
   bool onlyonce = false;
   for(int i = 0; i < 6; i++)
   {
      if(vrry[i]->visited == false)
      {
        allvisited = false;
        if(onlyonce == false)
        {
          smallest = vrry[i]->value;

          onlyonce = true;
          index = i;
        }

        if(vrry[i]->value < smallest)
        {
          index = i;
          smallest = vrry[i]->value;
        }

      }
   }
   return !allvisited;
}

int main()
{
  //Array to hold vertex
  vertex *vrry[6];

  //Create the graph
  //Create f
  vertex *f = new vertex();
  //Add f
  vrry[0] = f;

  //Create d
  vertex *d = new vertex();
  edge *ed1 = new edge();
  ed1->weight = 2;
  ed1->to = f;
  d->arry[0] = ed1;
  //Add d
  vrry[1] = d;

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

  //Create c
  vertex *c = new vertex();
  edge *ec1 = new edge();
  ec1->weight = 3;
  ec1->to = e;
  c->arry[0] = ec1;
  //Add c
  vrry[3] = c;

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

  //while array is not all visited
  bool allvisited = false;
  while(allvisited == false)
  {
     //find the smallest value vertex
     int smallest = 0;

     if(FindSmallest(vrry, smallest))
     {
       vrry[smallest]->visited = true;

       //relax the values of vertex
       int j = 0;
       while(vrry[smallest]->arry[j] != NULL)
       {
          if(vrry[smallest]->value + vrry[smallest]->arry[j]->weight < vrry[smallest]->arry[j]->to->value)
          {
            vrry[smallest]->arry[j]->to->value = vrry[smallest]->value + vrry[smallest]->arry[j]->weight;
          }
          j++;
       }

     }
     else
     {
      allvisited = true;
     }
  }
  cout<<"Done finding shortest paths"<<endl;
  cout<<c->value;
  return 0;
}
