// GFG
// BURNING TREE (HARD)
// MIMP

int maxDepth(Node *n){
    if (n == NULL){
        return 0;
    }
    return 1 + max(maxDepth(n->left), maxDepth(n->right));
}

int traverse(Node *n, int target, int &ret){
    if (n == NULL){
        return 0;
    }

    if (n->data == target){
        ret = max(ret, maxDepth(n->right));
        ret = max(ret, maxDepth(n->left));
        return 1;
    }

    int val = traverse(n->left, target, ret);
    
    if (val){  // (val != 0) means target was found at distance = val
        ret = max(ret, val + maxDepth(n->right));
        return val + 1;
    }

    val = traverse(n->right, target, ret);
    if (val){
        ret = max(ret, val + maxDepth(n->left));
        return val + 1;
    }

    return 0;
}

int minTime(Node *root, int target){
    int ret = 0;
    traverse(root, target, ret);
    return ret;
}