#include "iostream"
#include "vector"
#include "list"
using namespace std;

vector<int> plusOne(vector<int>& nums){
    int n = nums.size();
    vector<int> tmp(n+1, 0);
    for(int i=0; i< nums.size(); i++){
        tmp[i+1] = nums[i];
    }
    int notNine = 0;
    for(int i=1; i< tmp.size(); i++){
        if(tmp[i] != 9){
            notNine = i;
        }
    }
    tmp[notNine] ++;
    notNine ++;
    while(notNine < tmp.size()){
        tmp[notNine] = 0;
        notNine++;
    }
    vector<int> res;
    int indx = 0;
    while(tmp[indx] == 0){
        indx++;
    }
    for(int t= indx; t< tmp.size(); t++){
        res.push_back(tmp[t]);
    }
    return res;
}
int main(){
    vector<int> v{1, 2, 3};
    plusOne(v);
}