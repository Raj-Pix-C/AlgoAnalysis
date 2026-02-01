#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s, a, b;
    cin >> n >> s;

    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    stack<int> stk;

    while(cin >> a >> b){
        g[a][b] = g[b][a] = 1;
    }

    stk.push(s);
    visited[s] = true;

    while(!stk.empty()){
        int tmp = stk.top();
        stk.pop();

        for(int i = 0; i < n; i++){
            if(!visited[i] && g[tmp][i]){
                stk.push(i);
                visited[i] = true;
            }
        }
    }

    for(bool x: visited){
        if(!x){
            cout << "Disconnected Graph\n";
            return 0;
        }
    }
    cout << "Connected Graph\n";
}
