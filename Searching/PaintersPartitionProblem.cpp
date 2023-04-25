/*Given 2 integers A and B and an array of integers C of size N. Element C[i] represents the length of ith board.
You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time
to paint 1 unit of the board.

Calculate and return the minimum time required to paint all boards under the constraints that any painter will only paint
contiguous sections of the board.
NOTE:
1. 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially
by another.
2. A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.
Return the ans % 10000003.*/

#include "iostream"
#include "vector"
using namespace std;

int minimum_time_to_paint(int k, int time_unit, vector<int>& board){
    auto is_possible = [](vector<int>& board, long  time, int no_of_p)-> bool {
        int t=0;
        int p =0;
        for(int i=0; i< board.size(); i++){
            t += board[i];
            if(t > time){
                p++;
                t=board[i];
            }
        }
        if(t > 0){
            p++;
        }
        return p <= no_of_p;
    };

    int low = 0;
    long long high = 0;
    for(int i=0; i< board.size(); i++){
        low = max(low, board[i]);
        high += board[i];
    }
    long long  res = -1;
    while(low <= high){
        long long  mid = (low + high)/2;
        if(is_possible(board, mid, k)){
            res = mid;
            high = mid-1;
        }else{
            low = mid +1;
        }
    }
    return (res * time_unit) %10000003;
}

int main(){


}





