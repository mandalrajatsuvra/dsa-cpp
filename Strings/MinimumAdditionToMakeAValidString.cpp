#include "iostream"
#include "string"
#include "unordered_set"
using namespace std;
class Solution {
public:
    int addMinimum(string word) {
        int cnt = 0;
        unordered_set<char> st;
        char prev = 0;
        for(int i=0; i< word.size(); i++){
            if(word[i] > prev){
                st.insert(word[i]);
            }else{
                cnt += (3 - st.size());
                st.clear();
                st.insert(word[i]);
            }
            prev = word[i];
        }
        if(!st.empty()){
            cnt += (3 - st.size());
        }
        return cnt;
    }
};

int main(){
    Solution s;
    cout << s.addMinimum("accbc")<< endl;

}

//https://leetcode.com/problems/minimum-additions-to-make-valid-string/
