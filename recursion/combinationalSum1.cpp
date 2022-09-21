Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
  
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.  
  -----------------------------------------------------------------------------------------------------------------------------------------------------------
//if there is given an array and we have to pick some items we can use pick/nonpick 
  class Solution {
public:
    void f(int ind,vector<int>&ds,int target,vector<int>&arr,vector<vector<int>>&ans){
        if(ind == arr.size()){
            if(target == 0){
               ans.push_back(ds);
            }
            return;
        }
        
        //pick up
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            f(ind,ds,target-arr[ind],arr,ans);
            ds.pop_back();
        }
        f(ind+1,ds,target,arr,ans);
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,ds,target,candidates,ans);
        return ans;
    }
};
