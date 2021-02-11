#include <iostream>
#include <vector>
#include <string>

using namespace std;

string shortest_path(string path){
    vector<string> v;
    string ans = "";
    int n = path.length();
    for (int i = 0; i < n; i++)
    {
        int start = i;
        while(i<n && path[i]!='/'){
            i++;
        }
        string dir = path.substr(start, i-start);
        if(dir==".."){
            if(!v.empty())
                v.pop_back();
        } else if(dir=="."||dir==""){
            //do nothing
        } else {
            v.push_back(dir);
        }
    }
    for(string dir: v){
        ans.append("/");
        ans.append(dir);
    }
    if(ans==""){
        ans = "/";
    }
    return ans;
}

int main(){
    string path = "/Users/Joma/Documents/../Desktop/./../";
    std::cout<<shortest_path(path)<<endl;
    return 0;
}