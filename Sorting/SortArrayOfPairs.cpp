#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int main(){
    // Sorting the pairs in ascending order depends on the second part.

    vector<pair<int, int>> vt;
    vt.push_back({0,30});
    vt.push_back({5, 10});
    vt.push_back({15, 20});
    auto comp = [](pair<int, int> p1, pair<int, int> p2){
        return p1.second <= p2.second;
    };
    sort(vt.begin(), vt.end(), comp);
    for(auto& [start, end]: vt){
        cout << start << "  " << end << endl;
    }
}