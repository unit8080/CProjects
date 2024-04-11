#include <iostream>
using namespace std;

int sqrt (int x) {
    if (x == 0 || x == 1)
        return x;
    int ans = 1;
    int start = 0, end = x/2;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (mid == x/mid)
            return mid;
        else if (mid < x/mid) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        } 
    }
    return ans;
}
int main (void) {
    int x;
    cout << "Enter number: ";;
    cin >> x;
    cout << sqrt(x) << endl;
}
