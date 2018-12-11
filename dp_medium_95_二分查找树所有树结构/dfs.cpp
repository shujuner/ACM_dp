class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> tree;                //tree代表以root为根节点的所有树
        if(n == 0) {
            return tree;
        }
        dfs(1, n, tree);
        return tree;
    }
private:
    void dfs(int start, int end, vector<TreeNode*>& tree) {
        if(start > end) {
            tree.push_back(NULL);   // we must push a NULL value for integration
            return;
        }
        for(int i = start; i <= end; ++i) {//以i为value创建root结点
            // important notation: the left and right should be the copy, not the reference
            vector<TreeNode*> left; //left中存储了以left为根节点的时候所有的树情况 
            vector<TreeNode*> right;//right中存储了以right为根节点的所有的树情况
            dfs(start, i - 1, left); //制造左树
            dfs(i + 1, end, right); //制造右树
            for(int j = 0; j < left.size(); ++j) { //将所有以left[j]为左树，right[k]为右树的情况遍历加入到root树中
                for(int k = 0; k < right.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    tree.push_back(root);
                }
            }
        }
    }
};
