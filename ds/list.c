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
