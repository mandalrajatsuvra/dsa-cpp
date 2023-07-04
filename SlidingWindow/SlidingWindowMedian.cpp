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
        vector<double> vt;
        multiset<int> minHeap;
        for(int i=0; i< nums.size(); i++){
            minHeap.insert(nums[i]);
        }
        minHeap.erase(minHeap.find(3));
        cout << minHeap.size();

        return vt;
    }
};

int main(){
    Solution s;
    vector<int> v{3,3,3,3,5,3,3,7};
    vector<int> vt;
    vt.push_back(1);
    vt.push_back(2);
    vt.insert(vt.end(), v.begin(), v.end());

    //vector<double> res = s.medianSlidingWindow(v, 3);
    for(int x: vt){
        cout << x << " ";
    }
    cout << endl;

}

