class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // for (int i=0;i<=paths.size()){
        //     string a= paths[i][]
        // }
        unordered_set<string> hash;
        for (int i=0;i<paths.size();i++){
            hash.insert(paths[i][0]);
        }
        for (int i=0;i<paths.size();i++){
            string c=paths[i][1];
            if (hash.find(c)==hash.end()){
                return c;
            }
        }
        return"";
    }
};
