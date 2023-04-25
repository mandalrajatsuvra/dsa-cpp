/*

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation:
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
1 [3  -1  -3] 5  3  6  7       -1
1  3 [-1  -3  5] 3  6  7       -1
1  3  -1 [-3  5  3] 6  7        3
1  3  -1  -3 [5  3  6] 7        5
1  3  -1  -3  5 [3  6  7]       6
Example 2:

Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]*/

#include "iostream"
#include "vector"
#include "queue"
#include "set"
using  namespace std;


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> v;
        auto minHeapComp = [](pair<int, int> a, pair<int, int> b){
            if(a.first == b.first){
                return true;
            }
            return a.second < b.second ? true: false;
        };
        auto maxHeapComp = [](pair<int, int> a, pair<int, int> b){
            if(a.first == b.first){
                return true;
            }
           return a.second > b.second ? true: false;
        };
        set<pair<int, int>, decltype(maxHeapComp)> maxHeap{maxHeapComp};
        set<pair<int, int>, decltype(minHeapComp)> minHeap{minHeapComp};

        int i =0;
        int j = 0;
        while (j < nums.size()){
            if(maxHeap.size() == minHeap.size()){
                if(maxHeap.empty()) {
                    maxHeap.insert({j, nums[j]});
                }else if(nums[j] < minHeap.begin()->second){
                    maxHeap.insert({j, nums[j]});
                }else{
                    auto min = minHeap.begin();
                    minHeap.erase(min);
                    maxHeap.insert(*min);
                    minHeap.insert({j, nums[j]});
                }
            }else if(maxHeap.size() > minHeap.size()){
                if(nums[j] < maxHeap.begin()->second){
                    auto max = maxHeap.begin();
                    maxHeap.erase(max);
                    minHeap.insert(*max);
                    maxHeap.insert({j, nums[j]});
                }else{
                    minHeap.insert({j,nums[j]});
                }

            }

            if(j-i +1 < k){
                j++;
            }else if(j-i+1 == k){
                if(k%2 == 0){
                    v.push_back(static_cast<double>(maxHeap.begin()->second) + static_cast<double>(minHeap.begin()->second)/2);
                }else{
                    v.push_back(static_cast<double>(maxHeap.begin()->second));
                }
                pair<int, int> iThPair = {i, nums[i]};
                if(minHeap.find(iThPair) != minHeap.end()){
                    minHeap.erase(iThPair);
                }else{
                    maxHeap.erase(iThPair);
                }

                if(maxHeap.size() > minHeap.size()){
                    auto max = minHeap.begin();
                    maxHeap.erase(max);
                    minHeap.insert(*max);
                }
                if(maxHeap.size() < minHeap.size() ){
                    auto min = minHeap.begin();
                    minHeap.erase(min);
                    maxHeap.insert(*min);
                }
                i++;
                j++;
            }



            auto it = maxHeap.begin();
            while (it!= maxHeap.end()){
                cout << it->second << "  ";
                it ++;
            }
            cout<< endl;

            it = minHeap.begin();
            while (it!= minHeap.end()){
                cout << it->second << "  ";
                it ++;
            }
            cout<< endl;

        }
        return v;
    }
};

int main(){
    Solution s;
    vector<int> v{1,3,-1,-3,5,3,6,7};
    vector<double> res = s.medianSlidingWindow(v, 3);
    for(int x: res){
        cout << x << " ";
    }
    cout << endl;

}

