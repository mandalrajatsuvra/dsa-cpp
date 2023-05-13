#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j =-1;
        int zc = 0;
        int maxConsecutiveOnes = 0;
        while (j < n) {
            while (zc <= 1 && j < n) {
                maxConsecutiveOnes = max(maxConsecutiveOnes, j - i + 1);
                j++;
                if (j < n && nums[j] == 0) {
                    zc++;
                }
            }
            while (zc > 1  && i < n) {
                if (nums[i] == 0) {
                    zc--;
                }
                i++;
            }
        }
        return maxConsecutiveOnes;
    }
};

int main(){
    Solution s;
    vector<int> v{1,0,1,1,0,1};
    cout << s.findMaxConsecutiveOnes(v) << endl;
    vector<int> v2{1,1,0, 1,1,1, 0, 1,1,1 ,1, 0, 1};
    cout << s.findMaxConsecutiveOnes(v2) << endl;
    vector<int> v3{1,1, 0, 1};
    cout << s.findMaxConsecutiveOnes(v3) << endl;

}

//leetcode 487 https://leetcode.com/problems/max-consecutive-ones-ii/
// notice the boundary check conditions.


