#include <bits/stdc++.h>

using namespace std;

void Dijkstra(vector<vector<pair<int, int>>> graph, int source, vector<int>& dist, vector<int>& parent)  {
    for(int i = 0; i < graph.size(); i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    for(int i = 0; i < graph.size(); i++) {
        while()

}



int main(){

    return 0;
}