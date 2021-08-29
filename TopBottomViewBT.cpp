// Most Important

// Top View Of Binary Tree
vector<int> topView(Node *root)
{
    vector<int> v;
    map<int, int> mp;
    queue<pair<Node *, int>> q;

    if (root == NULL)
    {
        return v;
    }

    q.push({root, 0});

    while (!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;
        q.pop();

        if (!mp[h])
        {
            mp[h] = temp->data;
        }

        if (temp->left)
        {
            q.push({temp->left, h - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, h + 1});
        }
    }

    for (auto i : mp)
    {
        v.push_back(i.second);
    }

    return v;
}

// Bottom View of binary tree

vector<int> bottomView(Node *root)
{
    vector<int> v;
    map<int, int> mp;
    queue<pair<Node *, int>> q;

    if (root == NULL)
    {
        return v;
    }

    q.push({root, 0});

    while (!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;
        q.pop();

        mp[h] = temp->data;

        if (temp->left)
        {
            q.push({temp->left, h - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, h + 1});
        }
    }

    for (auto i : mp)
    {
        v.push_back(i.second);
    }

    return v;
}