void convert(Node *head, TreeNode *&root)
{

    if (head == NULL)
    {
        root = NULL;
        return;
    }

    queue<TreeNode *> q;
    root = new TreeNode(head->data);
    q.push(root);

    head = head->next;

    while (head)
    {
        TreeNode *temp = q.front();
        q.pop();

        TreeNode *l = new TreeNode(head->data);
        q.push(l);
        head = head->next;

        TreeNode *r = NULL;

        if (head)
        {
            r = new TreeNode(head->data);
            head = head->next;
            q.push(r);
        }

        temp->left = l;
        temp->right = r;
    }
}