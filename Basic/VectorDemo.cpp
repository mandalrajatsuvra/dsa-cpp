#include "iostream"
#include "vector"

using namespace std;

int main(){
    // insert at the end;
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    v1.insert(v1.begin()+ v1.size(), v2.begin(), v2.end());
    vector<int> ::iterator  it = v1.begin();
    while (it != v1.end()){
        cout << *it << " ";
        it ++;
    }

    cout << endl;


    // Insert at the start

    vector<int> t1 = {1, 2, 3};
    vector<int> t2 = {4, 5, 6};
    t1.insert(t1.begin(), t2.begin(), t2.end());
    auto it1 = t1.begin();
    while (it1 != t1.end()){
        cout << *it1 << " ";
        it1++;
    }
    cout << endl;
    // insert into the vector form initializer list

    vector<int> m1 = {1, 2, 3};
    m1.insert(m1.end(), {4, 5, 6});
    it = m1.begin();
    while (it != m1.end()){
        cout << *it << " ";
        it ++;
    }
    cout << endl;
}


