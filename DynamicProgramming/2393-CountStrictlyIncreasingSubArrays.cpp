#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int left = 0, right = 0;
        int len = nums.size();
        long long cnt = 0;
        while(right < len){
            if(left == right){
                cnt ++;
            }else{
                if(nums[right] > nums[right-1]){
                    cnt += (right- left + 1);
                }else{
                    cnt += 1;
                    left = right;
                }
            }
            right++;
        }
        return cnt;
    }
};

int main(){

}







