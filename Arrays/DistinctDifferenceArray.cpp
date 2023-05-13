#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;


class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> prefix;
        unordered_map<int, int> suffix;
        vector<int> res;
        for(int i = 0; i< nums.size(); i++){
            suffix[nums[i]]++;
        }
        for(int i=0; i< nums.size(); i++){
            prefix[nums[i]] ++;
            if(suffix.find(nums[i]) != suffix.end()){
                suffix[nums[i]]--;
                if(suffix[nums[i]] == 0){
                    suffix.erase(nums[i]);
                }
            }
            res.push_back(prefix.size() - suffix.size());
        }
        return res;
    }
};

int main(){


}