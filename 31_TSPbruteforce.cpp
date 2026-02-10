#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>>& dist, int n, vector<int>& bestPath){
    vector<int> cities;

    for (int i = 1; i < n; i++){
        cities.push_back(i);
    }

    int minCost = INT_MAX;

    while(true){
        int currCost = 0;
        int k = 0;

        for(int city: cities){
            currCost += dist[k][city];
            k = city;
        }

        currCost += dist[k][0];

        if(currCost < minCost){
            minCost = currCost;
            bestPath = cities;
        }

        if(!next_permutation(cities.begin(), cities.end())) 
            break;
    }
    
    return minCost;
}


int main(){
    int n = 4;
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    vector<int> bestPath;

    cout << "Minimum travelling cost: " << tsp(dist, n, bestPath) 
    << "\nBest Path: 0 -> ";

    for(int& city: bestPath){
        cout << city << " -> ";
    }
    cout << " 0\n";
}