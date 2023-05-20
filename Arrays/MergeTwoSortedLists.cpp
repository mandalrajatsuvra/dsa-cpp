#include "iostream"
#include "vector"
using namespace std;


class Solution{
    void merge(vector<int>& A, vector<int>& B){
        vector<int> C;
        int i=0;
        int j=0;
        while(i < A.size() && j < B.size()){
            if(A[i] >= B[j]){
                C.push_back(B[j]);
                j++;
            }else{
                C.push_back(A[i]);
                i++;
            }
        }
        while(i < A.size()){
            C.push_back(A[i]);
            i++;
        }
        while(j < B.size()){
            C.push_back(B[j]);
            j++;
        }
        A=C;
    }
};
int main(){



}
