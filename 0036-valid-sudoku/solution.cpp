class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& nums) {
        bool res1=1,res2=1,res3=1;
        unordered_map<char,int> hash1;
        unordered_map<char,int> hash2;
        unordered_map<char,int>hash3;
        for (int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                hash1[nums[i][j]]++;
            }
            auto it=hash1.begin();
            while(it!=hash1.end()){
                if(it->second>1 && it->first!='.'){
                    return false;
                }
                it++;
            }
            for (int j=0;j<9;j++){
                hash2[nums[j][i]]++;
            }
            auto itt=hash2.begin();
            while(itt!=hash2.end()){
                if(itt->second>1 && itt->first!='.'){
                    return false;
                }
                itt++;
            }

            hash1.clear();
            hash2.clear();
        }
        for(int i=0 ; i < 9 ;i+=3){
            for(int j=0 ; j <9 ;j+=3){
                hash3.clear();
                for(int x = i ; x < i+3 ; x++){
                    for(int y = j ; y < j+3; y++){
                        if(nums[x][y]!='.'){
                            hash3[nums[x][y]]++;
                        }
                        if(hash3[nums[x][y]]>1){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
