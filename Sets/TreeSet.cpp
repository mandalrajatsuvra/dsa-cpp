#include "iostream"
#include "vector"
#include "queue"
#include "set"
using  namespace std;

int main(){
    set<int> s1;
    s1.insert(20);
    s1.insert(10);
    s1.insert(5);
    s1.insert(50);

    auto it = s1.begin();
    s1.erase(*it);
    it = s1.begin();
    cout << *it << endl;



    auto com = [](int a, int b){
        return a > b ? true: false;
    };

    set<int, decltype(com)> s2{com};
    s2.insert(20);
    s2.insert(100);
    s2.insert(50);
    s2.insert(-90);
    cout << *s2.begin() << endl;



    auto comp = [](pair<int, int> a, pair<int, int>b){
        if(a.first == b.first){
            return true;
        }
        return a.second > b.second? true: false;
    };

    set<pair<int, int>, decltype(comp)> s3{comp};

    s3.insert({0, 100});
    s3.insert({1, 50});
    s3.insert({2, 200});
    s3.insert({3, 60});

    cout << s3.begin()->second << endl;
    s3.erase(s3.begin());
    cout << s3.begin()->second << endl;
}