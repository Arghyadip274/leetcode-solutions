class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int r=n-1;
        while(l<m and r>=0){
            if(matrix[l][r]==target) return 1;
            else if(matrix[l][r]>target) r--;
            else l++;
        }
        return 0;
    }
};
