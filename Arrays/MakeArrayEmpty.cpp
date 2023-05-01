#include "iostream"
#include "vector"
#include "queue"

using namespace std;
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        deque<int> dq;
        for(int i=0; i< nums.size(); i++){
            pq.push(nums[i]);
            dq.push_back(nums[i]);
        }
        long long op = 0;
        while (!dq.empty()){
            if(pq.top() == dq.front()){
                dq.pop_front();
                pq.pop();
            }else{
                int x = dq.front();
                dq.pop_front();
                dq.push_back(x);
            }
            op ++;
        }
        return op;
    }
};


