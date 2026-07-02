class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> v;
        v.push_back({1});
        if (numRows>=2){
            v.push_back({1,1});
        }
        for ( int i=2;i<numRows;i++){
            vector <int> temp;
            for ( int j=0;j<=i;j++){
                if (j==0||j==i){
                    temp.push_back(1);
                }
                else{
                    int t;
                    t=v[i-1][j-1]+v[i-1][j];
                    temp.push_back(t);
                }
            }
            v.push_back(temp);
        }
        return v;

    }
};
