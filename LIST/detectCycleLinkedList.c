Detect Cycle
by harsha_s
Problem
Submissions
Leaderboard
Discussions
Problem Statement

This challenge is part of a tutorial track by MyCodeSchool

You’re given the pointer to the head node of a linked list. Find whether the list contains any cycle (or loop). A linked list is said to contain cycle if any node is re-visited while traversing the list. The head pointer given may be null meaning that the list is empty.

Input Format 
You have to complete the int HasCycle(Node* head) method which takes one argument - the head of the linked list. You should NOT read any input from stdin/console. Number of nodes in a linked list doesn't exceed 100.

Output Format 
Check whether the linked list has a cycle and return 1 if there is a cycle. Otherwise, return 0. Do NOT print anything to stdout/console.

Sample Input

1 --> NULL

1 --> 2 --> 3
      ^     |
      |     |
       -----                           
Sample Output

0
1
Explanation 
1. First list has no cycle, hence return 0 
2. Second list is shown to have a cycle, hence return 1.

Note 
After first solving the problem by yourself, see Floyd's cycle-finding algorithm for an efficient solution which uses O(N) time and O(1) additional memory.

https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare


/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int HasCycle(Node* head)
{
   // Complete this function
   // Do not write the main method
   if (head == NULL) return 0;
   
   int count = 0;
   struct Node *slow, *fast;
    
   slow = head;
   fast = slow->next;
   while (count++ <= 100 && fast != NULL && fast->next != NULL) {
       if (fast == slow || fast->next == slow) {
           return 1;
       }
       slow = slow->next;
       fast = fast->next->next;
   }
   return 0;
}


