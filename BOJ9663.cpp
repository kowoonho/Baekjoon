#include <iostream>

using namespace std;

int n;
bool visit[15];
int ans_cnt = 0;
int board[15];

bool check_board(int cnt){ //그 위치에 두어도 되는지 판단
    for(int i = 0; i<cnt; i++){
        if(board[i] == board[cnt] || cnt-i == abs(board[cnt] - board[i])){
            return false;
        }
    }
    return true;
}

void dfs(int cnt){
    if(cnt==n){
        ans_cnt++;
        return;
    }
    
    for(int i = 0; i<n; i++){
        board[cnt] = i;
        
        if(check_board(cnt)){ // 그 위치에 두어도 된다면 다음 열에서 다시 실행
            dfs(cnt+1);
        }
    }
    
    
}


int main(){
    cin >> n;
    dfs(0);
    
    cout << ans_cnt << endl;
    
    return 0;
}
