/*Given a string s and an integer k, return the length of the longest substring of s such
 * that the frequency of each character in this substring is greater than or equal to k.

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.*/

#include "iostream"
#include "string"
#include "unordered_map"
#include "unordered_set"
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxi = INT_MIN;
        unordered_map<char, int> mp;
        unordered_set<char> st;
        for(int i=0; i< s.size(); i++){
            if(mp.find(s[i]) == mp.end()){
                st.insert(s[i]);
            }
            mp[s[i]]++;
            if(mp[s[i]] == k){
                st.erase(s[i]);
            }
            if(st.empty()){
                maxi = max(maxi, i+1);
            }
        }

        if(maxi != INT_MIN){
            return maxi;
        }

        for(int i= 0; i< s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]] --;
                if(mp[s[i]] == 0){
                    if(st.find(s[i]) == st.end()){
                        st.erase(s[i]);
                    }
                    if(st.empty()){
                        return s.size() - i;
                    }
                }
            }
        }
        return -1;

    }
};

int main(){



}

