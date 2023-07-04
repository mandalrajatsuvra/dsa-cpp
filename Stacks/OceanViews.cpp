#include "iostream"
#include "vector"
#include "stack"

using namespace std;


class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        stack<int> au_res;
        stack<int> stk;
        for(int i = heights.size() - 1; i >= 0 ; i--){
            while (!stk.empty() && heights[i] > stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                au_res.push(i);
            }
            stk.push(heights[i]);
        }
        while (!au_res.empty()){
            res.push_back(au_res.top());
            au_res.pop();
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> heights = {1,3,2,4};
    vector<int> res = s.findBuildings(heights);
    for(int x: res){
        cout << x << " ";
    }
    cout << endl;
}
