Find Merge Point of Two Lists
by harsha_s
Problem
Submissions
Leaderboard
Discussions
Problem Statement

This challenge is part of a tutorial track by MyCodeSchool

You’re given the pointer to the head nodes of two linked lists that merge together at some node. Find the node at which this merger happens. The two head nodes will be different and neither will be NULL.

[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q

In the above figure, both list merges at node x.

Input Format 
You have to complete the int FindMergeNode(Node* headA, Node* headB) method which takes two arguments - the heads of the linked lists. You should NOT read any input from stdin/console.

Output Format 
Find the node at which both lists merge and return the data of that node. Do NOT print anything to stdout/console.

Sample Input

 1
  \
   2--->3--->NULL
  /
 1


1--->2
      \
       3--->Null
      /
     1
Sample Output

2
3
Explanation 
1. As shown in the Input, 2 is the merge point. 
2. Similarly 3 is merging point

/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/


int compareList(Node *node1, Node *node2)
{
    while (node1 != NULL && node2 != NULL &&
           node1->data == node2->data) {
           node1 = node1->next;
           node2 = node2->next;
    }
    if (node1 == NULL && node2 == NULL) return 1;
    else return 0;
}

int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    int match;
    while (headA != NULL) {
        struct Node *nodeB = headB;
        while (nodeB != NULL) {
            
            if (headA->data == nodeB->data) {
               /* found potential merge point */
               match = compareList(headA, nodeB);
               if (match) return headA->data;
            } else {
               nodeB = nodeB->next;
            }
        }      
        headA = headA->next;
    }
    return 0;
}

