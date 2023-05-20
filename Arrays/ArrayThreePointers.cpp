#include "iostream"
#include "vector"
using namespace std;

class Solution{
public:
    int minimize(const vector<int>& A, const vector<int>& B, const vector<int>& C){
        int i=0;
        int j=0;
        int k =0;
        int mini = INT_MAX;
        while(i< A.size() && j < B.size() && k < C.size()){
            int temp = max(abs(A[i] - B[j]), max(abs(B[j] - C[k]), abs(C[k] - A[i])));
            mini = min(mini, temp);
            int minOfThree = min(A[i], min( B[j], C[k]));
            if(minOfThree == A[i]){
                i++;
            }else if(minOfThree == B[j]){
                j++;
            }else{
                k++;
            }
        }
        return mini;
    }
};

int main(){
    Solution s;
    vector<int> A{1, 4, 6, 9};
    vector<int> B{6, 8, 9, 11};
    vector<int> C{3, 7, 11, 15};

    cout<< s.minimize(A, B, C) << endl;



}



