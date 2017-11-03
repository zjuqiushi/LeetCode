You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

题意：找出数中每行最大的元素

思路：DFS/BFS

Me:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> tmp;
    vector<int> ans;
    int maxdepth = -1;
    void process(TreeNode* root, int depth, int &maxdepth){
        if(depth > maxdepth)
            maxdepth = depth;
        if(tmp[depth] < root->val)
            tmp[depth] = root->val;
        if(root->left != NULL)
            process(root->left, depth+1, maxdepth);
        if(root->right != NULL)
            process(root->right, depth+1, maxdepth);
    }
    vector<int> largestValues(TreeNode* root) {
        tmp.resize(2000, -2147483648);
        if(root == NULL)
            return ans;
        process(root, 0, maxdepth);
        for(int i=0;i<=maxdepth;i++)
            ans.push_back(tmp[i]);
        return ans;
    }
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> T;
        if(root == NULL)
            return ans;
        T.push(root);
        while(!T.empty()){
            int max = INT_MIN;
            int n = T.size();
            for(int i=0;i<n;i++){
                TreeNode* tmp = T.front();
                if(max < tmp->val)
                    max = tmp->val;
                if(tmp->left != NULL)
                    T.push(tmp->left);
                if(tmp->right != NULL)
                    T.push(tmp->right);
                T.pop();
            }
            ans.push_back(max);
        }
        return ans;
    }
};

Discuss:
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> T;
        vector<int> result;
        T.push(root);
        bool flag = true;
        while(flag){
            flag = false;
            int len = T.size();
            int ans = INT_MIN;
            for(int i = 0; i < len; i++){
                TreeNode* now = T.front();
                ans = max(ans, now->val);
                if(now->left){
                    T.push(now->left);
                    flag = true;
                }
                if(now->right){
                    T.push(now->right);
                    flag = true;
                }
                T.pop();
            }
            result.push_back(ans);
        }
        return result;
    }
};
