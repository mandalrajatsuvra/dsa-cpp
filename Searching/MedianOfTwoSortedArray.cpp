/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both arrays ).

The overall run time complexity should be O(log (m+n)).

NOTE: If the number of elements in the merged array is even,then the median is the average of n / 2 th and n/2 + 1th element.
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5

Example:
A : [1 4 5]
B : [2 3]
Merged A and B will be : [1, 2, 3, 4, 5]
Its median will be 3

*/

#include "iostream"
#include "vector"
using namespace std;

double findMedianTwoSortedArray(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size(), m = arr2.size();
    int low = 0, high = n;
    double median = -1;
    int mid = 0;
    if((m+n)% 2 == 0){
        mid = (m+n)/2;
    }else{
        mid = (m+n)/2 + 1;
    }

    if(arr2.size()== 0){
        if((m+n)% 2 == 0){
            return static_cast<double >(arr1[mid] + arr1[mid-1])/2;
        }else{
            return static_cast<double >(arr1[mid-1]);
        }
    }


    while(low <= high){
        int c1 = (low + high)/2;
        int c2 =  mid - c1;
        int l1 = c1 == 0 ? INT_MIN: arr1[c1-1];
        int r1 = c1 == n? INT_MAX: arr1[c1];
        int l2 = c2 == 0? INT_MIN : arr2[c2-1];
        int r2 = c2 == m? INT_MAX : arr2[c2];
        if(l1 <= r2 && l2 <= r1){
            if((m+n)% 2 == 0){
                median = (static_cast<double>(max(l1, l2)) + static_cast<double >(min(r1, r2)))/2;
            }else{
                median =  static_cast<double>(max(l1, l2));
            }
            break;
        }else if(l1 > r2){
            high = c1 - 1;
        }else{
            low = c1 + 1;
        }
    }
    return median;
}
int main(){
    vector<int> arr1 { -41, -33, -24, -21, -20, 27, 48};
    vector<int> arr3 {-9};
    vector<int> arr2 {8, 9,10,11, 12};
    cout << findMedianTwoSortedArray(arr1, arr3) << endl;
}



