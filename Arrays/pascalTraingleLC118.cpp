// You are given an integer N. Your task is to return a 2-D ArrayList containing the pascal’s triangle till the row N.
// A Pascal's triangle is a triangular array constructed by summing adjacent elements in preceding rows. Pascal's triangle contains the values of the binomial coefficient. For example in the figure below.
// // Sample Input 1 :
//  3
// 1
// 2
// 3
// Sample Output 1 :
// 1
// 1 
// 1 1 
// 1 
// 1 1 
// 1 2 1 
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        for(int i =0;i<n;i++){
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
           
           for(int j =1;j<i;j++){
               ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
           } 
        }
        return ans;
    }
    
};
