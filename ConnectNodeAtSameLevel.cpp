// Connect Nodes at Same Level
// GFG (IMP)

void connect(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        int n = q.size();

        while (n--)
        {

            if (q.front() == NULL)
            {
                q.pop();
                break;
            }

            Node *temp = q.front();
            q.pop();

            temp->nextRight = q.front();

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        if (!q.empty())
        {
            q.push(NULL);
        }
    }
}