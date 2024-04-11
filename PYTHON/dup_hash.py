#!/usr/bin/python

# import modules used here 
import sys
import pdb

#define a "func" function that takes two arguments and returns result.
def func ():
    """ 
    comment
    """ 

    arr = [3, 2, -5, -5, 6, 5, -5, 4, -3, -4, -6]
    str = "hello"
    for ch in str:
        #pdb.set_trace()
        print ch
    hash_tbl = {}
    l = len(arr)
    for i in range(l):
        if abs(arr[i]) in hash_tbl.keys():
            if arr[i] < 0 and hash_tbl(abs(arr[i])) > 0:
                print abs(arr[i]), arr[i]
            elif arr[i] > 0 and hash_tbl(arr[i]) < 0:
                print arr[i], -arr[i]
        else:
            if arr[i] < 0:
                hash_tbl(abs(arr[i])) -= 1
            else:
                hash_tbl(arr[i]) += 1


def main():
    func()

#Standard boilerplte to call the main() function to begin
# the program.

if __name__ == '__main__':
    main()

