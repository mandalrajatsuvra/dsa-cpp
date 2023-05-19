#include "iostream"
#include "string"

using namespace std;

class Solution{
public:
    int noOfWays(string s, int n,  int steps){
        return dfs(0, s, n, steps);
    }
    int dfs(int s, string path, int n, int steps){
        int ways = 0;
        for(int i=1; i<= steps; i++){
            int s1 = s+i;
            if( s1 < n-1 && path[s1] =='1' ){
                ways +=dfs(s1, path, n, steps);
            }else if(s1 >= n-1 ){
                return 1;
            }
        }
        return ways;
    }
};

int main(){
    Solution s;
    int n;
    string path;
    int steps;
    cin >> n;
    cin >> steps;
    cin >> path;
    cout << s.noOfWays(path, n, steps) << endl;
}

// Not complete solution