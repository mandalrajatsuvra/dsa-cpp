#include "iostream"
#include "vector"
#include "unordered_set"
using namespace std;


int solve(vector<int>& arr, int x){
    unordered_set<int> st;
    for(int i=0; i< arr.size(); i++){
        if (st.find(arr[i] - x) != st.end() || st.find(arr[i] + x) != st.end()) {
            return 1;
        }
       st.insert(arr[i]);
    }
    return 0;
}
int main(){

}

// Question : https://www.interviewbit.com/problems/pair-with-given-difference/




