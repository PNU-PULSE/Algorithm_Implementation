#define MAX_N 100000
using namespace std;
using ll = long long;
vector<ll> edge[MAX_N];
bool cutvertex[MAX_N];
ll visited[10010];
ll v, e, cnt, idx;
ll dfs(ll pos, bool root){
    visited[pos] = ++idx;
    ll rt = idx;
    ll child = 0;
    for (ll nxt : edge[pos]){
        if (visited[nxt]){
            rt = min(rt, visited[nxt]); continue;
        }

        child++;
        ll i = dfs(nxt, false);
        if (!root && i >= visited[pos]) {
            cnt += !cutvertex[pos]; cutvertex[pos] = true;
        }
        rt = min(rt, i);
    }

    if (root && (child > 1))  {
        cutvertex[pos] = true; cnt++;
    }
    return rt;
}
