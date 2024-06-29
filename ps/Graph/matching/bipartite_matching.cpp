#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;
int n, m;
int a[1001];
int b[1001];
int visited[1001];
vector<int> edge[1001];
bool dfs(int pos){
    visited[pos] = true;
    for (int nxt: edge[pos]){
        if (b[nxt] == -1 || (!visited[b[nxt]] && dfs(b[nxt]))){
            a[pos] = nxt; b[nxt] = pos; return true;
        }
    }
    return false;
}
void bipartite_matching() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        while (x--){
            ll nxt; cin >> nxt;
            edge[i].emplace_back(nxt);
        }
    }
    int match = 0;
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    for (int i = 1; i <= n; i++){
        if (a[i] == -1){
            memset(visited, 0, sizeof(visited));
            if (dfs(i)) match++;
        }
    }
    return match;
}
