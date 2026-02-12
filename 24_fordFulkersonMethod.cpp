//maximum flow problem using edmonds-carp (bfs)

#include<bits/stdc++.h>
using namespace std;

const int inf = 1e8;

int bfs(int s, int t, vector<vector<int>>& capacity, vector<vector<int>>& adj, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pair<int, int>> q;
    q.push({s, inf});

    while (!q.empty()){
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(auto& next:adj[cur]){
            if(parent[next] == -1 && capacity[cur][next] > 0){
                parent[next] = cur;

                int newFlow = min(capacity[cur][next], flow);

                if(next == t){
                    return newFlow;
                }

                q.push({next, newFlow});
            }
        }
    }
    
    return 0;
}

int maxFlow(int n, int s, int t, vector<vector<int>>& adj, vector<vector<int>>& capacity){
    int flow = 0;
    vector<int> parent(n);

    int newFlow;
    while((newFlow = bfs(s, t, capacity, adj, parent))){
        flow += newFlow;

        int cur = t;
        while(cur != s){
            int prev = parent[cur];
            capacity[prev][cur] -= newFlow;
            capacity[cur][prev] += newFlow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
    int n; cin >> n;
    int s = 0, t = n-1;

    vector<vector<int>> capacity(n, vector<int>(n, 0)), adj(n), original, flow;

    int u, v, c;
    while(cin >> u >> v >> c){
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += c;
    }

    original = capacity;

    cout << "Maximum flow: " << maxFlow(n, s, t, adj, capacity) << endl;


    // // for storing original capacity, residual capacity and flow matrices // //

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         if(original[i][j] > 0){
    //             flow[i][j] = original[i][j] - capacity[i][j];
    //         }
    //     }
    // }
}