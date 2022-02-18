#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int graph[20][20];
bool visit[26];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int max_cnt = 0;

bool is_inside(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}


void dfs(int x, int y, int cnt){
    int cur_idx = graph[x][y];
    visit[cur_idx] = true;
    
    max_cnt = max(cnt, max_cnt);
    
    for(int i = 0; i<4; i++){
        int nxt_x = x + dx[i];
        int nxt_y = y + dy[i];
        
        if(is_inside(nxt_x, nxt_y) && (!visit[graph[nxt_x][nxt_y]])){
            visit[graph[nxt_x][nxt_y]] = true;
            dfs(nxt_x, nxt_y, cnt+1);
            visit[graph[nxt_x][nxt_y]] = false;
        }
    }
}

int main(){
    
    cin >> n >> m;
    string x;
    
    for(int i = 0; i<n; i++){
        cin >> x;
        for(int j = 0; j<m; j++){
            graph[i][j] = x[j]-'A';
        }
    }
    
    memset(visit, false, sizeof(visit));
    
    dfs(0,0,1);
    cout << max_cnt << endl;
    
    
    
    return 0;
}
