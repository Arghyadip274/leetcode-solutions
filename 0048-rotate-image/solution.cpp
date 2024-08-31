class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int dim=matrix[0].size();
        for (int i=0;i<dim;i++){
            for (int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i=0;i<dim;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
