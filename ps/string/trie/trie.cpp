//Warning! solution of 13505!
struct trie{
    trie* node[2]; bool end;
    trie(){
        end = false;
        for (int i = 0; i < 10; i++) node[i] = NULL;
    }
    ~trie(){
        for (int i = 0; i < 10; i++) node[i] = nullptr;
    }
    void insert(ll num, ll depth){
        if (depth == 31){
            this->end = true; return;
        }
        bool bit = num & (1 << (30 - depth));
        if (!node[bit])   node[bit] = new trie();
        node[bit]->insert(num, depth + 1);
    }
    ll find_mx(ll num, ll depth){
        if (depth == 31)    return 0;
        bool bit = num & (1 << (30 - depth));
        if (node[(bit + 1) & 1]) {
            return (1 << (30 - depth)) | node[(bit + 1) & 1]->find_mx(num, depth + 1);
        }
        else if (node[bit & 1]) return node[bit & 1]->find_mx(num, depth + 1);
        return 0;
    }
};
