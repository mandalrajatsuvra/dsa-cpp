
/*
Problem Description



Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

In Unix-style file system:
A period '.' refers to the current directory.
A double period '..' refers to the directory up a level.
Any multiple consecutive slashes '//' are treated as a single slash '/'.
In Simplified Absolute path:
The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path doesn't end with trailing slashes '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
The path will not have whitespace characters.


Problem Constraints
1 <= |A| <= 106


Input Format
The only argument given is string A.
Output Format
Return a string denoting the simplified absolute path for a file (Unix-style).


Example Input
Input 1:
A = "/home/"
Input 2:
A = "/a/./b/../../c/"


Example Output
Output 1:
"/home"
Output 2:
"/c"
*/

#include "iostream"
#include "string"
#include "vector"
#include "stack"
using namespace std;

vector<string> processInput(string s){
    vector<string> vt;
    string token ="";
    int i =0;
    while(i < s.size()){
        if(s[i] == '/'){
            if(!token.empty()){
                vt.push_back(token);
            }
            token = "";
            i++;
        }else{
            token += s[i];
            i++;
        }
    }
    if(!token.empty()){
        vt.push_back(token);
    }
    return vt;
}
string simplifyPath(string s){
    vector<string> vt = processInput(s);
    stack<string> stk;
    for(int i=0; i< vt.size(); i++){
        if(vt[i] == "."){
            continue;
        }else if(vt[i] == ".."){
            if(!stk.empty())
                stk.pop();
        }else{
            stk.push(vt[i]);
        }
    }
    string res = "";
    while (!stk.empty()){
        string top = stk.top();
        stk.pop();
        res = "/" + top + res;
    }
    if(res.empty()){
        return "/";
    }
    return res;
}
int main(){
    string  in = "/a/./b/../../c///";
    cout << simplifyPath(in) << endl;
}






