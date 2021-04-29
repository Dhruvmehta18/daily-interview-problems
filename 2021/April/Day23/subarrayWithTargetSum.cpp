// Hi, here's your problem today. This problem was recently asked by Amazon:

// You are given an array of integers, and an integer K. Return the subarray which sums to K. You can assume that a solution will always exist.

/*
    Input - [1, 3, 2, 5, 7, 2]
            k = 14
    Output - [2, 5, 7]
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v){
    for(int c: v){
        cout<<c<<" ";
    }
}

vector<int> find_continuous_k(vector<int> list, int k){
    int sum = 0;
    int start = 0;
    int i = 0;
    for(; i < list.size(); ){
        while(sum>k){
            sum -= list[start++];
        }
        if(sum == k){
            break;
        }
        sum += list[i++];
    }
    vector<int> subList(&list[start], &list[i]);
    return subList;
}

int main(){
    vector<int> list{1, 3, 2, 5, 7, 2};
    int k = 1;
    printVector(find_continuous_k(list, k));
    return 0;
}