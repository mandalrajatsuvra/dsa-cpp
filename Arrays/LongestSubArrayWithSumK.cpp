#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution{
public:
    int lenOfLongSubArray(int A[],  int N, int K)
    {
        int maxi = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += A[i];
            if(mp.find(sum - K) != mp.end()){
                maxi = max(maxi, i - mp[sum-K]);
            }else{
                mp[sum] = i;
            }
        }
        return maxi;
    }

};
int main(){
    Solution s;
    int A[] = {10, 5, 2, 7, 1, 9};
    cout << s.lenOfLongSubArray(A, 6, 15) << endl;
}

// Question https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1