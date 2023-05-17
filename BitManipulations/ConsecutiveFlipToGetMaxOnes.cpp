#include "iostream"
using namespace std;

class Solution{
public:
    int maxOnes(int a[], int n)
    {
        int ones = 0;
        int count = 0;
        int maxi = 0;
        for(int i=0; i< n; i++){
            if(a[i] == 0){
                count++;
            }else{
                ones ++;
                count--;
            }
            maxi = max(count, maxi);
            if(count < 0){
                count = 0;
            }
        }
        return ones + maxi;
    }
};


int main(){
    Solution s;
    int arr[] = {1, 0, 1, 0, 1, 0,  0, 1, 1};
    cout << s.maxOnes(arr, 9) <<endl;

}


