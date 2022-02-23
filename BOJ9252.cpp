#include <iostream>
#include <cstring>
using namespace std;

int dp[1002][1002];
string s1, s2;

void printlcs(int a, int b){
    if(dp[a][b] == 0) return;
    if(s1[a-1] == s2[b-1]){
        printlcs(a-1, b-1);
        cout << s1[a-1];
    }
    else{
        if(dp[a-1][b] > dp[a][b-1]){
            printlcs(a-1,b);
        }
        else{
            printlcs(a,b-1);
        }
    }
    return;
}

int main(){
    
    cin >> s1 >> s2;
    
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i<=s1.size(); i++){
        for(int j = 1; j<=s2.size(); j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    printlcs(s1.size(), s2.size());
    cout << endl;
    
    return 0;
    
}
