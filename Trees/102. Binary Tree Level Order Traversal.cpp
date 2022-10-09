102. Binary Tree Level Order Traversal
Medium
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Example 1:
    3
  9    20
     15   7
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
Approach:

The algorithm steps are stated as:

Take a queue data structure and push the root node to the queue.
Set a while loop which will run till our queue is non-empty.
In every iteration, pop out from the front of the queue and assign it to a variable (say temp).
If temp has a left child, push it to the queue.
If temp has a right child, push it to the queue.
At last push the value of the temp node to our “ans” data structure.
  
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
         if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int size = q.size();
            for(int i=0;i<size;i++){
            TreeNode* front = q.front();
            q.pop();
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
            level.push_back(front->val);
           
            }
            ans.push_back(level);
        }
       
        return ans;
    }
};
