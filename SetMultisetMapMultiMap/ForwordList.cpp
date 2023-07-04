#include "iostream"
#include "forward_list"
#include "algorithm"


using namespace std;

void printList(forward_list<int>& list){
    for(forward_list<int>::iterator it = list.begin(); it != list.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    forward_list<int> list = {1, 2, 3, 4};
    list.push_front(0);
    printList(list);

    forward_list<int>::iterator it = find(list.begin() , list.end(), 1);
    list.erase_after(it);
    printList(list);




}