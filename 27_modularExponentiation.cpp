#include<bits/stdc++.h>
using namespace std;

int modExp(int a, int n, int m){
    if(n == 0) return 1;

    int x = modExp(a, n/2, m);

    return (n%2==0? (x*x)%m:(x*x*a)%m);
}

int main(){
    int a, n, m;
    cin >> a >> n >> m;

    cout << modExp(a, n, m) << endl;
}