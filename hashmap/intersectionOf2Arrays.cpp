class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>memo;
        
        for(auto i:nums1){
                memo[i] =  true;
        }
        
        vector<int> res;
        
        for(auto i :nums2){
            if(memo.find(i) != memo.end() and memo[i] == true){
                res.push_back(i);
                memo[i] = false;
            }
        }
        return res;
    }
};
