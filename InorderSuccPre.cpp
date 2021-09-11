// Predecessor and Successor 
// GFG
// IMP


// left then extreme right
Node *inPre(Node *root)
{
    Node *temp = root->left;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}


// right then extreme left
Node *inSuc(Node *root)
{
    Node *temp = root->right;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
    {
        return;
    }

    if (root->key == key)
    {
        if (root->left)
        {
            pre = inPre(root);
        }
        if (root->right)
        {
            suc = inSuc(root);
        }
        return;
    }

    if (key > root->key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else if (key < root->key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}