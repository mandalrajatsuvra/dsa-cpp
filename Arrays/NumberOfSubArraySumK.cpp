#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        for(int i=0; i< nums.size(); i++){
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()){
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v1{1, 1, 1};
    cout << s.subarraySum(v1, 2) << endl;

    vector<int> v2{1, 2, 3};
    cout<< s.subarraySum(v2, 3) << endl;

    vector<int> v3{0, 1, 0, 2, 0 , 0, 3};
    cout << s.subarraySum(v3, 3) << endl;


}

// Question https://leetcode.com/problems/subarray-sum-equals-k/description/
