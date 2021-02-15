// Hi, here's your problem today. This problem was recently asked by Twitter:

// Given an array of integers of size n, where all elements are between 1 and n inclusive, find all of the elements of [1, n] that do not appear in the array. Some numbers may appear more than once.

// Example:
// Input: [4,5,2,6,8,2,1,5]
// Output: [3,7]

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> nums){
    for(int num: nums){
        cout<<num<<",";
    }
    cout<<"\n";
}
void printVector(vector<bool> nums){
    for(bool num: nums){
        cout<<num<<",";
    }
    cout<<"\n";
}

vector<int> findDisappearedNumbers(vector<int> nums){
    vector<int> registry(nums.size()+1);
    vector<int> ans;
    for(int num: nums){
        registry[num] = 1;
    }
    printVector(registry);

    for(int i=1;i<registry.size();i++){
        if(registry[i]==0){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    vector<int> nums{4,5,2,6,8,2,1,5};
    printVector(findDisappearedNumbers(nums));
    return  0;
}