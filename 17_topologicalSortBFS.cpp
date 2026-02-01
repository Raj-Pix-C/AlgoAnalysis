#include<bits/stdc++.h>
using namespace std;

// kahn's algorithm

vector<int> bfsTopo(int n, vector<vector<int>>& g, vector<int>& inDeg, queue<int>& q){
    vector<int> res;

    for(auto& x: inDeg){
        if(!x){
            q.push(x);
        }
    }

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        res.push_back(tmp);

        for(int i = 0; i < n; i++){
            inDeg[i]--;
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
    }
    return res;
}

int main(){
    int n, a, b;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<int> inDeg(n, 0);
    queue<int> q;

    while(cin >> a >> b){
        g[a][b] = 1;
        inDeg[b]++;
    }

    vector<int> topoSrtd = bfsTopo(n, g, inDeg, q);

    for(auto& x:topoSrtd){
        cout << x << " ";
    }
    cout << endl;

}