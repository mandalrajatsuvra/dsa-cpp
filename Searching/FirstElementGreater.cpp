#include <iostream>
#include "vector"
using namespace std;
int firstElementGreater(const vector<int>& arr, int t){
    int low = 0;
    int high = arr.size()-1;
    int result = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > t){
            result = mid;
            high = mid-1;
        }else{
            low = mid +1;
        }
    }
    return result;
}
int main(){
    vector<int> arr{-14, 10, 2, 3, 108, 108, 243, 285, 285,285,401, 402, 406};
    cout << arr[firstElementGreater(arr, 3)] << endl;
}