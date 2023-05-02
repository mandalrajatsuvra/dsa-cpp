#include "iostream"
#include "string"
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string res= "";
        while (i< word1.size() && j < word2.size()){
            if((i+j)%2 == 0){
                res += word1[i];
                i++;
            }else{
                res+= word2[j];
                j++;
            }
        }
        while (i < word1.size()){
            res += word1[i];
            i++;
        }
        while (j< word2.size()){
            res += word2[j];
            j++;
        }
        return res;
    }
};

int main(){

}





