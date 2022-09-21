//if asked to return only one ans just return true if base case is satisfied
#include <bits/stdc++.h> 
bool f(int ind,vector<int>&ds,int sum,int n,int k,vector<int>&arr){
    if(ind == n){
        if(k == sum){
            return true;
        }
        return false;
    }
    //take
    ds.push_back(arr[ind]);
    sum += arr[ind];
    if (f(ind+1,ds,sum,n,k,arr) == true){
        return true;
    }
    //not take
    sum-= arr[ind];
    ds.pop_back();
    if( f(ind+1,ds,sum,n,k,arr) == true){
        return true;
    }
    
    return false;
    
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<int>ds;
   return f(0,ds,0,n,k,arr);
}
