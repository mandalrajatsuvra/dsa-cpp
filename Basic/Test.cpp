#include "iostream"
#include "string"
#include "bitset"
using namespace std;
template<class T>

void swap2(T& a, T& b){
    T t{a};
    a = b;
    b= t;
}
string f(string&& s){
    if(s.size()){
        s[0] = ::toupper(s[0]);
    }
    return s;
}
struct Link{
            double * pre;
            Link* previous;
            Link* next; };

int main(){





    bitset<10> bitset;

    bitset.flip(9);

    if(bitset[9]){
        cout << "";
    }


    cout << "Riya Biswas" << endl;
    Link link;
    cout << sizeof(link) << endl;
    cout << f("rajat") << endl;
    unsigned char c1 = 64;
    int a= 10;
    int b = 20;
    bool is_same{a==b};
    cout << is_same << endl;

    bool is_negative = -7;
    cout << is_negative << endl;

    for(int i=0; i!= 10; i++){
        cout <<  static_cast<char>('0' + i) << " ";
    }
    cout <<endl;

    cout<< sizeof(int) << endl;
    cout << sizeof(bool) << endl;

    int dp[1024]{-1};
    for(int i=0; i< 1; i++){
        cout << dp[i] << endl;
    }

    int *p{new int{10}};
    cout << *p << endl;

    auto x1 = {1, 2, 3};
    cout << x1.size() << endl;

    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    cout << sizeof(alpha)/ sizeof(alpha[0]) << endl;

    int a1 = 10;
    int a2 = 20;
    swap2(a1, a2);
    cout << "after swap" << a1 << endl;

}