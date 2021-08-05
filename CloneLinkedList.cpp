// Clone a linked list with next and random pointer

    struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

//Function to clone a linked list with next and random pointer.
Node *copyList(Node *head)
{
    Node *iter = head;
    Node *front = head;

    // First round: make copy of each node,
    // and link them together side-by-side in a single list.
    while (iter != NULL)
    {
        front = iter->next;

        Node *copy = new Node(iter->data);
        iter->next = copy;
        copy->next = front;

        iter = front;
    }

    // Second round: assign random pointers for the copy nodes.
    iter = head;
    while (iter != NULL)
    {
        if (iter->arb != NULL)
        {
            iter->next->arb = iter->arb->next;
        }
        iter = iter->next->next;
    }

    // Third round: restore the original list, and extract the copy list.
    iter = head;
    Node *pseudoHead = new Node(0);
    Node *copy = pseudoHead;

    while (iter != NULL)
    {
        front = iter->next->next;

        // extract the copy
        copy->next = iter->next;

        // restore the original list
        iter->next = front;

        copy = copy->next;
        iter = front;
    }

    return pseudoHead->next;
}