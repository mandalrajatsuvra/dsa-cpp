#include "set"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "stack"
#include "vector"
#include "iostream"
#include "list"
#include "algorithm"
using namespace std;

int main(){

    stack<int, vector<int>> stk;
    stk.push(2);
    stk.push(3);
    cout << stk.top() << endl;

    initializer_list<int> lst = {1, 2, 3, 4, 5};
    cout << lst.size() << endl;

    auto it = lst.begin();
    for(int i=0; i< lst.size(); i++){
        cout << *it << " ";
        it++;
    }
    cout << endl;


    list<int> dll;

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);


    list<int>::iterator it_4 =   find(dll.begin(), dll.end(), 4);
    it_4 --;
    cout << *it_4 << endl; // should print 3


    for(auto it = dll.begin() ; it != dll.end() ; it ++){
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = dll.rbegin(); it != dll.rend(); it ++){
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = dll.crbegin(); it != dll.crend(); it ++){
        cout << *it << " ";
    }
    cout << endl;
}
