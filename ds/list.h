#ifndef LIST_H
  #define LIST_H list.h

  #include "common.h"

  struct node
  {
    int info;
    struct node *nextLink;
  };

  struct node *addEmptyList(struct node *start);

  struct node *createList(struct node *start);

  void search(struct node *start,int data);

  unsigned int count(struct node *start);

  void display(struct node *start);

  struct node *addAtBeginning(struct node *start, int data);

  struct node *addAtEnd(struct node *start, int data);

  struct node *reverse(struct node *start);

#endif
