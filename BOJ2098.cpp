#include <iostream>
#include <cstring>
#define MAX 987654321
using namespace std;

int n;

int graph[16][16];
int dp[16][65536];
int ans_cost = MAX;


int solve(int cur, int way){
    way |= (1<<cur);
    
    if(way == (1<<n)-1){
        if(graph[cur][0] != 0){
            return graph[cur][0];
        }
        return MAX;
    }
    
    int &ret = dp[cur][way];
    if(ret != 0) return ret;
    
    ret = MAX;
    for(int i = 0; i<n; i++){
        if((way & (1<<i)) == 0 && graph[cur][i] != 0){
            int temp = solve(i, way + (1<<i)) + graph[cur][i];
            
            ret = min(ret, temp);
            
        }
    }
    return ret;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, 0, sizeof(dp));
    
    cin >> n;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> graph[i][j];
        }
        
    }
    
    cout << solve(0,0) << endl;
    
    
    
    
    
    
    return 0;
}
