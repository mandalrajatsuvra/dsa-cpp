/*Problem Description

Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.



Problem Constraints
1 <= |A| <= 105



Input Format
First argument is an string A.



Output Format
Return 1 if parantheses in string are balanced else return 0.



Example Input
Input 1:

A = "(()())"
Input 2:

A = "(()"


Example Output
Output 1:

1
Output 2:

0*/


#include "iostream"
#include "string"
#include "stack"
using namespace std;

int isBalance(string s){
    stack<char> stk;
    for(int i=0; i< s.size(); i++){
        if(s[i] == '('){
            stk.push(s[i]);
        }else{
            if(stk.empty()){
                return 0;
            }
            if(stk.top() == '('){
                stk.pop();
            }else{
                return 0;
            }
        }
    }
    return stk.empty() ? 1: 0;

}
int main(){

}