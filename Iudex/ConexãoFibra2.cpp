#include <bits/stdc++.h>

using namespace std;

class Graph{
private:    
    unordered_map<string, list<pair<string, int>>> adjList; // <vertex<pair< adj vertex, weight>>
    unordered_map<string, int> visited;

public: 
    Graph(){}

    void setEdge(string u, string v, int w){
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    void setVisited(string v){
        visited[v] = 1;
    }

    int getVisited(string v){
        return visited[v];
    }

    void Prim(string start, unordered_map<string, int>& MST, unordered_map<string, string>& parent){
        
        for (const auto& node : adjList) {
            MST[node.first] = INT_MAX;
            visited[node.first] = false;
        }
        
        
        priority_queue<pair<int, pair<string, string>>,vector<pair<int,pair<string,string>>>, greater<pair<int, pair<string, string>>>> pq;  //<pair<weight,pair< vertex, prev_vertex>>>

        MST[start] = 0;
        pq.emplace(0, make_pair(start, start));

        for(int i = 0; i < adjList.size(); i++){
            string p, v;

            do{
                if(pq.empty()) return;

                v = pq.top().second.first;
                p = pq.top().second.second;
                pq.pop();

            }while(visited[v] == 1);

            setVisited(v);
            parent[v] = p;

            for(auto& edge: adjList[v]){
                string u = edge.first;
                int weight = edge.second;
                
                if(visited[u] == 0 && MST[u] > weight){
                    MST[u] = weight;
                    pq.emplace(weight, make_pair(u, v));
                }

            }
        }



    }


};





int main(){
    string input;
    int dist;

    Graph g; 
    while (getline(cin, input)) {
        // Remove espaços em branco
        input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

        stringstream ss(input);
        string centro1, centro2, distStr;
        int dist;

        getline(ss, centro1, ',');
        getline(ss, centro2, ',');
        getline(ss, distStr);
        dist = stoi(distStr);

        g.setEdge(centro1, centro2, dist);
    }
    
    unordered_map<string, int> MST;
    unordered_map<string, string> parent;
    
    string start = "STI";
    g.Prim(start, MST, parent);
    

    int sumDist = 0;
    for (const auto& dist : MST) {
        if (dist.second != INT_MAX) {
            sumDist += dist.second;
        }
    }

    cout << sumDist << endl;

    //print path do STI ao centro mais próximo
    stack<string> path;
    string target = "CIn";
    while (target!= start) {
        path.push(target);
        target = parent[target];
    }
    path.push(start);

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }


    return 0;
};
