// Hi, here's your problem today. This problem was recently asked by LinkedIn:

// Given a non-empty array where each element represents a digit of a non-negative integer, add one to the integer. The most significant digit is at the front of the array and each element in the array contains only one digit. Furthermore, the integer does not have leading zeros, except in the case of the number '0'.

// Example:
// Input: [2,3,4]
// Output: [2,3,5]

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printVector(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << ", ";
        s.pop();
    }
}

stack<int> plusOne(vector<int> digits)
{
    stack<int> ans;
    int len = digits.size();
    int i = len - 1;
    int carry = 1;
    while (i > -1)
    {
        int sum = digits[i] + carry;
        carry = sum / 10;
        if (carry > 0)
        {
            ans.push(sum % 10);
        }
        else
        {
            ans.push(sum+carry);
            i--;
            break;
        }
        i--;
    }
    while (i > -1)
    {
        ans.push(digits[i]);
        i--;
    }
    if(carry){
        ans.push(carry);
    }
    return ans;
}

int main()
{
    vector<int> digits{ 9};
    printVector(plusOne(digits));
    return 0;
}