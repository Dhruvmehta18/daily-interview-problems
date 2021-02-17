// Hi, here's your problem today. This problem was recently asked by Apple:

// You are given two strings, A and B. Return whether A can be shifted some number of times to get B.

// Eg. A = abcde, B = cdeab should return true because A can be shifted 3 times to the right to get B. A = abc and B= acb should return false.

#include<iostream>
#include<string>

using namespace std;

bool isShifted(string s1, string s2){
    if(s1.length()!=s2.length()) return false;

    string temp = s1 + s1;
    return (temp.find(s2)!=string::npos);
}

int main(){
    string s1 = "abcde";
    string s2 = "cdeab";
    cout<<isShifted(s1, s2)<<endl;
    return 0;
}