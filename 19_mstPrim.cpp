#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, u, v, w;
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);

    while (cin >> u >> v >> w){
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    key[0] = 0;
    pq.push({0, 0}); // {key[start], start}

    while (!pq.empty()){
        u = pq.top().second;

        pq.pop();

        if(inMST[u]) continue;

        inMST[u] = true;

        for(auto& e:graph[u]){
            v = e.first;
            w = e.second;

            if(!inMST[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    int cost = 0;
    for(int i = 1; i < n; i++){
        cout << parent[i] << " " << i << " : " << key[i] << endl;
        cost += key[i];
    }

    cout << cost << endl;

}