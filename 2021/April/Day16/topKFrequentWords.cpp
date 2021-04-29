#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

class CompareClass {
    public:
        bool operator() (pair<string, int> a, pair<string, int> b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        }
};

int main(){
    string wordArr[] = {"daily", "interview", "pro", "pro", "for", "daily", "pro", "problems"};
    int k=2;
    int n = sizeof(wordArr)/sizeof(wordArr[0]);
    unordered_map<string, int> um;
    for (int i = 0; i < n; i++)
        um[wordArr[i]]++;
 
    priority_queue<string, vector<pair<string, int>>, CompareClass> pq(um.begin(), um.end());
    for(int i=0; i<k;i++){
        cout<<pq.top().first<<",";
        pq.pop();
    }
    return 0;
}