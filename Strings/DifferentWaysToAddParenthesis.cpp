#include "iostream"
#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<string> exp = processExpression(expression);
        return dfs(0, exp.size()-1, exp);
    }
    vector<string> processExpression(string exp){
        vector<string> v;
        int i = 0;
        string token = "";
        while(i < exp.size()){
            if(exp[i] == '+' || exp[i] =='-' || exp[i] == '*'){
                v.push_back(token);
                if(exp[i] == '+'){
                    v.push_back("+");
                }else if(exp[i] == '-'){
                    v.push_back("-");
                }else{
                    v.push_back("*");
                }

                token = "";
            }else{
                token += exp[i];
            }
            i++;
        }
        if(!token.empty()){
            v.push_back(token);
        }
        return v;
    }
    vector<int> dfs(int i, int j, vector<string>& exp){
        if(i == j){
            return {stoi(exp[i])};
        }
        vector<int> ans;
        for(int k=i; k<= j; k++){
            if(exp[k] == "+" || exp[k] == "-" || exp[k] == "*"){
                vector<int> left = dfs(i, k-1, exp);
                vector<int> right = dfs(k+1, j, exp);
                for(int x: left){
                    for(int y: right){
                        if(exp[k] == "+"){
                            ans.push_back(x + y);
                        }else if(exp[k] == "-"){
                            ans.push_back(x - y);
                        }else if(exp[k] == "*"){
                            ans.push_back(x * y);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

void print(vector<int> res){
    for(int x: res){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    Solution s;
    vector<int> res = s.diffWaysToCompute("2-1-1");
    vector<int> res2 = s.diffWaysToCompute("2*3-4*5");
    print(res);
    print(res2);
}

//Question : https://leetcode.com/problems/different-ways-to-add-parentheses/



