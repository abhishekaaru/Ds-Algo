

Node *solve(vector<int> &nums, int st, int en)
{
    if (st >= en){
        return NULL;
    }
    
    int mid = (st + en) / 2;

    Node *root = new Node(nums[mid]);
    root->left = solve(nums, st, mid);
    root->right = solve(nums, mid + 1, en);

    return root;
}
vector<int> sortedArrayToBST(vector<int> &nums)
{

    vector<int> v;

    Node *root = solve(nums, 0, nums.size());

    return v;
}