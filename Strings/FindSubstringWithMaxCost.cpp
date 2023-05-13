#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals){
        unordered_map<char, int> mp;
        for(int i=0; i< chars.size(); i++) {
            mp[chars[i]] = vals[i];
        }
        int n = s.size();
        vector<int> v(n, 0);
        for(int i=0; i< s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                v[i] = mp[s[i]];
            }else{
                v[i] = s[i] - 'a' + 1;
            }
        }

        int curr = 0;
        int maxi = 0;
        for(int i=0; i< n; i++){
            curr += v[i];
            maxi = max(maxi, curr);
            if(curr < 0){
                curr = 0;
            }
        }
        return maxi;
    }
};


int main(){
    Solution s;
    vector<int> v{-1000};
    cout << s.maximumCostSubstring("adaa", "d", v) << endl;
    vector<int> v1 {-1,-1, -1};
    cout << s.maximumCostSubstring("abc", "abc", v1)<< endl;
}

//Question https://leetcode.com/problems/find-the-substring-with-maximum-cost/
