#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s, 0, s.size()-1);
        reverseEachWord(s);
    }
    void reverseEachWord(vector<char>& arr){
        int start = 0;
        int end = 0;
        while(end < arr.size()){
            if(arr[end] == ' '){
                reverse(arr, start, end-1);
                start = end+1;
            }else if(end == arr.size() - 1){
                reverse(arr, start, end);
            }
            end++;
        }
    }
    void reverse(vector<char>& arr, int start, int end){
        while(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
};