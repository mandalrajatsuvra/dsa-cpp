#include "iostream"
#include "unordered_map"
using namespace std;


class FrequencyTracker {
    unordered_map<int, int> keyToFreq;
    unordered_map<int, int> freqToKey;
public:
    FrequencyTracker() {

    }
    void add(int number) {
        int freq = keyToFreq[number];
        keyToFreq[number]++;
        freqToKey[freq] --;
        if(freqToKey[freq] == 0){
            freqToKey.erase(freq);
        }
        freqToKey[keyToFreq[number]] ++;
    }
    void deleteOne(int number) {
        if(keyToFreq.find(number) == keyToFreq.end()){
            return;
        }

        int val = keyToFreq[number];
        keyToFreq[number]--;
        if(keyToFreq[number]==0){
            keyToFreq.erase(number);
        }
        freqToKey[val] --;
        if(freqToKey[val] == 0){
            freqToKey.erase(val);
        }
    }
    bool hasFrequency(int frequency) {
        return freqToKey.find(frequency) != freqToKey.end();
    }
};