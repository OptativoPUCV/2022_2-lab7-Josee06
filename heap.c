#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
  if(pq->size == 0) return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority)
{
  heapElem elemento, aux;
  int s;
  elemento.data = data;
  elemento.priority = priority;

  if(pq->size == pq->capac)
  {
    pq->capac = (pq->capac*2) + 1;
    pq->heapArray = (heapElem *) realloc (pq->heapArray, sizeof(heapElem)*pq->capac); 
  }
  pq->heapArray[pq->size] = elemento;
  
  s = pq->size;
  while(pq->heapArray[s].priority > pq->heapArray[(s - 1)/2].priority)
  {
    if(pq->heapArray[s].priority > pq->heapArray[(s - 1)/2].priority)
    {
      aux = pq->heapArray[(s - 1)/2];
      pq->heapArray[(s - 1)/2] = pq->heapArray[s];
      pq->heapArray[s] = aux;
      s = (s-1)/2;
    }
  }
  pq->size++;
}


void heap_pop(Heap* pq)
{
  pq->size--;
  pq->heapArray[0]=heapArray[pq->size];
  prioridad=pq->heapArray[0].priority;
  now=1;

  while((now <= pq->size && pq->heapArray[now].priority > pq->priority)|| now +1<=pq->size && pq->heapArray[now+1].priority>pq->priority)
  {
    heapElem temporal= pq->heapArray[(now-1)/2];
    if (now+1<= pq->size && pq->heapArray[now+1].priority > pq->priority) now++;
    pq->heapArray[(now-1)/2]=  pq->heapArray[now]
    pq->heapArray[now] = temporal;
    now=now*2+1;
    
  }
}

Heap* createHeap()

{
  Heap * new = (Heap*) malloc (sizeof(Heap));
  new->heapArray=(heapElem*) malloc (3*sizeof(heapElem));
  new->size=0;
  new->capac = 3;
  return new;
}
