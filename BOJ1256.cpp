#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n, m;
int k;
int dp[201][201];
string ans;

int dp_word(int x, int y){
    if(x == 0 || y == 0) return 1;

    int &ret = dp[x][y];
    if(ret != -1) return ret;

    ret = min(dp_word(x-1, y)+dp_word(x, y-1), 1000000000+1);
    return ret;
}

void getWord(int step, int x, int y){
    if(x==0){
        for(int i = 0; i<y; i++){
            ans+='z';
        }
        return;
    }
    else if(y==0){
        for(int i = 0; i<x; i++){
            ans+='a';
        }
        return;
    }
    int idx = dp_word(x-1, y);
    if(step > idx){
        ans+='z';
        getWord(step-idx,x,y-1);
    }
    else{
        ans+='a';
        getWord(step,x-1,y);
    }
    return;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> k;
    dp_word(101,101);
    if(k > dp[n][m]){
        cout << -1 << endl;
        return 0;
    }
    getWord(k,n,m);

    cout << ans << endl;
    return 0;
}
