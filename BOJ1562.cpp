#include <iostream>

using namespace std;

int dp[101][10][1024];
const int inf = 1e9;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i<10; i++){
        int x = 1<<i;
        dp[1][i][x] = 1;
    }
    
    for(int i = 2; i<=100; i++){
        for(int j = 0; j<10; j++){
            for(int k = 0; k<1024; k++){
                if(j==0) dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j+1][k]) % inf;
                else if(j==9) dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j-1][k]) % inf;
                else dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j-1][k] + dp[i-1][j+1][k]) % inf;
            }
        }
    }
    
    long long sum = 0;
    for(int i = 0; i<10; i++){
        sum += dp[n][i][1023];
    }
    cout << sum % inf << endl;
    return 0;
} 
