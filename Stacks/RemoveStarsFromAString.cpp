#include "iostream"
#include "stack"
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        deque<char> stk;
        for(int i=0; i< s.size(); i++) {
            if (s[i] == '*') {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(s[i]);
            }
        }
        string res = "";
        while (!stk.empty()){
            res += stk.front();
            stk.pop_front();
        }
        return res;
    }
};
int main(){
    Solution s;
    cout << s.removeStars("leet**cod*e") << endl;
    cout << s.removeStars("erase*****") << endl;
}
