#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freq;
        for(int i=0; i< word.size(); i++){
            freq[word[i]] ++;
        }
        unordered_map<int, int> freq_of_freq;
        for(auto& [key, value]: freq){
            freq_of_freq[value] ++;
        }
        if(freq_of_freq.size() > 2){
            return false;
        }else if(freq_of_freq.size() <= 1){
            return false;
        }else{
            vector<int> v;
            for(auto& [key, value]: freq_of_freq){
                v.push_back(key);
            }
            int large = v[0];
            int small = v[1];
            if(v[1] > v[0]){
                large = v[1];
                small = v[0];
            }
            if(freq_of_freq[large] != 1){
                return false;
            }
            if (large != small+1){
                return false;
            }
            return true;
        }

    }
};

int main(){



}




