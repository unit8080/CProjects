/*
Problem Statement

Your teacher has given you the task of drawing a staircase structure. Being an expert programmer, you decided to make a program to draw it for you instead. Given the required height, can you print a staircase as shown in the example?

Input 
You are given an integer N depicting the height of the staircase.

Output 
Print a staircase of height N that consists of # symbols and spaces. For example for N=6, here's a staircase of that height:

     #
    ##
   ###
  ####
 #####
######
*/


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int j;
    printf(" Enter number of steps in staircase :");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        j = n - i;
        for (int x = 0; x < j; x++)
            printf(" ");
        for (int x = 0; x < i; x ++)
            printf("#");
        printf("\n");
    }
    return 0;
}
