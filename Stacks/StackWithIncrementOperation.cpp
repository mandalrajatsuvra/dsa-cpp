#include "iostream"
#include "vector"
using namespace std;

class CustomStack {
    vector<int> stack;
    vector<int> values;
    int top;
public:
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        values.resize(maxSize);
        top = -1;
    }
    void push(int x) {
        if(top == stack.size() - 1){
            return;
        }
        stack[++top] = x;
        values[top] = 0;
    }
    int pop() {
        if(top == -1){
            return -1;
        }
        int peek = stack[top];
        int val = values[top];
        top --;
        if(top >= 0){
            values[top] += val;
        }
        return peek + val;
    }
    void increment(int k, int val) {
        int indx = min(k-1, top);
        if(indx != -1){
            values[indx] += val;
        }
    }
};
