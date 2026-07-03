class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l=1;
        int r=x;
        while(l<=r){
            long long mid=(long long)l+(r-l)/2;
            if(mid*mid<x) {
                l=mid+1;
            }
            else if(mid*mid>x){
                r=mid-1;
            }
            else return mid;
        }
        return l-1;
    }
};
