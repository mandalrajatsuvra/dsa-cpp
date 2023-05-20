#include "iostream"
#include "vector"
using namespace std;

class Solution{
public:
    vector<int> maxone(vector<int>& A, int B){
        int maxStart = 0;
        int maxEnd = 0;

        int maxContiguousOnes = 0;
        int i=0, j=0;
        int ones=0;
        int zeroes = 0;

        while(j < A.size()){
            if(A[j] == 1){
                ones++;
            }else{
                zeroes ++;
            }
            while(zeroes > B){
                if(A[i] == 1){
                    ones --;
                }else{
                    zeroes --;
                }
                i++;
            }
            if(zeroes + ones > maxContiguousOnes){
                maxContiguousOnes = zeroes + ones;
                maxStart = i;
                maxEnd = j;
            }
            j++;
        }
        vector<int> res;
        for(int i=maxStart; i<= maxEnd; i++){
            res.push_back(i);
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> v1{1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    vector<int> v2{1, 0, 0, 0, 1, 0, 1};
    vector<int> res =  s.maxone(v2, 2);
    for(int x: res){
        cout << x << " ";
    }
    cout<< endl;


}

// https://www.interviewbit.com/problems/max-continuous-series-of-1s/