#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<pair<pair<int,string>,pair<string,int>>> lmao;
    deque<pair<pair<int,string>,pair<string,int>>> restaurants;
    lmao.push_back({{0,"kfc"},{"food",4}});
    cout << lmao[0].first.first << ' ' << lmao[0].first.second << " " << lmao[0].second.first << " " << lmao[0].second.second << endl;
}

/* #include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;
    
    void init(long v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight){
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    void dfs(vector<long> &result, long start){
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
                visited[temp] = true;
            }

            for(auto vertex:adjList[temp]){
                if (!visited[vertex.first])
                    st.push(vertex.first);
            }
        }
    }

    void bfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!q.empty()){
            long temp = q.front();
            q.pop();

            for(auto vertex:adjList[temp]){
                if (!visited[vertex.first]){
                    q.push(vertex.first);
                    visited[vertex.first] = true;
                    result.push_back(vertex.first);
                }
            }
        }
    }
};

int main(){
    
    deque<pair<pair<int,string>,pair<string,int>>> restaurants;
    //first is name, second.first is type, second.second is price
    int n;
    cin >> n;
    graph g;
    g.init(n+1);
    for(int i = 0; i < n; i++){
        string input, type;
        int value;
        cin >> input >> type >> value;
        restaurants.push_back({{i, input},{type, value}});
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        string source, destination;
        cin >> source >> destination;
        int src, dest;
        for(int j = 0; j < n; j++){
            if(restaurants[j].first.second == source){
                src = restaurants[j].first.first;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(restaurants[j].first.second == destination){
                dest = restaurants[j].first.first;
                break;
            }
        }
        g.add_edge(src, dest);
    }




    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 20);
    g.add_edge(0, 3, 30);
    g.add_edge(1, 3, 40);
    g.add_edge(1, 4, 50);

    vector<long> dfs_result, bfs_result;
    g.dfs(dfs_result, 0);

    for(auto it:dfs_result){
        cout << it << " ";
    }
    cout << endl;

    g.bfs(bfs_result, 0);

    for(auto it:bfs_result){
        cout << it << " ";
    }
    cout << endl;

    return 0;
} */