#!/usr/bin/python

# import modules used here 
import sys
import pdb

#define a "func" function that takes two arguments and returns result.
def func ():
    """ 
    comment
    """ 

    result = 'hello'
    list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    i = 0
    while i < len(list): 
        print list[i]
        i = i + 3
    #pdb.set_trace()
    #return result

def main():
    func()

#Standard boilerplte to call the main() function to begin
# the program.

if __name__ == '__main__':
    main()
