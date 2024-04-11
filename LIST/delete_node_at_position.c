/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  struct Node *node = head;
  struct Node *prev = NULL;
    
  // Complete this method
  while (position > 0 && node != NULL) {
      prev = node;
      node = node->next;
      position--;
  }
    
  if (prev == NULL) {
      head = node->next;
      free(node);
      return head;
  } else {
      prev->next = node->next;
      free(node);
      return head;
  }
}

