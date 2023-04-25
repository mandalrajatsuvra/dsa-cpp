#include "iostream"
#include "string"
using namespace std;

bool is_match(string s, string p){
    int m = s.size();
    int n = p.size();
    for(int i=0; i <= m -n ; i++){
        int j=0;
        for(; j< n; j++){
            if(s[i] != p[j]) {
                break;
            }
            i++;
        }
        if(j == n){
            return true;
        }
    }
    return false;
}
int main(){
    string s = "abcabadmn";
    string p ="abca";
    if(is_match(s, p)){
        cout << "Matched" << endl;
    }else{
        cout << "Not matched" << endl;
    }
}





