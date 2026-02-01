#include<bits/stdc++.h>
using namespace std;

const int inf = 1e7;

int main(){
    int n, src;
    cin >> n >> src;

    vector<vector<pair<int, int>>> adj(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, inf), par(n, -1);

    int u, v, w;
    while(cin >> u >> v >> w){
        adj[u].push_back({v, w});
    }

    dist[src] = 0;

    pq.push({dist[src], src});

    while(!pq.empty()){
        u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if(du != dist[u]) continue;

        for(auto [v, w]: adj[u]){
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    for(auto& x: dist){
        if(x != inf) cout << x << " ";
        else cout << "inf ";
    }
    cout << endl;
}