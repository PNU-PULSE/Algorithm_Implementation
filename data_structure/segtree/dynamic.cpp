//reference: https://justicehui.github.io/medium-algorithm/2020/02/28/DynamicSeg/
struct Node{
    Node *l, *r;
    ll tsum;//구간 합
    Node(): l(nullptr), r(nullptr), tsum(0) {}
};
void update(Node *node, int s, int e, int p, ll val){
    if (s == e){
        node->tsum = val; return;
    }
    int m = (s + e) >> 1;
    if (p <= m){//l, r을 반으로 나눠서 구간 선택, 나머지는 일반적인 세그와 동일
        if (!node->l) node->l = new Node();
        update(node->l, s, m, p, val);
    }
    else{
        if (!node->r) node->r = new Node();
        update(node->r, m + 1, e, p, val);
    }
    ll left_t = (node->l) ? node->l->tsum : 0;
    ll right_t = (node->r) ? node->r->tsum : 0;
    node->tsum = left_t + right_t;
}
ll query(Node *node, int s, int e, int le, int ri){
    if (!node || ri < s || e < le) return 0;
    if (le <= s && e <= ri) return node->tsum;
    int m = (s + e) >> 1;
    return query(node->l, s, m, le, ri) + query(node->r, m + 1, e, le, ri);
}
