#include <stdio.h>
#include <stdbool.h>

int A[] = { 2, 3, 4, 5, 5, 5, 5, 5, 6, 6, 7, 8 };
int len = sizeof(A)/sizeof(A[0]);

int binarySearch(int A[], int len, int x, bool first)
{
    int low = 0; int high = len -1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high -low)/2;
        if (A[mid] == x) { // found target 
            result = mid;
            if (first) {
                high = mid -1;
            } else {
                low = mid+1;
            }
        } else if (A[mid] < x) {
            low = mid +1;
        } else {
            high = mid -1;
        }
    }
    return result;
}

int main(void)
{
    int first = binarySearch(A, len, 5, true);
    if (first == -1) {
        printf("Occurence not found\n");
    } else {
        int last = binarySearch(A, len, 5, false);
        printf("Count of occurrences : %d\n", last -first +1);
    }

}


