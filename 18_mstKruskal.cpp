#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
    vector<int>parent, rank;

    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int i){
        return parent[i] == i ? i : (parent[i] = find(parent[i]));
    }

    void unite(int u, int v){
        int s1 = find(u), s2 = find(v);

        if(s1 != s2){
            if(rank[s1] < rank[s2])
                parent[s1] = s2;
            else if(rank[s1] > rank[s2])
                parent[s2] = s1;
            else
                parent[s2] = s1;
            rank[s1]++;
        }
    }
};

// bool compare(vector<int>&a, vector<int>&b){
//     return a[2] < b[2];
// }

int kruskal(int n, vector<pair<int, pair<int, int>>>& edges, vector<pair<int, pair<int, int>>>& mst){
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int cost = 0, cnt = 0;

    for(auto& e:edges){
        int w = e.first, u = e.second.first, v = e.second.second;

        if(dsu.find(u) != dsu.find(v)){
            dsu.unite(u, v);
            cost += w;
            mst.push_back(e);
            if(++cnt == n-1) break;
        }
    }
    return cost;
}

int main(){
    vector<pair<int, pair<int, int>>> edges;
    vector<pair<int, pair<int, int>>> mst;

    int n, a, b, c;
    cin >> n;
    while(cin >> a >> b >> c){
        edges.push_back(make_pair(c, make_pair(a, b)));
    }
    cout << kruskal(n, edges, mst) << endl;
    for(auto& e:mst){
        cout << e.second.first << " " << e.second.second << " : " << e.first << endl;
    }
}