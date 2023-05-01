#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"
#include "algorithm"
#include "set"
using namespace std;

class UnionFind{
private:
    vector<int> parent;
    vector<int> sz;
public:
    UnionFind(int n): parent(n), sz(n){
        for(int i=0; i< n ; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u){
        if(parent[u] == u){
            return u;
        }
        parent[u] = find(parent[u]);
        return parent[u];
    }
    bool connected(int u, int v){
        return find(u) == find(v);
    }
    void make_union(int u, int v){
         int uid = find(u);
         int vid = find(v);
         if(uid == vid){
             return;
         }
         if(sz[uid] > sz[vid]){
             parent[vid] = uid;
             sz[uid] += sz[vid];
         }else{
             parent[uid] = vid;
             sz[vid] += sz[uid];
         }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf{n};
        unordered_map<string, int> mp;
        for(int i=0; i < n; i++){
            vector<string> account = accounts[i];
            for(int j=1; j< account.size(); j++){
                if(mp.find(account[j]) != mp.end()){
                    uf.make_union(i, mp[account[j]]);
                }
                mp[account[j]] = i;
            }
        }
        unordered_map<int, pair<string ,set<string>>> merged_accounts;
        for(int i=0; i < n; i++){
            vector<string> account = accounts[i];
            int set = uf.find(i);
            string name = account[0];
            merged_accounts[set].first = name;
            for(int j=1; j< account.size(); j++){
                merged_accounts[set].second.insert(accounts[i][j]);
            }
        }
        vector<vector<string>> m_accounts;
        for(auto& [first, second]: merged_accounts){
            vector<string> tmp;
            string name = second.first;
            set<string> emails = second.second;
            tmp.push_back(name);
            tmp.insert(tmp.end(), emails.begin(), emails.end());
            m_accounts.push_back(tmp);
        }
        return m_accounts;
    }
};

int main(){
    Solution s;
    vector<vector<string>> accounts{
            {"John", "j1.com", "j2.com"},
            {"Mary", "m1.com", "m2.com"},
            {"John", "t1.com", "j2.com"},
            {"John", "t1.com", "t2.com"}
    };
    vector<vector<string>> res = s.accountsMerge(accounts);
    for(vector<string> account: res){
        for(string s: account){
            cout << s +" ";
        }
        cout<< endl;
    }
}


