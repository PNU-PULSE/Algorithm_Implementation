//tarjan al
bool finished[10001];
vector<int> edge[10001];
stack<int> st;
int scc_cnt = 0;
int dfs(int now){
    int cur = num; parent[now] = num++; st.push(now);
    for (auto nxt: edge[now]){
        if (!parent[nxt]){
            parent[now] = min(parent[now], dfs(nxt));
        }
        else if (!finished[nxt]){
            parent[now] = min(parent[nxt], parent[now]);
        }
    }
    if (parent[now] == cur){
        vector<int> scc;
        int pos = -1;
        do{
            pos = st.top(); scc.emplace_back(pos); finished[pos] = true; st.pop();
        } while(pos != now);
        cnt[++scc_cnt] = scc.size();
        for (auto x: scc) uf[x] = scc_cnt;
    }
    return parent[now];
}
