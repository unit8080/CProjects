#include <stdio.h>
//int A[] = { 10, 20 , 30 , 40 , 50 , 60 }; // even intersection
//int B[] = { 11, 20, 31, 40, 51, 60 };     // even intersection
int A[] = { 10, 20 , 30 , 40 , 50 , 60 }; // no intersection
int B[] = { 11, 21, 31, 41, 51, 61 };     // no intersection
//int A[] = {}; // empty array
//int B[] = {}; // empty array

int findArrayIntersection(int A[], int B[], int C[], int lenA, int lenB)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < lenA && j < lenB) {
        if (A[i] == B[j]) {
            C[k] = A[i];
            k++;
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
    return k;
}
int findArrayUnion(int A[], int B[], int C[], int lenA, int lenB)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < lenA && j < lenB) {
        if (A[i] < B[j]) {
            C[k] = A[i];
            k++;
            i++;
        } else if (A[i] > B[j]) {
            C[k] = B[j];
            k++;
            j++;
        } else {
            C[k] = B[j];
            k++;
            i++;
            j++;
        }
    }
    while (i < lenA) {
        C[k++] = A[i++];
    }
    while (j < lenB) {
        C[k++] = B[j++];
    }
    return k;
}
int main()
{
    int lenA = sizeof(A)/sizeof(A[0]);
    int lenB = sizeof(B)/sizeof(B[0]);

    int C[lenA > lenB ? lenA: lenB];
    int lenC = 0;
    lenC = findArrayIntersection(A, B, C, lenA, lenB);
    printf("\n Array intersection [] = ");
    for (int i=0; i < lenC; i++)
        printf(" %d ", C[i]);
    printf("\n");

    // Array union 
    int D[lenA + lenB];
    int lenD = findArrayUnion(A, B, D, lenA, lenB);
    printf("\n Array Union [] = ");
    for (int i=0; i < lenD; i++)
        printf(" %d ", D[i]);
    printf("\n");
}
