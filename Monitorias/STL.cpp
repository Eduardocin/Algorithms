//vector , priority_queue, stack, queue, deque, list, set, map, multiset,

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    priority_queue<int, vector<int>, greater<int>> min_H;
    pair<int, int> p;

    //priority_queue
    min_H.push(1); min_H.push(5); min_H.push(2);

    while(!min_H.empty()){
        cout << min_H.top() << " ";
        min_H.pop();
    }

    cout << endl;

    //pair
    cout << "pair: " << endl;
    p = {1, 3};
    cout << p.first << " " << p.second << endl;

    //map
    map<string, int> m;
    m.insert({"a", 1});
    m.insert({"b", 2});
    m.insert({"c", 3});
    cout << "map: " << endl;

    auto it = m.begin();
    while(it!= m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }


    cout << m["a"] << endl;

    m["b"] = 4;
    cout << m["b"] << endl;

    //iterator
    vector<int> v = {1, 42 ,45, 4, 2,};
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << "vector" << endl;
    for(int it : v){
        cout << it << " ";
    }
    cout << endl;


    




    return 0;
}