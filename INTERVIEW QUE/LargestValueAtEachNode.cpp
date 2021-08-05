// O(n)
// using DFS

void inorder(TreeNode *root, vector<int> &res, int k)
{
    if (root == NULL)
        return;
    if (k == res.size())          //if no element of level k is pushed into res
        res.push_back(root->val); // push root val
    else
        res[k] = max(res[k], root->val); // else update the max among res[k] and curr root val
    inorder(root->left, res, k + 1);
    inorder(root->right, res, k + 1);
}

vector<int> largestValues(TreeNode *root)
{
    vector<int> res;
    inorder(root, res, 0);
    return res;
}