#include <iostream>
#include <queue>
#include "DirectedWeightedGraph.h"

//constructors
DirectedWeightedGraph::DirectedWeightedGraph()
{
    numberOfVertices=0;
    maxVertices=50;
    vertices = new VertexType[50];
}

DirectedWeightedGraph::DirectedWeightedGraph(int maxV)
{
    numberOfVertices=0;
    maxVertices=maxV;
    vertices = new VertexType[maxVertices];
}

//destructor
DirectedWeightedGraph::~DirectedWeightedGraph()
{
   delete [] vertices;
   numberOfVertices=0;
}

bool DirectedWeightedGraph::IsEmpty() const
{
   if(numberOfVertices==0);
	return true;

   return false;
}

bool DirectedWeightedGraph::IsFull() const
{
   if(numberOfVertices==maxVertices)
	return true;

   return false;
}

void DirectedWeightedGraph::AddVertex(VertexType v)
{
   vertices[numberOfVertices] = v;

   for(int i=0; i<numberOfVertices; i++)
   {
      edges[numberOfVertices][i] = 0;
      edges[i][numberOfVertices] = 0;
   }

   numberOfVertices++;
}

void DirectedWeightedGraph::DeleteVertex(VertexType v)
{
   int index = IndexIs(v);
   int last = numberOfVertices-1;
   int weight =0;

   if(index !=last)
   {
        VertexType t;
	for(int i=0; i<numberOfVertices;i++)
	{
	    DeleteEdge(vertices[i], vertices[index]);
	    DeleteEdge(vertices[index], vertices[i]);
 	
	    if(i != index)
	    {
		if(EdgeExists(vertices[i],vertices[last]))
		{
		  weight = GetWeight(vertices[i], vertices[last]);
		  AddEdge(vertices[i], vertices[index], weight);
		}

                if(EdgeExists(vertices[last],vertices[i]))
                {
                    weight = GetWeight(vertices[last], vertices[i]);
                    AddEdge(vertices[i], vertices[index], weight);
                 }
	   }
      }

      t = vertices[last];
      vertices[index] = t;
   }

   numberOfVertices--;
}

void DirectedWeightedGraph::AddEdge(VertexType v1, VertexType v2, int w)
{
  
    int i1 = IndexIs(v1);
    int i2 = IndexIs(v2);

    edges[i1][i2] = w;   
}

 bool DirectedWeightedGraph::DeleteEdge(VertexType v1, VertexType v2)
{
   if(EdgeExists(v1,v2))
   {
     int i1 = IndexIs(v1);
     int i2 = IndexIs(v2);
     
     edges[i1][i2]=0;
     return true;
   }

   return false;
}

int DirectedWeightedGraph::GetWeight(VertexType v1, VertexType v2)
{
   int i1 = IndexIs(v1);
   int i2 = IndexIs(v2);
 
   return (edges[i1][i2]);
}

int DirectedWeightedGraph::IndexIs(VertexType v)
{
   for(int i=0; i<numberOfVertices; i++)
   {
      if(vertices[i].item.ComparedTo(v.item) == EQUAL)
	return i;
   }

   return -1;

}

bool DirectedWeightedGraph::EdgeExists(VertexType v1, VertexType v2)
{
   int i1 = IndexIs(v1);
   int i2 = IndexIs(v2);

   if(edges[i1][i2] != 0)
     return true;
   
   return false;
}

bool DirectedWeightedGraph::VertexExists(VertexType v)
{
   for(int i=0; i<numberOfVertices; i++)
   {
      if(vertices[i].item.ComparedTo(v.item))
         return true;
   }
   return false;
   
}

void DirectedWeightedGraph::GetNeighbors(VertexType v, queue<VertexType>& nq)
{
   int index = IndexIs(v);

   for(int i=0; i<numberOfVertices; i++)
   {
      if(edges[index][i] != 0 && vertices[i].mark != QUEUED && vertices[i].mark != VISITED)
      {
         nq.push(vertices[i]);
	 vertices[i].MarkVertex(QUEUED);
      }
   }
}

// Breadth-First Traversal :: Queue datara structure (FIFO)
// "neighbors first"; visit all nodes on one level before going to the next
void DirectedWeightedGraph::BreadthFirstTraversal(VertexType v)
{
   int index = IndexIs(v);

   vertices[index].item.Print();
   vertices[index].MarkVertex(VISITED);
   GetNeighbors(v,nq);

   while(!nq.empty())
   {
      VertexType q = nq.front();
      q.item.Print();
      q.MarkVertex(VISITED);
      GetNeighbors(q,nq);
      nq.pop();
   }

  for(int i=0; i<numberOfVertices; i++)
      vertices[i].MarkVertex(DEFAULT);

}

