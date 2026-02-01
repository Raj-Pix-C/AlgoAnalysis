#include<bits/stdc++.h>
#define INF 1e7
using namespace std;

bool bellman_ford(vector<vector<pair<int, int>>>& adj, vector<int>& d, int s, int V){
    d[s] = 0;

    for(int i = 0; i < V-1; i++){
        for(int u = 0; u < V; u++){
            for(auto& [v, w]:adj[u]){
                if(d[u] != INF && d[u]+w < d[v]){
                    d[v] = d[u]+w;
                }
            }
        }
    }

    for(int u = 0; u < V; u++){
        for(auto& [v, w]:adj[u]){
            if(d[u] != INF && d[u]+w < d[v]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, src;
    cin >> n >> src;

    vector<vector<pair<int, int>>> adj(n);
    vector<int> dis(n, INF);

    int u, v, w;
    while (cin >> u >> v >> w){
        adj[u].push_back({v, w});
    }

    if(bellman_ford(adj, dis, src, n)){
        cout << "No Negative Cycle.\n";
        for(auto& d:dis){
            if(d != INF)
                cout << d << " ";
            else cout << "inf ";
        }
        cout << endl;
    }
    else{
        cout << "Negative Cycle detected. No Solution Exists.\n";
    }
    
}