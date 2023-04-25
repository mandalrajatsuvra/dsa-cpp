/*Given an array of integers and a number K.
Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3.
Window 2 of size k = 4 is 2 1 3 4. Number
        of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
        of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
        of distinct elements in this window are 3.*/

#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

vector<int> countDistinct (int A[], int n, int k){
    unordered_map<int,int> mp;
    vector<int> v;
    int i=0;
    int j=0;
    while (j < n){
        if(mp.find(A[j]) == mp.end()){
            mp[A[j]] = 1;
        }else{
            mp[A[j]] ++;
        }
        if(j-i +1 <k){
            j++;
        }else if(j-i+1 == k){
            v.push_back(mp.size());
            if(mp.find(A[i]) != mp.end()){
                int cnt = mp[A[i]];
                if(cnt == 1){
                   mp.erase(A[i]);
                }else{
                    mp[A[i]]--;
                }
            }
            i++;
            j++;
        }
    }
    return v;
}
int main(){
    int arr[] = {1,2,1,3,4,2,3};
    vector<int> res = countDistinct(arr, 7, 4);
    for(auto x: res) {
        cout << x << " ";
    }
    cout << endl;
}

