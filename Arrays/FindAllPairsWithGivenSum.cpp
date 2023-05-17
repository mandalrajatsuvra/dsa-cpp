#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


class Solution{
public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int, int>> res;
        sort(A, A+N);
        sort(B, B+M);
        int i =0;
        int j = M-1;
        while( i < N && j >= 0 ){
            if(A[i] + B[j] == X){
                res.push_back({A[i], B[j]});
                i++;
                j--;
            }else if(A[i] + B[j] > X){
                j--;
            }else{
                i++;
            }
        }
        return res;
    }
};
