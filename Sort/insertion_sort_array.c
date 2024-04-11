/*
 * Insertion sort for array of intergers.
 *
 *         Tips: Don't used "\n" with scanf
 */

#include <stdio.h>
#include <stdlib.h>

void insert_sort(int arr[], int num)
{
    int valueToInsert;
    int holePos;
    int i;

    for (i = 1; i < num; i++) {
        // The values in A[ i ] are checked in-order, starting at the second one
        // save A[i] to make a hole that will move as elements are shifted
        // the value being checked will be inserted into the hole's final position
        valueToInsert = arr[i];
        holePos = i;
        // keep moving the hole down until the value being checked is larger than 
        // what's just below the hole <!-- until A[holePos - 1] is <= item -->

        while (holePos > 0 && valueToInsert < arr[holePos - 1]) 
        { // value to insert doesn't belong where the hole currently is, so shift
            arr[holePos] = arr[holePos - 1]; //shift the larger value up
            holePos -= 1;                    //move the hole position down
        }
        // hole is in the right position, so put value being checked into the hole
        arr[holePos] = valueToInsert;
    }
}


int main ()
{
    int num, N, i;
    int Array[20];

    printf("\n\n\t Enter number of the intergers: ");
    scanf("%d", &N);
    printf("Entered number : %d \n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &Array[i]);
    }
    printf("\nEntered Array Elements : ");
    for (i = 0; i < N; i++) {
        printf("%d\t", Array[i]);
    }

    /*
     * Array based insertion sort
     */
    insert_sort(Array, N);

    printf("\nSorted Array Elements : ");
    for (i = 0; i < N; i++) {
        printf("%d\t", Array[i]);
    }
}

