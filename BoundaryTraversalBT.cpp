// Boundary Traversal
// GFG
// MIMP

// excluding leaf node
void left(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left)
    {
        v.push_back(root->data);
        left(root->left, v);
    }
    else if (root->right)
    {
        v.push_back(root->data);
        left(root->right, v);
    }
}

void leaf(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    leaf(root->left, v);
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->data);
    }
    leaf(root->right, v);
}

// excluding leaf node
void right(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right)
    {
        right(root->right, v);
        v.push_back(root->data);
    }
    else if (root->left)
    {
        right(root->left, v);
        v.push_back(root->data);
    }
}

vector<int> printBoundary(Node *root)
{
    vector<int> v;
    v.push_back(root->data);

    left(root->left, v);
    leaf(root, v);
    right(root->right, v);

    return v;
}