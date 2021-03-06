// Postorder to BST

Node *constructTreeUtil(int post[], int *postIndex, int key, int min, int max)
{
    if (*postIndex < 0)
    {
        return NULL;
    }

    Node *root = NULL;

    if (key > min && key < max)
    {
        root = new Node(key);
        *postIndex = *postIndex - 1;

        if (*postIndex >= 0)
        {
            root->right = constructTreeUtil(post, postIndex, post[*postIndex], key, max);

            root->left = constructTreeUtil(post, postIndex, post[*postIndex], min, key);
        }
    }
    return root;
}

Node *constructTree(int post[], int n)
{
    int postIndex = n - 1;
    return constructTreeUtil(post, &postIndex, post[postIndex], INT_MIN, INT_MAX);
}