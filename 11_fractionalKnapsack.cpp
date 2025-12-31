#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>vals = /*{2,2,6,5}; {5,6,4,6,5,2}*/{60,100,120};
    vector<int>wt = /*{1,3,8,4};{6,5,6,6,3,7}*/{10,20,30};
    int n, w = 50;
    n = vals.size();
    double profit = 0.0;

    vector<pair<double, pair<int, int>>> items;
    for(int i = 0; i < n; i++){
        items.push_back({(double)vals[i]/(double)wt[i], {vals[i], wt[i]}});
    }
    sort(items.rbegin(), items.rend());

    for(auto& x:items){
        if(w <= 0)break;
        if(x.second.second > w){
            profit += w*x.first;
            w = 0;
        }else{
            profit += x.second.second*x.first;
            w -= x.second.second;
        }
    }
    cout << profit << endl;
}