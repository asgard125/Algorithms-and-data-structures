void build_tree(int tree[], int v, int tl, int tr, int arr[]){
    if (tl == tr){
        tree[v] = arr[tl];
    }else{
        int mid = (tl+tr)/2;
        build_tree(tree, v * 2, tl, mid, arr);
        build_tree(tree, v * 2 + 1, mid + 1, tr, arr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int find_max(int *tree, int v, int tl, int tr, int l, int r){
    if (l > r){
        return -1000000000;
    }
    if (l == tl && r == tr){
        return tree[v];
    }
    int mid = (tl + tr) / 2;
    return max(find_max(tree, v*2, tl, mid, l, min(r, mid)), find_max(tree, v*2 + 1, mid + 1, tr, max(l, mid + 1), r));
}