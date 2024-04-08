#include <iostream>
#include <string>

using namespace std;
int main (void)
{
    string str ("Test string");
    for (unsigned int i = 0; i < str.length(); i++) {
        cout << str.at(i);
    }
}
