//17412 정답 코드
#include <bits/stdc++.h>
#define INF 1e18
using namespace std;
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
using ll = long long;
using pll = pair<ll, ll>;
ll cap[401][401], flow[401][401];
ll work[401], lv[401];
vector<ll> edge[401];
ll st = 1, ed = 2;
ll n, e;
bool bfs(){
    memset(lv, -1, sizeof(lv));
    lv[1] = 0;
    queue<ll> q; q.push(1);
    while (!q.empty()){
        ll pos = q.front(); q.pop();
        for (ll nxt: edge[pos]){
            if (lv[nxt] == -1 && cap[pos][nxt] - flow[pos][nxt] > 0){
                lv[nxt] = lv[pos] + 1;
                q.push(nxt);
            }
        }
    }
    return lv[ed] != -1;
}
ll dfs(ll pos, ll fw){
    if (pos == 2)   return fw;
    for (ll &i = work[pos]; i < edge[pos].size(); i++){
        ll nxt = edge[pos][i];
        if (lv[nxt] == lv[pos] + 1 && cap[pos][nxt] - flow[pos][nxt] > 0){
            ll rt = dfs(nxt, min(cap[pos][nxt] - flow[pos][nxt], fw));
            if (rt){
                flow[pos][nxt] += rt; flow[nxt][pos] -= rt; return rt;
            }
        }
    }
    return 0;
}
int main() {
    fastio
    cin >> n >> e;
    for (ll i = 0; i < e; i++){
        ll u, v; cin >> u >> v;
        if (!cap[u][v]) {
            edge[u].emplace_back(v);
            edge[v].emplace_back(u);
        }
        cap[u][v]++;
    }
    ll ans = 0;
    ll flowed = 0;
    while (bfs()){
        memset(work, 0, sizeof(work));
        do{
            flowed = dfs(1, INF);
            ans += flowed;
        }while (flowed);
    }
    cout << ans;
    return 0;
}
