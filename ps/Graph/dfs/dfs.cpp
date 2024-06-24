#define MAX_N 100000
vector<int> edge[MAX_N];
bool visited[MAX_N];
vector<int> order;
void dfs(int i){
    visited[i] = 1;
    for (int nxt: edge[v]){
        if (visited[nxt])  continue;
            dfs(nxt);
    }
}

int main(){
    dfs(1);
    for (int i: order)    cout << i << "\n";
}
