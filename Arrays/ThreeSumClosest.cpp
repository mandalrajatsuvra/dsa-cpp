#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;



class Solutions{
public:
   int threeSumClosest(vector<int> &A, int B) {
       int closestSum = INT_MAX;
       int diff = INT_MAX;
       sort(A.begin(), A.end());
       for(int i=0; i< A.size(); i++){
            int j = i+1;
            int k = A.size()-1;
            while(j < k){
                int sum = A[i] + A[j] + A[k] ;
                int abs_diff = abs(sum- B);
                if(abs_diff < diff){
                    closestSum = sum;
                    diff = abs_diff;
                }
                if(sum > B){
                    k--;
                }else{
                    j++;
                }
            }
       }
       return closestSum;
   }


};



int main(){



}



