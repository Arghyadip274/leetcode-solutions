class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>hash;
        for (auto i:nums){
            ++hash[i];
        }
        while(k--){
            auto it=hash.begin();
            int c=0;
            int b=0;
            while (it!=hash.end()){
                if (it->second>=c){
                    c=it->second;
                    b=it->first;
                }
                it++;
            }
            res.push_back(b);
            hash.erase(b);


        }
        sort(res.begin(),res.end());
        return res;
    }
};
