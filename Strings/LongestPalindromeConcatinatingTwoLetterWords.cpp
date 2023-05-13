#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int count = 0;
        for(int i=0; i< words.size(); i++){
            string  word = words[i];
            string rev = "";
            rev += word[1];
            rev += word[0];
            if(mp.find(rev) != mp.end()){
                count += 4;
                mp[rev] --;
                if(mp[rev] == 0){
                    mp.erase(rev);
                }
            }else{
                mp[word]++;
            }
        }
        int maxi = INT_MIN;
        for(auto &[key, value]: mp){
            if(key[0] == key[1]){
                maxi = max(maxi, 2*value);
            }
        }
        return maxi != INT_MIN ?  count + maxi : count;
    }
};

int main(){
    Solution s;
    vector<string> v{"lc","cl","gg"};
    cout << s.longestPalindrome(v) << endl;

}


