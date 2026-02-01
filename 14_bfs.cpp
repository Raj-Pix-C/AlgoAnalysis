#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, s, d;
    cin >> n >> s >> d;

    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<int> par(n, -1);    
    vector<bool> visited(n, false);
    queue<int> q;
    
    int a, b;

    while(cin >> a >> b){
        g[a][b] = 1;
    }

    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        for(int i = 0; i < n; i++){
            if(g[tmp][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
                par[i] = tmp;
            }
        }
    }

    cout << "All Reachable Nodes From " << s << ": ";
    for(int i = 0; i < n; i++){
        if(visited[i])
        cout << i << " ";
    }
    
    if(par[d] != -1){
        cout << endl << "Shortest Path From " << s << " to " << d << ": " << d;
        do{
            cout << " < " << par[d];
            d = par[d];
        }while(d != s);
        cout << endl;
    }

}