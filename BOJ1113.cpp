#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair <int, int> pii;

int n, m;
int arr[52][52];
int ans = 0;
int max_num = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool is_inside(int x, int y){
    return x>=0 && x<=n+1 && y>=0 && y<=m+1;
}

void bfs(int h){
    arr[0][0] = h;
    queue <pii> q;
    q.push({0,0});

    while(!q.empty()){
        pii cur = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            pii nxt = {cur.first + dx[i], cur.second + dy[i]};
            if(is_inside(nxt.first, nxt.second) && (arr[nxt.first][nxt.second] < h)){
                arr[nxt.first][nxt.second] = h;
                q.push(nxt);
            }

        }
    }

}

int main(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        string s;
        cin >> s;
        for(int j = 1; j<=m; j++){
            arr[i][j] = s[j-1] - '0';
            max_num = max(max_num, arr[i][j]);
        }
    }

    for(int k = 1; k<=max_num; k++){
        bfs(k);

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(arr[i][j] < k){
                    arr[i][j]++;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;




    return 0;
}