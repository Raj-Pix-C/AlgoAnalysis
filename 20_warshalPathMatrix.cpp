#include<bits/stdc++.h>
#define INF 1e7
using namespace std;

int main(){
    int n, a, b, c;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) g[i][i] = 0;

    while(cin >> a >> b >> c){
        g[a][b] = c;
    }


    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][k] != INF && g[k][j] != INF){
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] != INF)
                cout << (bool)g[i][j] << " ";
            else 
                cout << 0 << " ";
        }
        cout << endl;
    }
}