using ll = long long;
ll path[100001][21];
ll depth[100001];
int n;
vector<int> edge[100001];
void dfs(int node, int par){
	depth[node] = depth[par] + 1;
	for(auto& nxt : edge[node]){
		if (nxt != par){
            path[nxt][0] = node;
            dfs(nxt, node);
        }
	}
}

void sparse(){
	for(int j=1; j<=20; j++){
		for(int i=1; i<=n; i++){
			path[i][j] = path[ path[i][j-1] ][j-1];
		}
	}
}

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
    ll i = 0;
	while (diff){
        if (diff & 1) u = path[u][i];
        i++; diff >>= 1;
    }
	if(u == v) return u;

	for(int i=20; i>=0; i--){
		if(path[u][i] != path[v][i]) u = path[u][i], v = path[v][i];
	}
	return path[u][0];
}
