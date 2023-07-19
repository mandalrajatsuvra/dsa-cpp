#include "iostream"
#include "vector"
using namespace std;

// Incomplete

class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        int len = nums.size();
        vector<long long> dp(len, 0);
        if(nums[0] % 2 == 0){
            dp[0] = 1;
        }else{
            dp[0] = 0;
        }
        for(int i=1; i< nums.size(); i++){
            if(nums[i] % 2 == 0){
                dp[i] = i+1;
            }else{
                if(nums[i-1] % 2 ==0){
                    dp[i] = 1;
                }else{
                    dp[i] = 0;
                }
            }
        }
        long long res = 0;
        for(int i=0; i< dp.size(); i++){
            res += dp[i];
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> vt {9,6,7,13};
    cout << s.evenProduct(vt);
}
