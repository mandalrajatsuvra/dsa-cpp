#include "iostream"
#include "vector"
using namespace std;

double get_median(vector<int>& arr1, vector<int>& arr2){
    int l1 = arr1.size();
    int l2 = arr2.size();
    vector<int> res(l1+l2, 0);
    int i=0;
    int j=0;
    int k=0;
    while(i < l1 && j < l2){
        if(arr1[i] >= arr2[j]){
            res[k] = arr2[j];
            j++;
            k++;
        }else{
            res[k] = arr1[i];
            i++;
            k++;
        }
    }
    while(i < l1){
        res[k] = arr1[i];
        k++;
        i++;
    }
    while(j < l2){
        res[k] = arr2[j];
        k++;
        j++;
    }
    for(int x: res){
        cout << x << " ";
    }
    cout << endl;


    if(res.size()%2 == 0){
        double d1 = static_cast<double>( res[res.size()/2]);
        double d2 = static_cast<double>(res[res.size()/2 -1]);
        cout << d1 << endl;
        cout << d1 << endl;
        return (d1 + d2)/2;
    }else{
        return static_cast<double>(res[res.size()/2]);
    }
}

int main(){
    vector<int> v1{1, 4, 5, 8};
    vector<int> v2{2, 3, 9, 10};
    cout << get_median(v1, v2) << endl;
}



