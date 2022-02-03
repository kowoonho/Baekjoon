#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int limit;
char graph[9][9];
int answer = -1;
int dx[8] = {-1,0,1,0,1,-1,1,-1};
int dy[8] = {0,-1,0,1,1,-1,-1,1};

bool is_square(int x){
    int temp = (int) sqrt(x);
    if(temp * temp == x) return true;
    else return false;
}

void brute_force(int x, int y, int step_x, int step_y){
    for(int i = 0; i<8; i++){
        string temp = "";
        temp += graph[x][y];
        int temp_x = x;
        int temp_y = y;
        int temp_i = stoi(temp);
        if(is_square(temp_i)) answer = max(answer, temp_i);
        while(0<=temp_x && temp_x<n && 0<=temp_y && temp_y<m){
            temp_x+= dx[i] * step_x;
            temp_y+= dy[i] * step_y;
            if(0> temp_x || n<= temp_x || 0> temp_y || m<=temp_y) break;
            temp += graph[temp_x][temp_y];
            int temp_i = stoi(temp);
            if(is_square(temp_i)) answer = max(answer, temp_i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    limit = max(n, m);
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        for(int j = 0; j<m; j++){
            graph[i][j] = s[j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            for(int k = 1; k<9; k++){
                for(int l = 1; l<9; l++)
                    brute_force(i,j,k,l);
            }
        }
    }

    cout << answer << endl;




    return 0;
}
