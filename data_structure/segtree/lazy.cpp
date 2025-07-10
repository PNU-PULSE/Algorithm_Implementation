template <typename T>
struct lazyseg{
    int h; vector<T> tree, lazy;
    lazyseg(int n): h(0) {
        h = 1 << ((int)ceil(log2(n)) + 1);
        tree.resize(h); lazy.resize(h);
    };
    void init(vector<T>& arr, int node, int st, int ed){
        if (st == ed){
            tree[node] = arr[st];
        }
        else{
            init(arr, node * 2, st, (st + ed) / 2);
            init(arr, node * 2 + 1, (st + ed) / 2 + 1, ed);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
    void lzup(int node, int st, int ed){
        if (lazy[node] != 0){
            tree[node] += (ed - st + 1) * lazy[node];
            if (st != ed){
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(int node, int l, int r, int st, int ed, T diff){
        lzup(node, st, ed);
        if (l > ed || r < st) return;
        if (l <= st && ed <= r){
            tree[node] += (ed - st + 1) * diff;
            if (st != ed){
                lazy[node * 2] += diff;
                lazy[node * 2 + 1] += diff;
            }
            return;
        }
        update(node * 2, l, r, st, (st + ed) / 2, diff);
        update(node * 2 + 1, l, r, (st + ed) / 2 + 1, ed, diff);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    T query(int node, int l, int r, int st, int ed){
        lzup(node, st, ed);
        if (l > ed || r < st) return 0;
        if (l <= st && ed <= r) return tree[node];

        T lsum = query(node * 2, l, r, st, (st + ed) / 2);
        T rsum = query(node * 2 + 1, l, r, (st + ed) / 2 + 1, ed);
        return lsum + rsum;
    }
};
