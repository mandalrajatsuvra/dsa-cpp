#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;


class Solution{
    int solve(vector<int>& A, int B){
        return countSubArraysWithAtMostKDistinctElements(A, B)- countSubArraysWithAtMostKDistinctElements(A, B-1);
    }
    int countSubArraysWithAtMostKDistinctElements(vector<int>& arr, int k){
        int ans = 0;
        unordered_map<int, int> mp;
        int n = arr.size();
        int i =0;
        int j =0;
        while(j < n){
            mp[arr[j]]++;
            while(mp.size() > k){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0){
                    mp.erase(arr[i]);
                }
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};

// https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

