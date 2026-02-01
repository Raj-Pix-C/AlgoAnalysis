#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n, s, a, b;
    cin >> n >> s;

    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<bool>visited(n, false);
    stack<int>st;
    
    while(cin >> a >> b){
        g[a][b] = 1;
    }
    
    st.push(s);
    visited[s] = true;

    while(!st.empty()){
        int tmp = st.top();
        cout << tmp << " ";
        st.pop();

        for(int i = 0; i < n; i ++){
            if(g[tmp][i] && !visited[i]){
                st.push(i);
                visited[i] = true;
            }
        }
    }
}