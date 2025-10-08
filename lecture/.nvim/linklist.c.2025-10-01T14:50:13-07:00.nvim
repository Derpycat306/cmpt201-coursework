#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNode(int data) {
  struct Node *newNode = malloc(sizeof(*newNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void append(struct Node **head, int data) {
  if (*head == NULL) {
    *head = createNode(data);
    return;
  }

  struct Node *node = *head;
  while (node->next != NULL) {
    node = node->next;
  }
  node->next = createNode(data);
}

void traverse(struct Node *head) {
  if (head == NULL) {
    printf("{}");
    return;
  }

  printf("{%i", head->data);
  head = head->next;
  while (head != NULL) {
    printf(", %i", head->data);
    head = head->next;
  }
  printf("}");
}

int main() {

  struct Node *head = NULL;

  append(&head, 1);
  append(&head, 2);
  append(&head, 3);

  printf("Linked List: ");
  traverse(head);
}
