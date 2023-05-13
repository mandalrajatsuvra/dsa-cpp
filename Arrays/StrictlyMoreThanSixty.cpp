#include "iostream"
#include "vector"
#include "string"
using  namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i=0; i< details.size(); i++){
            string s = details[i];
            string ph = s.substr(0, 10);
            string gen = s.substr(10,1);
            int age = stoi(s.substr(11, 2));
            if(age > 60){
                cnt ++;
            }
        }
        return  cnt;
    }
};