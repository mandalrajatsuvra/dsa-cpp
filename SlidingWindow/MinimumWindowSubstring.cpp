/*Given two strings s and t of lengths m and n respectively, return the minimum window
        substring
of s such that every character in t (including duplicates) is included in the window. If there is no such
substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.*/


#include "iostream"
#include "unordered_map"
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(int i=0; i< t.size(); i++){
            mp[t[i]] ++;
        }
        int start = 0;
        int end = 0;
        int min_length = INT_MAX;
        int count = mp.size();
        int j=0;
        int i=0;
        while(j < s.size()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]] --;
                if(mp[s[j]] == 0 && count > 0){
                    count--;
                }
            }
            while(count == 0){
                if(j-i+1 < min_length){
                    min_length = j-i +1;
                    start = i;
                    end = j;
                }
               if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        if(start == -1 || end == -1){
            return "";
        }
        return s.substr(start, end-start+1);
    }
};



int main(){
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
}
