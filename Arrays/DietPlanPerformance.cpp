#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"
using namespace std;

int main(){
    vector<int> v{1, 0, 0, 0, 1};
    std::reverse(v.begin(), v.end());
    int ones = count_if(v.begin(), v.end(), [](int x){ return x == 1;});
    for_each(v.begin(), v.end(), [](int x){});
    string a{"rajat"};
    reverse(a.begin(), a.end());
    cout << a << endl;
    cout << ones << endl;
    unordered_map<char,int> mp;
    cout << mp['a'] << endl;
    if(mp.find('a') != mp.end()){
        cout << "found" << endl;
    }else{
        cout << "not found" << endl;
    }
    string s ="abcdefghi";
    string temp;
    temp.assign(s.begin(), s.begin()+3);
    cout << temp << endl;
}




