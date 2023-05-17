#include "iostream"
#include "vector"
using namespace std;



class Solution{
public:
    int minJumps(int arr[], int n){
        vector<int> dp(n+1, -1);
        return f(0, n, arr, dp);
    }
    int f(int i, int n, int arr[], vector<int>& dp){
        if(i >= n-1){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int mini = 1e7;
        for(int k=1; k<= arr[i]; k++){
            int t = 1 + f(i+k, n, arr, dp);
            mini = min(mini, t);
        }
        return dp[i] = mini;
    }
};