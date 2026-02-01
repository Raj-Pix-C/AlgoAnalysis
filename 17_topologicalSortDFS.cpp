#include<bits/stdc++.h>
using namespace std;

void DfsTopo(int node, vector<vector<int>>& g, vector<bool>& visited, stack<int>& st){
    visited[node] = true;
    for(int i = 0; i < visited.size(); i++){
        if(g[node][i] && !visited[i]){
            DfsTopo(i, g, visited, st);
        }
    }
    st.push(node);
}


int main(){
    int n, a, b;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    stack<int> st;

    while(cin >> a >> b){
        g[a][b] = 1;
    }
    
    for( int i = n-1; i >= 0; i--/*int i = 0; i < n; i++*/){
        if(!visited[i]){
            DfsTopo(i, g, visited, st);
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}