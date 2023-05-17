#include "iostream"
#include "string"
#include "unordered_set"
using namespace std;

class Solution{
public:
    string longestCommonPrefix (string arr[], int N)
    {
        int mini = INT_MAX;
        for(int i=0; i<N; i++) {
            mini = min(mini, static_cast<int>(arr[i].size()));
        }
        string res = "";
        for(int i=0; i< mini; i++){
            unordered_set<char> st;
            for(int t=0; t< N; t++){
               st.insert(arr[t][i]);
            }
            if(st.size() == 1){
                res += arr[0][i];
            }
        }
        return res == "" ? "-1": res;
    }
};