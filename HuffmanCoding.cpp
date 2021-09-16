// Huffman encoding and decoding
// GFG

class MinHeapNode{
    public:
    char data;
    int freq;
    MinHeapNode* left;
    MinHeapNode* right;
    
    MinHeapNode(char c,int k){
        left = right = NULL;
        this->data = c;
        this->freq = k;
    }
};

struct compare{
    bool operator()(MinHeapNode* a,MinHeapNode* b){
        return a->freq > b->freq;
    }
};

// Encoding
	
void getCodes(MinHeapNode* root,string s,vector<string> &v){
	if(root==NULL){
	    return;
	}
	        
	if(root->data != '$'){
	    v.push_back(s);
	}
	getCodes(root->left,s+"0",v);
	getCodes(root->right,s+"1",v);
}
	    
vector<string> huffmanCodes(string s,vector<int> f,int N){
	vector<string> ans;
		    
		    
	priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> pq;
		    
	for(int i=0;i<s.size();i++){
		MinHeapNode* temp = new MinHeapNode(s[i],f[i]);
		pq.push(temp);
	}
		    
	while(pq.size()>1){
		MinHeapNode* left = pq.top();
		pq.pop();
		        
		MinHeapNode* right = pq.top();
		pq.pop();
		        
		MinHeapNode* top = new MinHeapNode('$',left->freq + right->freq);
		top->left = left;
		top->right = right;
		        
		pq.push(top);
	}
		    
	getCodes(pq.top(),"",ans);
		    
	return ans;
}

// Decoding 

string decoding(MinHeapNode* root, string s)
{
    string ans = "";
    MinHeapNode* temp = root;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            temp = temp->left;
        }
        else if(s[i]=='1'){
            temp = temp->right;
        }
        
        if(temp->left == NULL && temp->right == NULL){
            ans += temp->data;
            temp = root;
        }
    }
    
    return ans;
    
}