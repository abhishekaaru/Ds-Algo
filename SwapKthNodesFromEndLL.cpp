

Node *swapkthnode(Node *head, int n, int k)
{
    if (k > n)
    {
        return head;
    }

    if (2 * k - 1 == n)
    {
        // same node
        return head;
    }

    //finding the kth node from the beginning of list. We also find node
    //previous of kth node because we need to update next pointer of
    // the previous node.

    Node *X = head;
    Node *Xptr = NULL;
    int count = k - 1;
    while (count--)
    {
        Xptr = X;
        X = X->next;
    }

    //similarly, finding the kth node from end and its previous node. kth node
    //from end is (num-k+1)th node from beginning .

    Node *Y = head;
    Node *Yptr = NULL;
    count = n - k;
    while (count--)
    {
        Yptr = Y;
        Y = Y->next;
    }

    //if xptr exists, then new next of it will be y.
    if (Xptr)
    {
        Xptr->next = Y;
    }

    //if yptr exists, then new next of it will be x.
    if (Yptr)
    {
        Yptr->next = X;
    }

    // Swap
    Node *temp = X->next;
    X->next = Y->next;
    Y->next = temp;

    //changing head pointers when k is 1 or num.
    if (k == 1)
    {
        return Y;
    }
    if (k == n)
    {
        return X;
    }

    return head;
}