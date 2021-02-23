// Hi, here's your problem today. This problem was recently asked by Uber:

// You are given a list of n numbers, where every number is at most k indexes away from its properly sorted index. Write a sorting algorithm (that will be given the number k) for this list that can solve this in O(n log k)

// Example:
// Input: [3, 2, 6, 5, 4], k=2
// Output: [2, 3, 4, 5, 6]
// As seen above, every number is at most 2 indexes away from its proper sorted index.

#include <iostream>
#include <queue>

using namespace std;

void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void sort_partially_sorted(int arr[], int n, int k){
    priority_queue<int, vector<int> ,greater<int> > pq(arr, arr + k+1);
    int index = 0;
    for(int i=k+1; i<n; i++){
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main(){
    int arr[] = {3,2,6,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    sort_partially_sorted(arr, n, k);
    cout<<"Sorted array is:"<<endl;
    printArray(arr, n);
    return 0;
}