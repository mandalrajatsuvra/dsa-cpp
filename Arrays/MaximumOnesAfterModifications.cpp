#include "iostream"
#include "vector"
using namespace std;


class Solution{
public:
    int solve(vector<int>& A, int B){
        int max_ones = 0;
        int ones = 0;
        int zeros = 0;
        int i =0, j= 0;
        while(j < A.size()){
            if(A[j] == 1){
                ones ++;
            }else{
                zeros ++;
            }
            while(zeros > B){
                if(A[i] == 1){
                    ones --;
                }else{
                    zeros --;
                }
                i++;
            }
            max_ones = max(max_ones, ones+zeros);
            j++;
        }
        return max_ones;
    }
};

int main(){
    Solution s;
    vector<int> v1{1, 0, 0, 1, 1, 0, 1};
    cout << s.solve(v1, 1) << endl;
    vector<int> v2{1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
    cout << s.solve(v2, 2) << endl;
}


