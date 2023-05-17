class Solution{
public:
    bool isPowerofTwo(long long n){
        int i = 0;
        long long t = 0;
        while( t <= n ){
            t = 1 << i;
            if( t == n ){
                return true;
            }
            i++;
        }
        return false;
    }
};