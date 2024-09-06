int Edmond_Karp(){
    int n, p; cin >> n >> p;
    int st = 1, ed = 2;
    vector<vector<int>> cap(n + 1, vector<int>(n + 1));
    vector<vector<int>> flow(n + 1, vector<int>(n + 1));
    vector<int> edge[n + 1];
    while (p--){
        int u, v, w = 1; cin >> u >> v;// >> w
        cap[u][v] += w; edge[u].emplace_back(v); edge[v].emplace_back(u);
    }
    int answer = 0;
    int parent[n + 1];
  
    while (true){
        queue<int> q; q.push(st);
        memset(parent, -1, sizeof(parent));
        //bfs로 다음 경로 구하기
        while (!q.empty()){
            int now = q.front(); q.pop();
            for (int nxt: edge[now]){
                if (cap[now][nxt] - flow[now][nxt] > 0 && parent[nxt] == -1){
                    q.push(nxt); parent[nxt] = now;
                    if (nxt == ed)  break;
                }
            }
        }
        //만약 더 이상 augmenting path가 존재하지 않으면 maximum flow
        if (parent[ed] == -1)   break;

        
        int mn = 1e9;
        for (int i = ed; i != st; i = parent[i])    mn = min(mn, cap[parent[i]][i] - flow[parent[i]][i]);
        for (int i = ed; i != st; i = parent[i]) {
            flow[parent[i]][i] += mn; //잔여 네트워크에서 flow 흘림
            flow[i][parent[i]] -= mn; 
        }
        answer += mn;
    }
    return answer;
}
