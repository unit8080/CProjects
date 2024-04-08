/*
 * Binary Tree Data Sturcture declaration
 */
#ifndef TREE_H
#define TREE_H

typedef struct _T_Node {
    int   data;
    struct _T_Node  *parent;
    struct _T_Node  *left;
    struct _T_Node  *right;
    struct _T_Node  *next;
    int   height;
    unsigned int max_dis;
} treeNode;

#endif /* TREE_H */
