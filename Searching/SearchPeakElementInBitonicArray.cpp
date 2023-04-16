#include "iostream"
#include "vector"
using namespace std;

int get_index_of_peak_element_bi_tonic_array(vector<int> & arr){
    int low = 0;
    int high = arr.size()-1;
    int res = -1;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(mid >= 1 && mid <= arr.size()-2){
            if(arr[mid] > arr[mid -1]  && arr[mid] > arr[mid +1]){
                res = mid;
                break;
            }else if( arr[mid] < arr[mid +1] ){
                low = mid +1;
            }else{
                high = mid -1;
            }
        }else if(mid == 0){
            if(arr[mid] > arr[mid +1]){
                res = mid;
            }else{
                res = mid +1;
            }
        }else {
            if(arr[mid] > arr[mid -1]){
                res = mid;
            }else{
                res = mid -1;
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr {3,5, 6,8,9,4,2,1};
    vector<int> arr1 {3,5, 6,8,9,10,2};
    vector<int> arr2 {3,5, 6,8,9,10,11};
    cout << get_index_of_peak_element_bi_tonic_array(arr2) << endl;
}



