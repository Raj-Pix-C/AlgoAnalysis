#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int freq;
    char alp;
    node * left;
    node * right;

    node(){
        this->freq = 0;
        this->alp = '\0';
        this->left = nullptr;
        this->right = nullptr;
    }

//    node(int f){
//        this->freq = f;
//        this->alp = '\0';
//        this->left = nullptr;
//        this->right = nullptr;
//    }
    
    node(int f, char ch){
        this->freq = f;
        this->alp = ch;
        this->left = nullptr;
        this->right = nullptr;
    }
};

auto comp = [](node* a, node* b){
    return a->freq > b->freq; 
};

void preOrderTraverse(node * root, vector<pair<char,string>>& codes, string s){
    if(root == nullptr) return;
    if(root->left == nullptr and root->right == nullptr){
        codes.push_back({root->alp,s});
        return;
    }
    preOrderTraverse(root->left, codes, s+'0');
    preOrderTraverse(root->right, codes, s+'1');
}

void huffman(vector<int>& freqArr, vector<pair<char,string>>& codes){
    int n = 0;

    priority_queue<node*, vector<node*>, decltype(comp)> minHeap(comp);

    for(int i = 0; i < 26; i++){
        if(freqArr[i] > 0){
            n++;
            node * nd = new node(freqArr[i], (char)(i+'a'));
            minHeap.push(nd);
        }
    }


    if(n > 1){
        for(int i = 1; i < n; i++){
            node * x = minHeap.top();
            minHeap.pop();
            node * y = minHeap.top();
            minHeap.pop();

            node * z = new node();
            z->left = x;
            z->right = y;
            z->freq = x->freq + y->freq;

            minHeap.push(z);
        }
    }     

    node * root = minHeap.top();

    preOrderTraverse(root, codes, "");

}

string modBS(char x, vector<pair<char,string>>& codes){
    int l = 0;
    int r = codes.size()-1;
    int mid;
    string code;

    while(l <= r){
        mid = (l+r)/2;
        if(x < codes[mid].first) r = mid-1;
        else if(x > codes[mid].first) l = mid+1;
        else {code = codes[mid].second; break;}
    }
    return code;
}


int main(){
    string text = "writeaprogramthatconstructsahuffmancodeforagivenenglishetextandencodesit";

//    string text = "aabbcdefg";
    string encoded = "";
    vector<int> freqArr(26, 0);
    vector<pair<char,string>> codes;
    for(int i = 0; i < text.size(); ++i){
    freqArr[text[i]-'a']++;
    }

    huffman(freqArr, codes);
    sort(codes.begin(), codes.end());

    for(auto& x : codes){
        cout << x.first << " " << x.second << endl;
    }

    for(auto& x: text){
        encoded += modBS(x, codes);
    }

    cout << encoded << endl;

    return 0;
}
