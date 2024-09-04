struct Trie{
    Trie *go[26]{};
    Trie *fail{};
    bool output;

    Trie(){
        fill(go, go + 26, nullptr); output = false;
    }
    ~Trie(){
        for (auto & i : go) delete i;
    }
    void insert(const string& key, int idx = 0){
        if (idx == key.size()){
            output = true; return;
        }
        int nxt = key[idx] - 'a';
        if (!go[nxt]) go[nxt] = new Trie();
        go[nxt]->insert(key, idx + 1);
    }
};

void fail_link(Trie* root){
    queue<Trie*> Q; root->fail = root;
    Q.push(root);
    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < 26; i++){
            Trie* nxt = cur->go[i];
            if (nxt == nullptr) continue;

            if (cur == root) {
                nxt->fail = root;
            }
            else{
                Trie* dest = cur->fail;
                while (dest != root && dest->go[i] == nullptr){
                    dest = dest->fail;
                }
                if (dest->go[i]) dest = dest->go[i];
                nxt->fail = dest;
            }

            if (nxt->fail->output) nxt->output = true;
            Q.push(nxt);
        }
    }
}

bool find(string& str, Trie* root){
    Trie* cur = root;
    bool ans = false;
    for (int i = 0; str[i]; i++){
        int nxt = str[i] - 'a';
        while (cur != root && cur->go[nxt] == nullptr){
            cur = cur->fail;
        }
        if (cur->go[nxt]) cur = cur->go[nxt];
        if (cur->output){
            ans = true; break;
        }
    }
    return ans;
}
