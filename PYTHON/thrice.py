#!/usr/bin/python

# import modules used here 
import sys
import pdb

#define a "repeat" function that takes two arguments.
def repeat (s, exclaim):
    """ Returns the string s repeated 3 times.
    If exclaim is true, add exclaimation marks.
    """ 

    result = s + s + s # can also use s*3
    if exclaim:
        result = result + '!!!'

    pdb.set_trace()
    return result


def main():
    print repeat('Yay', False)
    print repeat('Woo Hoo', True)

#Standard boilerplte to call the main() function to begin
# the program.

if __name__ == '__main__':
    main()



