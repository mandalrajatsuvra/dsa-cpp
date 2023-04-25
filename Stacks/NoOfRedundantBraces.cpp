/*
Problem Description
Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.
Chech whether A has redundant braces or not.
NOTE: A will be always a valid expression.
Problem Constraints
1 <= |A| <= 105
Input Format
The only argument given is string A.

Output Format
Return 1 if A has redundant braces, else return 0.
Example Input
Input 1:
A = "((a+b))"
Input 2:

A = "(a+(a+b))"
Input 3:

A = "((a*b)+(c+d))"
Example Output
Output 1:
1
Output 2:
0
Output 3:
0
Example Explanation
Explanation 1:
((a+b)) has redundant braces so answer will be 1.
Explanation 2:
(a+(a+b)) doesn't have have any redundant braces so answer will be 0.
Explanation 3:
((a*b)+(c+d)) doesn't have have any redundant braces so answer will be 0.*/

#include "iostream"
#include "stack"
#include "string"
using namespace std;

int isRedundantBracesPresent(string s){
    stack<char> stk;
    int operator_count = 0;
    for(int i=0; i< s.size(); i++){
        if(s[i] == ')'){
            if(stk.top() == '('){
                return 1;
            }else{
                while(!stk.empty() && stk.top() != '('){
                    stk.pop();
                }
                if(stk.top() == '('){
                    stk.pop();
                    operator_count = 0;
                }
            }
        }else{
            if(s[i] == '+' || s[i] == '-'  || s[i] == '*' || s[i] == '/'){
                operator_count++;
            }
            if(s[i] == '('){
                stk.push(s[i]);
            }else if(operator_count > 0){
                stk.push(operator_count);
            }
            operator_count = 0;
        }
    }
    return 0;
}
int main(){
    cout << isRedundantBracesPresent("(a)") << endl;
    cout << isRedundantBracesPresent("()") << endl;
    cout << isRedundantBracesPresent("((a*b)+(c+d))") << endl;
    cout << isRedundantBracesPresent("((a+b))") << endl;
}



