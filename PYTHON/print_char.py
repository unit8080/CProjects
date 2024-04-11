#!/usr/bin/python

# import modules used here 
import sys
import pdb

#define a "func" function that takes two arguments and returns result.
def func ():
    """ 
    comment
    """ 

    str = "hello"
    for ch in str:
        #pdb.set_trace()
        print ch

def main():
    func()

#Standard boilerplte to call the main() function to begin
# the program.

if __name__ == '__main__':
    main()
