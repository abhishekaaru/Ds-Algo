// everyone knows celebrity, but celebrity knows no one

int celebrity(vector<vector<int>> &a, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() >= 2)
    {

        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        if (a[i][j] == 1)
        {
            // i knows j then i is not a celebrity
            s.push(j);
        }
        else
        {
            // i does not know j then i can be a celebrity
            s.push(i);
        }
    }

    int pot = s.top(); // maybe last element is a celebrity
    s.pop();

    for (int i = 0; i < n; i++)
    {

        if (i != pot)  // (pot,pot)
        {

            if (a[i][pot] == 0 || a[pot][i] == 1)
            {

                return -1;
            }
        }
    }

    return pot;
}