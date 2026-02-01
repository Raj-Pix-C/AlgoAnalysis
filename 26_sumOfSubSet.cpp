#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool sizeCmp(const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
}

class SubSetSum{
private:
    vector<int> arr, tmp;
    vector<vector<int>> res;
    int N;
    int target;

public:
    SubSetSum(int n, int t): N(n), target(t) {
        arr.resize(N);
    }

    void input(){
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
    }

    bool findSum(int i, int rem){
        bool found = false;  

        if(rem == 0){
            if(find(res.begin(), res.end(), tmp) == res.end())
                res.push_back(tmp);
            found = true;
        }
        if(i >= N) return found;
      
        tmp.push_back(arr[i]);
        found |= findSum(i+1, rem-arr[i]);
        tmp.pop_back();
        found |= findSum(i+1, rem);

        return found;
    }

    void print(){
        sort(res.begin(), res.end(), sizeCmp);
        for(auto& y: res){
            for(auto x: y){
                cout << x << " ";
            }
            cout << endl;
        }
    }

};


int main(){
    int n, t;
    cin >> n >> t;

    SubSetSum sss(n, t);
    sss.input();
    if(sss.findSum(0, t)){
        sss.print();
    }
    else{ cout << "impossible\n"; }
}