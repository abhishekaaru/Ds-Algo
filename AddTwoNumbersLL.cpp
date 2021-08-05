struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    struct Node *dummy = new Node(0);
    struct Node *temp = dummy;

    int carry = 0;


    while (first != NULL || second != NULL || carry)
    {

        int sum = 0;

        if (first != NULL)
        {
            sum += first->data;
            first = first->next;
        }
        if (second != NULL)
        {
            sum += second->data;
            second = second->next;
        }

        sum += carry;
        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}

// 2->4->3            342
// 5->6->7->9         9765

// 0->7->0->1->0->1   10107