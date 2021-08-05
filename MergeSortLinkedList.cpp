

void findMiddle(Node *curr, Node **first, Node **second)
{

    Node *slow = curr;
    Node *fast = curr->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *first = curr;
    *second = slow->next;
    slow->next = NULL;
}

Node *MergeBoth(Node *first, Node *second)
{

    if (first == NULL)
    {
        return second;
    }
    else if (second == NULL)
    {
        return first;
    }

    Node *result = NULL;

    if (first->data <= second->data)
    {
        result = first;
        result->next = MergeBoth(first->next, second);
    }
    else
    {
        result = second;
        result->next = MergeBoth(first, second->next);
    }

    return result;
}

void MergeSorting(Node **head)
{
    Node *curr = *head;
    Node *first;
    Node *second;

    if (curr == NULL || curr->next == NULL)
    {
        return;
    }

    findMiddle(curr, &first, &second);

    MergeSorting(&first);
    MergeSorting(&second);

    *head = MergeBoth(first, second);
}

Node *mergeSort(Node *head)
{

    MergeSorting(&head);

    return head;
}