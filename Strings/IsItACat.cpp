#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"
using namespace std;

bool is_a_cat(string word){
    int i =0;
    bool m = false,e = false ,o= false, w = false;
    char arr[] = {'m' , 'M', 'e','E', 'o', 'O', 'w' ,'W'};
    unordered_set<char> st;
    for(char c: arr){
        st.insert(c);
    }
    while (i < word.size() && st.find(word[i]) != st.end()) {
        while(word[i] == 'm' || word[i] == 'M'){
            if(e || o || w){
                return false;
            }
            m = true;
            i++;
        }
        while(word[i] == 'e' || word[i] == 'E'){
            if(o || w || !m){
                return false;
            }
            e= true;
            i++;
        }
        while(word[i] == 'o' || word[i] == 'O'){
            if(w || !m || !e){
                return false;
            }
            o = true;
            i++;
        }
        while(word[i] == 'w' || word[i] == 'W'){
            if(!m || !e || !o){
                return false;
            }
            w  = true;
            i++;
        }

    }
    return i == word.size() && m && e && o && w;
}
int main(){
    int n;
    cin >> n;
    vector<string> in;
    string word;
    int len;
    for(int i=0; i< n; i++){
        cin >> len;
        cin >> word;
        in.push_back(word);
    }
    for(int i=0; i< in.size(); i++){
        if(is_a_cat(in[i])){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << endl;
    }
}

