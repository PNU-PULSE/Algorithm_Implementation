//reference: https://justicehui.github.io/medium-algorithm/2020/02/28/DynamicSeg/
struct Node{
    Node *l, *r;
    ll value;
    Node(): l(nullptr), r(nullptr), value(0) {}
};
struct segtree{
    Node *root;
    segtree(): root(new Node()) {}
    void up(ll s, ll e, ll p, ll val){
        update(root, s, e, p, val);
    }
    ll qu(ll s, ll e, ll l, ll r){
        return query(root, s, e, l, r);
    }
    void update(Node *node, ll s, ll e, ll p, ll val){
        if (s == e){
            node->value = val; return;
        }
        ll m = (s + e) >> 1;
        if (p <= m){
            if (!node->l) node->l = new Node();
            update(node->l, s, m, p, val);
        }
        else{
            if (!node->r) node->r = new Node();
            update(node->r, m + 1, e, p, val);
        }
        ll lt = (node->l) ? node->l->value : 0;
        ll rt = (node->r) ? node->r->value : 0;
        node->value = lt + rt;
    }
    ll query(Node *node, ll s, ll e, ll l, ll r){
        if (!node || e < l || r < s) return 0;
        if (l <= s && e <= r) return node->value;
        ll m = (s + e) >> 1;
        return query(node->l, s, m, l, r) +
                query(node->r, m + 1, e, l, r);
    }
};
