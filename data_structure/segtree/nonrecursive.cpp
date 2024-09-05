template<typename T>
struct segtree{
    int sz, n;
    vector<T> seg;
    segtree(): sz(0) {}
    segtree(int sz): sz(sz){seg.resize(2 * sz, 0LL);}
    T& operator[](int idx){return seg[idx];}
    void init(int n){
        for (int i = 0; i < n; i++) cin >> seg[sz + i];
        for (int i = sz - 1; i > 0; i--) seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
    void update(int pos, T val){
        seg[sz + pos] = val;
        for (pos += sz; pos > 1; pos >>= 1){
            seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
        }
    }
    T query(int l, int r){
        T ans = 0;
        for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1){
            if (l&1) ans += seg[l++];
            if (~r&1) ans += seg[r--];
        }
        return ans;
    }
};
