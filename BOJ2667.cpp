#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int graph[25][25];
vector <int> town;
bool visit[25][25];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt = 0;
bool is_inside(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n);
}

void dfs(int x, int y){
    if(visit[x][y]) return;
    if(!is_inside(x,y)) return;
    if(graph[x][y] == 0) return;
    
    visit[x][y] = true;
    cnt++;
    for(int i = 0; i<4; i++){
        int nxt_x = x + dx[i];
        int nxt_y = y + dy[i];
        
        dfs(nxt_x, nxt_y);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    
    for(int i = 0; i<n; i++){
        string x;
        cin >> x;
        for(int j = 0; j<n; j++){
            graph[i][j] = x[j] - '0';
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(visit[i][j] == true || graph[i][j] == 0) continue;
            dfs(i, j);
            town.push_back(cnt);
            cnt = 0;
        }
    }
    cout << town.size() << endl;
    sort(town.begin(), town.end());
    for(auto i : town){
        cout << i << '\n';
    }
    
    return 0;
}
