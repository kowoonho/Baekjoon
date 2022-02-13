#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair <int, int> pii;

int n, m;
bool visit[50][50];
int graph[50][50];
int dx[8] = {0,1,0,-1,1,-1,-1,1};
int dy[8] = {1,0,-1,0,1,-1,1,-1};

bool is_inside(int x, int y){
    if(x>=0 && x<m && y>=0 && y<n && graph[x][y] == 1) return true;
    else return false;
}

void bfs(int x, int y){
    queue <pii> q;
    if(visit[x][y]) return;
    q.push({x,y});
    visit[x][y] = true;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        
        for(int i = 0; i<8; i++){
            int nxt_x = cur.first + dx[i];
            int nxt_y = cur.second + dy[i];
            
            pii nxt = {nxt_x, nxt_y};
            
            if(visit[nxt_x][nxt_y]) continue;
            if(!is_inside(nxt_x, nxt_y)) continue;
            
            visit[nxt_x][nxt_y] = true;
            q.push(nxt);
        }
    }
}

int main(){
    while(1){
        memset(visit, false, sizeof(visit));
        
        
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cin >> graph[i][j];
            }
        }
        int cnt = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(visit[i][j] || graph[i][j] == 0) continue;
                
                bfs(i,j);
                cnt++;
            }
        }
        cout << cnt << endl;
        
    }
    
    
    return 0;
}
