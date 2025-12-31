#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, start, finish; cin >> n;
    vector<pair<int, int>> times;

    for(int i = 0; i < n; i++){
        cin >> start >> finish;
        times.push_back({finish, start});
    }
    sort(times.begin(), times.end());

    // for(auto& x:times)cout << x.first << " " << x.second << endl;

    int count = 1;
    int j = 0;

    for(int i = 1; i < n; i++){
        if(times[i].second > times[j].first){
            count++;
            j = i;
        }
    }
    
    cout << count << endl;

    return 0;
}
