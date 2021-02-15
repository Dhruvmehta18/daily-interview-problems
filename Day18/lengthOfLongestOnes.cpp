// Hi, here's your problem today. This problem was recently asked by Microsoft:

// Return the longest run of 1s for a given integer n's binary representation.

// Example:
// Input: 242
// Output: 4
// 242 in binary is 0b11110010, so the longest run of 1 is 4.

#include <iostream>

using namespace std;

int longestRun(int n){
    int count = 0;
    while(n!=0){
        n = (n & (n << 1));
        count++;
    }
    return count;
}

int main(){
    cout<<longestRun(242)<<endl;
    return 0;
}