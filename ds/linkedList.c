/************************************************
# File: linkedList.c
# Author: Hrishikesh Adigal
# email: hadigal@sdsu.edu
# Date: 08/10/2018
************************************************/
#include "list.h"

int main(void)
{
  struct node *start = NULL;
  int choice;
  int data,item,pos;
  unsigned int countNode;

  do
  {
    printf("\n**** Enter any one of the below choice ****\n");
    printf("1. create list\n");
    printf("2. insert at the beg.\n");
    printf("3. insert at the end\n");
    printf("4. search an element\n");
    printf("5. reverse the list\n");
    printf("6. count the nodes of the list\n");
    printf("7. Dislplay info of each node\n");
    printf("8. insert before a node\n");
    printf("9. insert after a node\n");
    printf("10. insert at a particular position\n");
    printf("11. Delete a node\n");
    printf("0. EXIT\n");
    printf("\n*******************************************\n");

    printf("\nEnter your choice:\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
        start = createList(start);
        break;

      case 2:
        printf("\nEnter data for node to be inserted at the beginning of the list:\n");
        scanf("%d",&data);
        start = addAtBeginning(start,data);
        break;

      case 3:
        printf("\nEnter data for node to be inserted at the End of the list:\n");
        scanf("%d",&data);
        start = addAtEnd(start,data);
        break;

      case 4:
        printf("\nEnter the data to be searched in the list:\n");
        scanf("%d",&data);
        search(start,data);
        break;

      case 5:
        start = reverse(start);
        break;

      case 6:
        countNode = count(start);
        printf("\nTotal # of nodes in the list:%d\n",countNode);
        break;

      case 7:
        display(start);
        break;

      case 8:
        printf("Enter the new node data:\n");
        scanf("%d",&data);
        printf("Enter the item:\n");
        scanf("%d",&item);
        start = insertBefore(start,data,item);
        break;

      case 9:
        printf("Enter the new node data:\n");
        scanf("%d",&data);
        printf("Enter the item:\n");
        scanf("%d",&item);
        start = insertAfter(start,data,item);
        break;

      case 10:
        printf("Enter the new node data:\n");
        scanf("%d",&data);
        printf("Enter the pos:\n");
        scanf("%d",&pos);
        start = insertAtPos(start,data,pos);
        break;

      case 11:
        printf("Enter the node data to be deleted:\n");
        scanf("%d",&data);
        start = deleteNode(start,data);
        break;

      case 0:
        printf("\nExiting the query!\n");
        return EXIT_SUCCESS;

      default:
        printf("\nError in ip[%d]; enter correct option from the menu\n",choice);
        break;
    }
  }while(choice);
}
