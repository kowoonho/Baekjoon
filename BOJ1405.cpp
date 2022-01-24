#include <iostream>

using namespace std;

int start_x = 50;
int start_y = 50;
int n;
double probability[4];
bool visit[100][100];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

double back_tracking(int x, int y, int cnt){
    if(cnt == n){
        return 1.0;
    }
    visit[x][y] = true;
    double result = 0.0;
    
    for(int i = 0; i<4; i++){
        visit[x][y] = true;
        int nxt_x = x + dx[i];
        int nxt_y = y + dy[i];
        if(visit[nxt_x][nxt_y] == true) continue;
        result += probability[i] *  back_tracking(nxt_x, nxt_y, cnt+1);
    }
    visit[x][y] = false;
    return result;
}

int main(){
    cin >> n;
    for(int i = 0; i<4; i++){
        double x;
        cin >> x;
        probability[i] = x/100.0;
    }
    double ret = back_tracking(start_x, start_y, 0);
    cout.precision(10);
    cout << ret << endl;
    
    
    return 0;
}
