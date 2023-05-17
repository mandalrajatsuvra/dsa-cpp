#include "iostream"
#include "vector"
using namespace std;

class Solution{
public:
    int missingNumber(vector<int>& array, int n) {
        int r = 0;
        for(int i=1; i<= n ; i++){
            r = r^i;
        }
        for(int x: array){
            r = r^x;
        }
        return r;
    }
};