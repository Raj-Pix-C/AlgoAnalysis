#include <iostream>
#include <cstring>
#define MX 10
using namespace std;


int main(){

string s1, s2, s3;
cin >> s1 >> s2;

int m = s1.size();
int n = s2.size();

int dp[m+1][n+1];
memset(dp, 0, sizeof(dp));

for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
            s3.push_back(s1[i-1]);
        } else {
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
}
cout << dp[m][n] << endl << s3 <<endl;

for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
        cout << dp[i][j];
    }cout << endl;
}


}
