#include "unordered_set"
#include "set"
#include "iostream"
using namespace std;
void printSet(set<pair<int, int>>& st){
    for(auto it = st.begin(); it != st.end(); it ++){
        cout << "[" << it->first <<", " << it->second << "]" << endl;
    }
    cout << endl;
    cout << endl;
}
int main(){
    set<pair<int, int>> st;
    pair<int, int> p1 = {1, 0};
    pair<int, int> p2 = {2, 1};
    pair<int, int> p3 = {3, 2};
    pair<int, int> p4 = {4, 3};
    pair<int, int> p5 = {0, 4};
    pair<int, int> p6 = {1, 5};
    st.insert(p1);
    st.insert(p2);
    st.insert(p3);
    st.insert(p4);
    st.insert(p5);
    st.insert(p6);
    printSet(st);

    auto iter = st.find({1, 5});
    st.erase(iter);
    printSet(st);
}
