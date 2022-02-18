#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n, m;
vector <int> indegree;
vector <int> v;
vector < vector <int> > graph(32001);

void topoloysort(){
    priority_queue <int, vector <int>, greater<int> > pq;
    
    for(int i = 1; i<=n; i++){
        if(indegree[i] == 0) pq.push(i);
    }
    
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        cout << x << " ";
        for(int j = 0; j<graph[x].size(); j++){
            int y = graph[x][j];
            
            if(--indegree[y] == 0){
                pq.push(y);
            }
        }

    }
    
    cout << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    indegree.resize(n+1);
    
    int x, y;
    while(m--){
        cin >> x >> y;
        graph[x].push_back(y);
        indegree[y]++;
    }
    
    topoloysort();
    
    
    
    return 0;
}
