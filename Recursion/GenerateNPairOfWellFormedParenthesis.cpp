#include "iostream"
#include "vector"
#include "string"
using namespace std;


class Solution{
public:
    vector<string> generateWellFormedParenthesis(int n){
        vector<string> res;
        f(0, 0, n, "", res);
        return res;
    }
    void f(int open, int close, int n, string pr, vector<string>& res){
        if(open > n || close > n){
            return;
        }
        if(open == n && close == n){
            res.push_back(pr);
        }
        if(open == close){
            f(open+1, close, n, pr+'(', res);
        }else if(open > close){
            f(open+1, close, n, pr+'(', res);
            f(open, close+1, n, pr+')', res);
        }
    }
};

int main(){
    Solution s;
    vector<string> res = s.generateWellFormedParenthesis(4);
    for(string t: res){
        cout << t << endl;
    }
}






