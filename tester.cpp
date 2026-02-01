#include<bits/stdc++.h>
#include<string.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        for(auto word: wordDict){
            auto temp = s.find(word);
            while(temp != string::npos){
                s.erase(temp, word.size());
                temp = s.find(word);
            }
        }
        return s == "";
    }
};

int main(){
    Solution sol;
    vector<string> wordDict;
    
    cout << sol.wordBreak("leetcode", wordDict) << endl;
}