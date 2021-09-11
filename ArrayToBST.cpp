

// METHOD 1
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

// Method 2 (GFG) (100% solution)
Node *solve1(vector<int> &nums, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        Node *root = new Node(nums[mid]);
        root->left = solve(nums, low, mid - 1);
        root->right = solve(nums, mid + 1, high);
        return root;
    }
    return NULL;
}



vector<int> sortedArrayToBST(vector<int> &nums)
{

    vector<int> v;

    // Node *root = solve(nums, 0, nums.size());
    Node *root = solve1(,nums, 0, nums.size()-1);

    return v;
}