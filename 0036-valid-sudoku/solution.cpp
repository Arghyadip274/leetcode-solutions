class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> hash1, hash2, hash3;
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                hash1[board[i][j]]++;
            }
            for (auto it: hash1){
                if (it.second > 1 and it.first !='.') return false;
            }
            for (int j=0;j<9;j++){
                hash2[board[j][i]]++;
            }
            for (auto it: hash2){
                if (it.second >1 and it.first !='.') return false;
            }
            hash1.clear();
            hash2.clear();
        }

        for(int i=0;i<9;i+=3){
            for (int j=0; j<9;j+=3){
                hash3.clear();
                for (int x=i;x<i+3;x++){
                    for (int y=j;y<j+3;y++){
                        if (board[x][y]!='.') hash3[board[x][y]]++;

                        if (hash3[board[x][y]]>1) return false;
                    }
                }
            }
        }
        return true;

    }
};
