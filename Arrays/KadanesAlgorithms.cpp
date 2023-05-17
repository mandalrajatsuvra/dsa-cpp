#include "iostream"
#include "vector"
using namespace std;


class Solution{
public:
    long long maxSubarraySum(int arr[], int n){
        long long maxi = LONG_LONG_MIN;
        long long curr_sum = 0;
        for(int i=0; i< n; i++){
            curr_sum += arr[i];
            maxi = max(maxi, curr_sum);
            if(curr_sum < 0){
                curr_sum = 0;
            }
        }
        return maxi;
    }
};