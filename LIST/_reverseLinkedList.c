/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
  if (head == NULL)
      return head;
  struct Node *node;
  struct Node *prev = NULL;
  struct Node *curr = head;
  
  while (curr != NULL) {
      node = curr;
      curr = curr->next;
      node->next = prev;
      prev = node;
  }
  return prev;
}

