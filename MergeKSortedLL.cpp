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

// leetcode

ListNode* mergeTwoLists(ListNode* a, ListNode* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    ListNode* head=NULL;
    if(a->val <= b->val)
    {   head=a;
        head->next = mergeTwoLists(a->next, b);
            
    }
    else{
       head=b;
        head->next = mergeTwoLists(a, b->next);
            
    }
    return head;
}
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        
        ListNode* res=lists[0];
        
        for(int i=1;i<lists.size();i++){
            res=mergeTwoLists(res,lists[i]);
            
        }
        return res;
    }

// leetcode

class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<int, vector<int> , greater<int>> pq; //minheap
        for(int i=0; i<lists.size(); i++){ //push all the elements into minheap
            ListNode* temp = lists[i]; //temp pointing to first element of ith vector.
            while(temp){ //insert first vector in the minheap until temp becomes null
                pq.push(temp->val);
                temp = temp->next;
            }//then keep on adding all the vectors as i progress
        }
        ListNode* dummy = new ListNode(-1); //create a dummy node
        ListNode* curr = dummy; //iterate the list using curr
        
        while(!pq.empty()){ //while your min heap is not empty
            ListNode* temp = new ListNode(pq.top());  //add the minimum in the list
            pq.pop(); //remove the top from pq and minheapify will be called.
            curr->next = temp; //now next of curr will be the minimum which is stored in temp
            curr = curr->next; //now move current pointer and keep on adding the top of minheap
        }//and keep on doing this unless minheap is not empty
        return dummy->next; //at the end, return the dummy next which contains your sorted list.
        
    }
};


// My soln

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>&a) {
        int n = a.size();
        
        if(n==0){
            return NULL;
        }
        
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        vector<int> v;
        
        for(int i=0;i<n;i++){
            ListNode* curr = a[i];
            
            while(curr != NULL){
                v.push_back(curr->val);
                curr = curr->next;
            }
        }
        
        if(v.empty()){
            return NULL;
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++){
            temp->val = v[i];
            if(i==v.size()-1){
                break;
            }
            temp->next = new ListNode();
            temp = temp->next;
        }
        
        return dummy;
        
    }
};