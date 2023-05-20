#include "iostream"
#include "vector"
using namespace std;

class Solution{
public:
    int solve(vector<int> &A, int B){
        int i=0;
        int j =0;
        int sum = 0;
        int ans = 0;
        while(j < A.size()){
            sum += A[j];
            while(sum >= B){
                sum -= A[i];
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<int> v{1, 11, 2, 3, 15};
    cout << s.solve(v, 10) << endl;

}
// VVI
//  Qestion: https://www.interviewbit.com/problems/counting-subarrays/
