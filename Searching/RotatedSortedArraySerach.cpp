/*Given an array of integers A of size N and an integer B.
array A is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
You are given a target value B to search. If found in the array, return its index, otherwise, return -1.
You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*/

#include "iostream"
#include "vector"
using namespace std;

int search_in_rotated_sorted_array(vector<int>& arr, int t){
    auto findIndexOfSmallestNo = [](vector<int>& arr)->int {
        int low = 0;
        int high = arr.size();
        while(low < high){
            int mid = (low + high)/2;
            if(arr[mid] < high){
                high = mid;
            }else{
                low = mid +1;
            }
        }
        return low;
    };
    auto search = [](vector<int>& arr, int t, int low, int high)->int {
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == t){
                return mid;
            }else if(arr[mid] > t){
                high = mid - 1;
            }else{
                low = mid +1;
            }
        }
        return -1;
    };

    int smallest_index = findIndexOfSmallestNo(arr);
    int index = search(arr, t, 0, smallest_index - 1);
    if(index != -1){
        return index;
    }
    return search(arr, t, smallest_index, arr.size()-1);
}
int main(){
    vector<int> arr {6,7,0,1,2,4,5};
    cout << search_in_rotated_sorted_array(arr, 7) << endl;
    cout << search_in_rotated_sorted_array(arr, 1) << endl;
    cout << search_in_rotated_sorted_array(arr, 5) << endl;
}
