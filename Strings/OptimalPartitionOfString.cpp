#include "iostream"
#include "string"
#include "unordered_set"
using namespace std;


class Solution {
public:
    int partitionString(string s) {
        int p_count = 0;
        unordered_set<char>* st = new unordered_set<char>();
        for(int i=0; i< s.size(); i++){
            if(st->find(s[i]) != st->end()){
                p_count++;
                st = new unordered_set<char>();
            }
            st->insert(s[i]);
        }
        if(!st->empty()){
            p_count++;
        }
        return p_count;
    }
};

int main(){
    Solution s;
    string str= "ssssss";
    cout<< s.partitionString(str) << endl;
}


