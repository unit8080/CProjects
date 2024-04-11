#!/usr/bin/python

# import modules used here 
import sys
import pdb

#define a "func" function that takes two arguments and returns result.
def write_ticket():
    print 'You are so busted'
    print 'Have a nice day'

def func (speed, mood):
    if speed >= 80:
        print 'License and registration please'
    if mood == 'terrible' or speed >= 100:
        print 'You have the right to remain silent.'
    elif mood == 'bad' or speed >= 90:
        print "I'm going to have to write you a ticket."
        write_ticket()
    else:
        print "Let's try to keep it under 80 ok?"

    pdb.set_trace()
    return

def main():
    func (100, 'good')
    func (95, 'good')

#Standard boilerplte to call the main() function to begin
# the program.

if __name__ == '__main__':
    main()
