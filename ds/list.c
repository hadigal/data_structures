/************************************************
# File: list.c
# Desc.: Contains all the list function definitions
# Author: Hrishikesh Adigal
# email: hadigal@sdsu.edu
# Date: 08/10/2018
************************************************/

#include "list.h"

struct node *createList(struct node *start)
{
  int next,data,totalNodes;
  printf("Enter the totalNodes:\n");
  scanf("%d",&totalNodes);
  if(totalNodes == 0)
  {
    start = NULL;
    return start;
  }
  start = addEmptyList(start);
  for(next = 2; next <= totalNodes; next++)
  {
    printf("Enter data the data to be stored at node # %d:\n",next);
    scanf("%d",&data);
    start = addAtEnd(start,data);
  }
  return start;
}

struct node *addAtBeginning(struct node *start, int data)
{
  struct node *node1 = (struct node *)calloc(1,sizeof(struct node));
  struct node *ptr = start;
  node1->info = data;
  node1->nextLink = start;
  start = node1;
  return start;
}

struct node *addAtEnd(struct node *start, int data)
{
  struct node *node1 = (struct node *)calloc(1,sizeof(struct node));
  struct node *ptr = start;
  while(ptr->nextLink != NULL)
  {
    ptr = ptr->nextLink;
  }
  node1->nextLink = ptr->nextLink;
  node1->info = data;
  ptr->nextLink = node1;
  return start;
}

struct node *addEmptyList(struct node *start)
{
  int data;
  struct node *node1 = (struct node *)calloc(1,sizeof(struct node));
  printf("Enter data to be stored at First node:\n");
  scanf("%d",&data);
  node1->info = data;
  node1->nextLink = start;
  start = node1;
  return start;
}

void search(struct node *start,int data)
{
  if(start == NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct node *ptr = start;
  unsigned int count = 1;
  while(ptr != NULL)
  {
    if(ptr->info == data)
    {
      printf("found data at node #:%d\n",count);
      return;
    }
    ptr = ptr->nextLink;
    count++;
  }
  printf("Data[%d] not found the list\n",data);
}

unsigned int count(struct node *start)
{
  if(start == NULL)
  {
    printf("List is empty\n");
    return 0;
  }
  struct node *ptr = start;
  unsigned int nodeCount = 0;
  while(ptr != NULL)
  {
    nodeCount++;
    ptr = ptr->nextLink;
  }
  return nodeCount;
}

void display(struct node *start)
{
  if(start == NULL)
  {
    printf("List is empty\n");
    return;
  }

  struct node *ptr;
  ptr = start;

  while(ptr != NULL)
  {
    printf("Node addr: %p\n",ptr);
    printf("Node data: %d\n",ptr->info);
    ptr = ptr->nextLink;
  }
}

struct node *reverse(struct node *start)
{
  struct node *ptr, *currLink, *nxtLink;
  ptr = start;
  currLink = NULL;
  while(ptr != NULL)
  {
    nxtLink = ptr->nextLink;
    ptr->nextLink = currLink;
    currLink = ptr;
    ptr = nxtLink;
  }
  start = currLink;
  return start;
}

struct node *insertAfter(struct node *start,int data, int item)
{
  struct node *ptr;
  ptr = start;

  if(start == NULL)
  {
    printf("empty list\n");
    return start;
  }

  while(ptr != NULL)
  {
    if(ptr->info == item)
    {
      //struct node *tempPtr = ptr->link;
      struct node *tempNode = (struct node *)malloc(1*sizeof(struct node));
      tempNode->info = data;
      tempNode->nextLink = ptr->nextLink;
      ptr->nextLink = tempNode;
      return start;
    }
    ptr = ptr->nextLink;
  }
  printf("Item[%d] not found in the list\n",item);
  return start;
}

struct node *insertBefore(struct node *start, int data, int item)
{
  if(start == NULL)
  {
    printf("Empty List\n");
    return start;
  }

  if(start->info == item)
  {
    struct node *tempNode = (struct node *)calloc(1,sizeof(struct node));
    tempNode->info =  data;
    tempNode->nextLink = start;
    start = tempNode;
    return start;
  }

  struct node * ptr = start;
  while(ptr->nextLink != NULL)
  {
    if(ptr->nextLink->info == item)
    {
      struct node * tempNode = (struct node *)calloc(1,sizeof(struct node));
      tempNode->info = data;
      tempNode->nextLink = ptr->nextLink;
      ptr->nextLink = tempNode;
      return start;
    }
    ptr = ptr->nextLink;
  }
  printf("Item[%d] not found\n",item);
  return start;
}

struct node *insertAtPos(struct node *start, int data, int pos)
{
  struct node *ptr = start;
  struct node * tempNode;
  int itr;
  for(itr = 1; itr < pos - 1 && ptr != NULL; itr++)
  {
    ptr = ptr->nextLink;
  }

  if(ptr == NULL)
  {
    printf("Not enough elements in the given list\n");
    return start;
  }
  else
  {
    tempNode = (struct node *)calloc(1,sizeof(struct node));
    tempNode->info = data;
    if(pos == 1)
    {
      tempNode->nextLink = start;
      start = tempNode;
      return start;
    }
    else
    {
      tempNode->nextLink = ptr->nextLink;
      ptr->nextLink = tempNode;
      return start;
    }
  }
}

struct node *deleteNode(struct node *start, int data)
{
  if(start == NULL)
  {
    printf("List is empty\n");
    return start;
  }
  struct node *temp;
  if(start->info == data)
  {
    temp = start;
    start = temp->nextLink;
    free(temp);
    return start;
  }
  struct node *ptr = start;
  while(ptr->nextLink != NULL)
  {
    if(ptr->nextLink->info == data)
    {
      temp = ptr->nextLink;
      ptr->nextLink = temp->nextLink;
      free(temp);
      return start;
    }
    ptr = ptr->nextLink;
  }
  printf("Node with data[%d] not found\n",data);
  return start;
}
