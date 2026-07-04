class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n=cit.size();
        int l=0;
        int r=n; 
        while (l<r){
            int mid=l+(r-l)/2;
            if(cit[mid]>=n-mid) r=mid;
            else l=mid+1;
        }
        return n-l;
    }
};
