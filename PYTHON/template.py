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
    pdb.set_trace()
    return result

def main():
    print func()

#Standard boilerplte to call the main() function to begin
# the program.

if __name__ == '__main__':
    main()
