#include "stdio.h"
#include "stdlib.h"

struct node
{
  int data;
  struct node *next;
};

typedef struct node list;

list *createNode()
{
  list *newNode = (list *)malloc(sizeof(list));
  printf("\nEnter the value: ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;
  return newNode;
}

void append(list *list1)
{
  list *tmp = list1;
  for (; tmp->next != NULL; tmp = tmp->next)
    ;
  tmp->next = createNode();
  printf("Element added succesfully.");
}

void insert(list *list1)
{
  int key;
  printf("\nWhere do you want to insert? Before ");
  scanf("%d", &key);
  list *tmp = list1;
  while (tmp->next->next != NULL && key != tmp->next->data)
    tmp = tmp->next;
  if (tmp->next->data == key)
  {
    list *tmp1 = createNode();
    tmp1->next = tmp->next;
    tmp->next = tmp1;
  }
  else
    printf("\nElement not found.");
}

list *newList()
{
  int n;
  list *newList = (list *)malloc(sizeof(list));
  printf("\nHow many elements do you want to add? ");
  scanf("%d", &n);
  newList = createNode();
  printf("Element added succesfully.");
  for (int i = 0; i < n - 1; i++)
    append(newList);
  printf("\n\nList created succesfully.");
  return newList;
}

void pop(list *list1)
{
  list *tmp = list1;
  for (; tmp->next->next != NULL; tmp = tmp->next)
    ;
  printf("Popped element: %d", tmp->next->data);
  free(tmp->next);
  tmp->next = NULL;
}

void delete (list *list1)
{
  int key;
  printf("\nWhat do you want to remove? ");
  scanf("%d", &key);
  list *tmp = list1;
  while (tmp->next != NULL && key != tmp->data)
    tmp = tmp->next;

  //needs memory optimization
  if (tmp->data == key)
    tmp->next = tmp->next->next;
  else
    printf("\nElement not found.");
}

void display(list *list1)
{
  list *temp = list1;
  printf("\nThe elements are: ");
  while (temp != NULL)
  {
    printf("%d", temp->data);
    if (temp->next != NULL)
      printf(", ");
    else
      printf(".");
    temp = temp->next;
  }
}

int main(int argc, char const *argv[])
{
  list *list1;
  list1 = (list *)malloc(sizeof(list));
  int ch;
  while (1)
  {
    printf("\n==== MENU ====");
    printf("\n1. Create");
    printf("\n2. Append");
    printf("\n3. Insert");
    printf("\n4. Pop");
    printf("\n5. Delete");
    printf("\n6. Display");
    printf("\n0. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\nCreate new Singly Linked List...");
      list *list1 = newList();
      break;
    case 2:
      printf("\nAppend a new node...");
      append(list1);
      break;
    case 3:
      printf("\nInset a new node...");
      insert(list1);
      break;
    case 4:
      pop(list1);
      break;
    case 5:
      delete (list1);
      break;
    case 6:
      display(list1);
      break;
    case 7:
    case 0:
      printf("\nExiting...\n");
      return 0;
    default:
      printf("Invalid input.");
    }
  }
  return 0;
}
