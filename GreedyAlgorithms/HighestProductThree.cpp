#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int get_highest_product_three(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int p_count = 0;
    for(int i= n - 1; i>= 0; i--){
        if(arr[i] > 0) {
            p_count++;
        }
    }
    int res = -1;
    if(p_count == 0){
        res = arr[n-1] * arr[n-2] * arr[n -3];
    }else if(p_count == 1){
        res = arr[n-1] * arr[0] * arr[1];
    }else if(p_count == 2){
        res = arr[n-1] * arr[0] * arr[1];
    }else{
        res = max(arr[n-1] * arr[0] * arr[1], arr[n-1]*arr[n-2]* arr[n-3]);
    }
    return res;
}
int main(){
    vector<int> arr {0, -1, 3, 100, 70, 50};
    cout << get_highest_product_three(arr) << endl;
}





