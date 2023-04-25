/*Given an array of integers A.  There is a sliding window of size B which

        is moving from the very left of the array to the very right.

You can only see the w numbers in the window. Each time the sliding window moves

rightwards by one position. You have to find the maximum for each window.

The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

Window position	Max
———————————-	————————-
[1  3  -1] -3  5  3  6  7	3
1 [3  -1  -3] 5  3  6  7	3
1  3 [-1  -3  5] 3  6  7	5
1  3  -1 [-3  5  3] 6  7	5
1  3  -1  -3 [5  3  6] 7	6
1  3  -1  -3  5 [3  6  7]	7
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

Note: If B > length of the array, return 1 element with the max of the arra*/

#include "iostream"
#include "vector"
#include "list"
using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B){
    vector<int> res;
    list<int> dq;
    int size = A.size();
    int i=0;
    int j=0;
    while(j < size){
        while (!dq.empty() && A[j] >= A[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(j);
        if(j-i+1 < B){
            j++;
        }else if(j-i+1 == B){
            res.push_back(A[dq.front()]);
            if(dq.front() == i){
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return res;
}
int main(){
    vector<int> arr{1, 3 ,-1, -3, 5, 3, 6, 7};
    vector<int> res = slidingMaximum(arr, 3);
    for(int x: res){
        cout << x << " ";
    }
    cout << endl;

}



