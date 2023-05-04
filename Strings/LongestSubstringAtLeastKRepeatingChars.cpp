#include "iostream"
#include "string"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int distinctCharCount = cuntOfDistinctChars(s);
        int n = s.size();
        int res = 0;
        for(int noOfDistChars = 1; noOfDistChars <= distinctCharCount; noOfDistChars ++ ) {
            int i = 0, j = -1;
            unordered_map<char, int> mp;
            int t = 0;
            while (j < n) {
                while (mp.size() <= noOfDistChars) {
                    j++;
                    mp[s[j]]++;
                    if (mp[s[j]] == k) {
                        t++;
                    }
                    if (t == noOfDistChars && mp.size() == noOfDistChars) {
                        res = max(res, j - i + 1);
                    }
                }
                while (mp.size() > noOfDistChars) {
                    if (mp[s[i]] == k) {
                        t--;
                    }
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
        }
        return res;
    }
    int cuntOfDistinctChars(string s){
        bool countMap[26] = {0};
        int cnt = 0;
        for(int i=0; i< s.size(); i++){
            if(!countMap[s[i] - 'a']){
                cnt ++;
                countMap[s[i]-'a'] = true;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    cout << s.longestSubstring("aaabb", 3) << endl;
}


//Question: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/


