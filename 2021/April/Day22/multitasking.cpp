// Hi, here's your problem today. This problem was recently asked by AirBNB:

// We have a list of tasks to perform, with a cooldown period. We can do multiple of these at the same time, but we cannot run the same task simultaneously.

// Given a list of tasks, find how long it will take to complete the tasks in the order they are input.
// tasks = [1, 1, 2, 1]
// cooldown = 2
// output: 7 (order is 1 _ _ 1 2 _ 1)

#include <iostream>
#include <unordered_set>

using namespace std;

int findTime(int arr[], int n, int cooldown){
    int index = 0;
    int ans = 0;
    while(index < n){
        unordered_set<int> s;
        for(; index <= index+cooldown && index < n; index++){
            if(s.find(arr[index]) != s.end()){
                break;
            }
            s.insert(arr[index]);
        }
        if(index < n)
            ans += cooldown + 1;
        else
            ans += s.size();
    }

    return ans;
}

int main(){
    int arr[] = {1,2,3,1};
    int cooldown = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findTime(arr, n, cooldown)<<endl;
    return 0;
}