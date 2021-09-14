//GFG

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKLists(Node *a[], int k)
{
    priority_queue<Node *, vector<Node *>, compare> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(a[i]);
    }

    Node *dummy = new Node(0);
    Node *temp = dummy;

    while (!pq.empty())
    {
        Node *curr = pq.top();
        pq.pop();

        temp->next = curr;
        temp = curr;

        if (curr->next)
        {
            pq.push(curr->next);
        }
    }
    return dummy->next;
}