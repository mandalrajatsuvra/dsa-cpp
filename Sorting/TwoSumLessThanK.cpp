#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxi = -1;
        for(int i=0; i< n; i++){
            int j = binarySearch(nums,  i+1,  n-1, k - nums[i] - 1);
            if(j != -1){
                maxi = max(maxi, nums[i] + nums[j]);
            }
        }
        return maxi;
    }
    int binarySearch(vector<int> &arr, int  left,  int right, int x){
        int res = -1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if( arr[mid] <= x ){
                res = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums{34,23,1,24,75,33,54,8};
    cout << s.twoSumLessThanK(nums, 60) << endl;
    vector<int> nums2{10,20,30};
    cout << s.twoSumLessThanK(nums2, 15)<< endl;


}

