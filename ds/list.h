/************************************************
# File: list.h
# Desc.: Contains all the declaration of list functions
# Author: Hrishikesh Adigal
# email: hadigal@sdsu.edu
# Date: 08/10/2018
************************************************/

#ifndef LIST_H
  #define LIST_H

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

  struct node *insertAfter(struct node *start,int data, int item);

  struct node *insertBefore(struct node *start,int data, int item);

  struct node *insertAtPos(struct node *start,int data, int pos);

  struct node *deleteNode(struct node *start, int item);

  void search(struct node *start, int data);

#endif
