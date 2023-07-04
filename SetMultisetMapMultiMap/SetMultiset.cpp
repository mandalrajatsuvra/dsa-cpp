#include "set"
#include "map"
#include "iostream"

void checkLessThan(){
    std::pair<int, int> p1 = {1, 2};
    std::pair<int, int> p2 = {2, 2};
    if(p1 < p2){
        std::cout <<" p1 is less than p2" << std::endl;
    }else{
        std::cout << "p1 is greater than p2" << std::endl;
    }
}

int main(){
    std::pair<int, int> p = {1, 2};
    std::pair<int, int> p2 {1, 3};
    if(p == p2){
        std::cout<< "equals";
    }else{
        std::cout << "not equals";
    }
    checkLessThan();

    std::multimap<int, int> mm;
    mm.find(9);
}
