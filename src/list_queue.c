#include "list_queue.h"

void init_queue(queue *q)
{
  q->size = 0; // sætter queuen til at være tom
  q->front = NULL; // queue er tom
  q->rear = NULL; // tom queue
}

int empty(queue *q)
{
   return q->size == 0; // returner hvis queue er tom
}

void enqueue(queue *q, int x)
{
  qnode *newnode = malloc(sizeof(qnode)); //laver ny node som puttes i queue
  newnode->next = NULL;
  newnode->data = x;

  if (q->size == 0)
    q->front = newnode;
  else
    q->rear->next = newnode;

  q->rear = newnode;
  q->size++;
  return;
  }

int dequeue(queue *q)
{
  assert(q->size > 0); //sørger for at queue skal være tom 
  qnode *f = q -> front;
  int data = q -> front -> data;
  
  if (q->size == 1) // tjekker om der er noget i queue
  {
    q->front = NULL; 
    q->rear = NULL;
  }
  else if (q->size > 1) // kører hvis der er noget i queuen
  {
    q->front = q->front->next; // sætter den nye værdi a q's front til at pege på next, hvilket er den forige værdi i queuen
  }
  q->size--; // gør queue én mindre
  
  return data;
}