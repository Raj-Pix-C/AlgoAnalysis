#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int dp[1001];

int rc(vector<int>& prc, int len){
    if(len <= 0) return 0;
    if(dp[len] != -1) return dp[len];
    int ans = INT_MIN;

    for(int i = 1; i <= len; i++){
        ans = max(ans, prc[i-1]+rc(prc, len-i));
    }
    return dp[len] = ans;
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    memset(dp, -1, sizeof(dp));

    int n = 4;
    // cin >> n;
    vector<int> prices(n);
    // for(int i = 0; i < n; i++) {
    //     cin >> prices[i];
    // }
    prices = {1, 5, 8, 9};

    cout << rc(prices, n) << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(end-start);
    cout << "Elapsed time: " << dur.count() << endl;
}