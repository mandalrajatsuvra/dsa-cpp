#include "iostream"
#include "vector"
#include "string"
#include "queue"
using namespace std;



class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        auto comp = [](pair<char, int> e1, pair<char, int> e2){
            return e1.second <= e2.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp) > maxHeap{comp};
        maxHeap.push({'a', a});
        maxHeap.push({'b', b});
        maxHeap.push({'c', c});

        string s = "";
        pair<char, int> curr = maxHeap.top();
        maxHeap.pop();
        int usedCount = min(curr.second, 2);
        for(int i=0; i< usedCount; i++) {
            s += curr.first;
        }
        int futureUse = 0;
        if(curr.second > usedCount){
            futureUse = curr.second - usedCount;
        }
        pair<char, int> future = {curr.first, futureUse};


        while(!maxHeap.empty()){



        }




    }
};
