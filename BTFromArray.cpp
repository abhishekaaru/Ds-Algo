// Construt a binary tree from array
// GFG

void createNode(int parent[], int i, Node *created[], Node **root)
{
    if (created[i] != NULL)
    {
        return;
    }

    created[i] = new Node(i);

    if (parent[i] == -1)
    {
        *root = created[i];
        return;
    }

    if (created[parent[i]] == NULL)
    {
        createNode(parent, parent[i], created, root);
    }

    Node *p = created[parent[i]];

    if (p->left == NULL)
    {
        p->left = created[i];
    }
    else
    {
        p->right = created[i];
    }
}

Node *createTree(int parent[], int n)
{
    Node *created[n];

    for (int i = 0; i < n; i++)
    {
        created[i] = NULL;
    }

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        createNode(parent, i, created, &root);
    }

    return root;
}