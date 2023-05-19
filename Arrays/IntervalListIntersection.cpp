#include "iostream"
#include "vector"
using namespace std;


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i =0;
        int j =0;
        while(i < firstList.size() && j < secondList.size() ){
            vector<int> iListElm = firstList[i];
            vector<int> jListElm = secondList[j];
            if(iListElm[0] > jListElm[1]){
                j++;
            }else if(jListElm[0] > iListElm[1] ){
                i++;
            }else{
                int newStart = max(iListElm[0], jListElm[0]);
                int newEnd = min(iListElm[1], jListElm[1]);
                vector<int> intersection{newStart, newEnd};
                res.push_back(intersection);
                if(iListElm[1] > jListElm[1]){
                    j++;
                }else if(jListElm[1] > iListElm[1]){
                    i++;
                }else{
                    i++;
                    j++;
                }
            }
        }
        return res;
    }
};