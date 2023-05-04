#include <cstring>
#include "iostream"
#include "string"


using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapStoT[256];
        int mapTtoS[256];
        memset(mapStoT, -1, sizeof(mapStoT));
        memset(mapTtoS, -1, sizeof(mapTtoS));
        for(int i=0; i< s.size(); i++){
            if(mapStoT[s[i]] == -1 && mapTtoS[t[i]] == -1){
                mapStoT[s[i]] = t[i];
                mapTtoS[t[i]] = s[i];
            }else if(mapStoT[s[i]] != t[i] || mapTtoS[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
};



int main(){
    Solution s;
    cout << s.isIsomorphic("abc", "def") << endl;
}


// Question: https://leetcode.com/problems/isomorphic-strings/description/