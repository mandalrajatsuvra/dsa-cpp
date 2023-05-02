#include "iostream"
#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string s = "";
        vector<int> v(n, 0);
        int t = n-1;
        int sum = n;
        while(t >= 0){
            if(sum == k){
                break;
            }
            if(v[t] < 25){
                v[t] ++;
                sum ++;
            }else{
                t--;
            }
        }
        for(int i=0; i< n; i++){
            s += (char)(v[i]+'a');
        }
        return s;
    }
};
int main(){
    Solution s;
    cout << s.getSmallestString(3, 27) <<endl;
}
//Question:-  https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/description/