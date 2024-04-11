#include <stdio.h>
#include <stdbool.h>
int A[] = {5, 6, 6, 6, 2, 7, 8, 21, 14};
//`int A[] = {21, 4, 1, 3, 9, 20, 0, 25, 6, 21, 14};
//int A[] = {};
//int A[] = {0, -1, 0};

struct nums {
    int first;
    int second;
    int third;
};
void _qsort (int A[], int start, int end) 
{
    if (start >= end)
        return;

    int pivot = end;
    int i = start;
    while (i < pivot) {
        if (A[pivot] < A[i]) {
            int temp = A[i];
            A[i] = A[pivot -1];  // Can be optimized.
            A[pivot -1] = A[pivot];
            A[pivot] = temp;
            pivot = pivot - 1;
        } else {
            i = i +1;
        } 
    }
    _qsort(A, 0, pivot - 1);
    _qsort(A, pivot + 1, end);
}

int B[] = {0, -1, 2, -3, 1};
void find3SumZero (int A[], int len)
{
    if (len < 3) return;
    struct nums three[len/3 +1];

    _qsort(A, 0, len-1);
    int i = 0;
    int idx = 0;
    while (i < len-2) {
        int start = i +1;
        int end = len -1;
        while (start < end) {
            int s = A[i] + A[start] + A[end];
            if (s == 0) {
                //printf(" %d  %d  %d\n", A[i], A[start], A[end]);
                start++;
                end--;
                three[idx].first = A[i];
                three[idx].second = A[start];
                three[idx++].third = A[end];
            } else if (s > 0) {
                end --;
            } else {
                start++;
            }
        }
        i++;
    }
    int j =0;
    while (j < idx) {
        printf(" %d  %d  %d\n", three[j].first, three[j].second, three[j].third);
        j++;
    }
}

bool find3sum (int A[], int len, int sum) 
{
    if (len < 3) return false;
    bool found = false;
    _qsort(A, 0, len-1);
    int i = 0;
    while (i < len -2) {
        int l = i + 1;
        int r = len - 1;
        while (l < r) {
            int temp = A[i] + A[l] + A[r];
            if (temp == sum) {
                printf(" %d %d %d \n", A[i], A[l], A[r]);
                //return true;
                found = true;
                l++; r --;
            } else if (temp < sum) {
                l++;
            } else {
                r--;
            }
        }
        i++;
    }
    return found;
}

int main(void) {
    int l = sizeof(B)/sizeof(B[0]);
    printf("3sumZero found :\n");
    find3SumZero(B, l);
    getchar();
    int len = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < len; i++)
        printf(" %d", A[i]);
    printf("\n");
    printf("3sum %d found %s\n", 18, find3sum(A, len, 18) ? "Yes" : "No");
    //_qsort(A, 0, len -1);
    for (int i = 0; i < len; i++)
        printf(" %d", A[i]);
    printf("\n");
}
