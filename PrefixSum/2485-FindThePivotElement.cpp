#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        vector<int> vec(n+1, 0);
        for(int i=1; i<= n; i++){
            vec[i] = i;
        }
        for(int i=1 ; i<= n; i++){
            vec[i] = vec[i] + vec[i-1];
        }
        for(int i=1; i<=n; i++){
            if(vec[i] == vec[n] - vec[i-1]){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.pivotInteger(8) << endl;
    cout << s.pivotInteger(4) << endl;
    cout << s.pivotInteger(1) << endl;
}
