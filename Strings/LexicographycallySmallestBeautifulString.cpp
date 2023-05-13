#include "iostream"
#include "string"
#include "vector"
#include "unordered_set"

using namespace std;
class Solution {
public:
    /*
     * abcz
     * [1, 2, 3, 26];
     *
     * Incomplete
     * */

    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        vector<int> v(n, 0);
        for(int i=0; i< n; i++){
            v[i] = s[i] - 'a' + 1;
        }

        int t = n-1;
        while (  t >= 0 ){
            v[t] = v[t] + 1;
            int carry = v[t]/ 26;
            int val = v[t] % 26;
            v[t] = val;
            if(carry > 0){
                v[t-1] = v[t-1] + carry;
            }









        }





    }
};

int main(){


}





