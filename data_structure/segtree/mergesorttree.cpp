template<typename T>
struct mstree{
    int n;
    vector<vector<T>> tree;
    mstree(vector<T>& arr){
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int st, int ed, vector<T>& arr){
        if (st == ed){
            tree[node] = {arr[st]};
            return;
        }
        int md = (st + ed) / 2;
        build(node * 2, st, md, arr);
        build(node * 2 + 1, md + 1, ed, arr);
        tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
        merge(tree[node * 2].begin(), tree[node * 2].end(),
                tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), tree[node].begin());
    }
    int query(int node, int l, int r, int st, int ed, T k){
        if (r < st || ed < l) return 0;
        else if (l <= st && ed <= r){
            return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
        }
        int md = (st + ed) / 2;
        return query(node * 2, l, r, st, md, k) + query(node * 2 + 1, l, r, md + 1, ed, k);
    }
};
