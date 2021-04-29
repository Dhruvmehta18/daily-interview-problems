// Hi, here's your problem today. This problem was recently asked by Amazon:

// MS Excel column titles have the following pattern: A, B, C, ..., Z, AA, AB, ..., AZ, BA, BB, ..., ZZ, AAA, AAB, ... etc. In other words, column 1 is named "A", column 2 is "B", column 26 is "Z", column 27 is "AA" and so forth. Given a positive integer, find its corresponding column name.
// Examples:
// Input: 26
// Output: Z

// Input: 51
// Output: AY

// Input: 52
// Output: AZ

// Input: 676
// Output: YZ

// Input: 702
// Output: ZZ

// Input: 704
// Output: AAB

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void convertToTitle(int n)
{
    int i = 0;
    string str = "";
    string e = "";
    while (n > 0)
    {
        int rem = n % 26;
        if (rem == 0)
        {
            str = e + 'Z' + str;
            n = (n / 26) - 1;
        }
        else
        {
            str = e + char(rem - 1 + 'A') + str;
            n = n / 26;
        }
    }

    cout << str << endl;
}

int main()
{

    int input1 = 1;
    int input2 = 456976;
    int input3 = 28;

    convertToTitle(input1);
    convertToTitle(input2);
    convertToTitle(input3);
    return 0;
}