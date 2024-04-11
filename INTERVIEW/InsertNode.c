/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
  struct Node *tmp = (struct Node *) malloc(sizeof(tmp));
  tmp->data = data;
  tmp->next = NULL;
  struct Node *current = head;
  struct Node *prev = NULL;
  while(position > 0) {
      prev = current;
      current = current->next;
      position--;
  }
  if (prev == NULL) {
      tmp->next = head;
      return tmp;
  } else {
      prev->next = tmp;
      tmp->next = current;
  }
  return head;
}


