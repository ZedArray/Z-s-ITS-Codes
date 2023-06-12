#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;
    
    void init(long v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2){
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
        edgeCount++;
    }

    void dfs(deque<long> &result, long start, long end){
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!st.empty()){
            long temp = st.top();
            st.pop();

            if(!visited[temp]){
                result.push_back(temp);
                if(temp == end){
                    return;
                }
                visited[temp] = true;
            }

            for(auto vertex:adjList[temp]){
                if (!visited[vertex])
                    st.push(vertex);
            }
        }
    }

    void bfs(deque<long> &result, long start, long end){
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!q.empty()){
            long temp = q.front();
            q.pop();
            for(auto vertex:adjList[temp]){
                if (!visited[vertex]){
                    q.push(vertex);
                    visited[vertex] = true;
                    if(temp == end)return;
                    result.push_back(vertex);
                }
            }
        }
    }
};

int main(){
    deque<pair<pair<long,string>,pair<string,long>>> restaurants;
    //first.first is id, first.second is name, second.first is type, second.second is price
    long n;
    cin >> n;
    graph g;
    g.init(n+1);
    for(long i = 0; i < n; i++){
        string input, type;
        long value;
        cin >> input >> type >> value;
        restaurants.push_back({{i, input},{type, value}});
    }
    cin >> n;
    for(long i = 0; i < n; i++){
        string source, destination;
        cin >> source >> destination;
        long src, dest;
        for(long j = 0; j < n; j++){
            if(restaurants[j].first.second == source){
                src = restaurants[j].first.first;
                break;
            }
        }
        for(long j = 0; j < n; j++){
            if(restaurants[j].first.second == destination){
                dest = restaurants[j].first.first;
                break;
            }
        }
        g.add_edge(src, dest);
    }
    cin >> n;
    for(long i = 0; i < n; i++) {
        long budget, types;
        deque<pair<long,long>> targetlist;
        deque<long> paths;
        deque<string> finds;
        cin >> budget >> types;
        for(long j = 0; j < types; j++){
            string find;
            cin >> find;
            finds.push_back(find);
            // for(long k = 0; k < restaurants.size(); k++){
            //     if(find == restaurants[k].second.first && restaurants[k].second.second <= budget){
            //         targetlist.push_back({restaurants[k].first.first, restaurants[k].second.second});
            //     }
            // }
        }
        for(string it:finds){
            cout << it << endl;
        }
        for(int x = 1; x < finds.size(); x++){
            for(long j = 0; j < restaurants.size(); j++){
                for(long k = 0; k < restaurants.size(); k++){
                    if(j != k && restaurants[j].second.second + restaurants[k].second.second <= budget && finds[x-1] == restaurants[j].second.first && finds[x] == restaurants[k].second.first){
                        cout << restaurants[j].second.first << ", " << restaurants[k].second.first << endl;
                        g.dfs(paths, restaurants[j].first.first, restaurants[k].first.first);
                        for(int it:paths){
                            cout << it << " ";
                        }
                        //cout << paths.front() << ", " << paths.back();
                        cout << endl << endl;
                        paths.clear();
                    }
                }
            }
            
        }
        // for(int j = 0; j < targetlist.size(); j++){
        //     for(int k = 0; k < targetlist.size(); k++){
        //         if(j != k && targetlist[j].second + targetlist[j].first <= budget){
        //             g.dfs(paths, targetlist[j].first, targetlist[k].first);
        //         }
        //     }
        // }
        // cout << "path " << i << ": ";
        // for(int it:paths){
        //     cout << it << " ";
        // }
        // cout << endl;
    }


    // g.add_edge(0, 1);
    // g.add_edge(0, 2);
    // g.add_edge(0, 3);
    // g.add_edge(1, 3);
    // g.add_edge(1, 4);

    // vector<long> dfs_result, bfs_result;
    // g.dfs(dfs_result, 0);

    // for(auto it:dfs_result){
    //     cout << it << " ";
    // }
    // cout << endl;

    // g.bfs(bfs_result, 0);

    // for(auto it:bfs_result){
    //     cout << it << " ";
    // }
    // cout << endl;

    return 0;
}





/* 
10
kfc food 4
pizzahut food 4
sederhana food 8
gyukaku food 10
warkop drink 1
kopikenangan drink 3
starbucks drink 5
mixue dessert 2
tempogelato dessert 4
moncheri dessert 8
13
kfc sederhana
kfc mixue
mixue warkop
mixue tempogelato
mixue kopikenangan
warkop gyukaku
warkop tempogelato
sederhana pizzahut
sederhana kopikenangan
kopikenangan moncheri
tempogelato moncheri
pizzahut moncheri
moncheri starbucks
3
5 2 dessert drink
10 4 food dessert drink dessert
1 1 food
*/