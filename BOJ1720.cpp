#include <iostream>
#include <cstring>
using namespace std;

long long dp[31];
long long overlap_dp[31];
long long sol_dp(int x){
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(x == 2) return 3;
    if(x == 3) return 5;
    long long &ret = dp[x];
    if(ret != -1) return ret;
    
    return ret = sol_dp(x-1) + 2 * sol_dp(x-2);
}

long long sol_overlap_dp(int x){
    if(x==0) return 0;
    if(x==1) return 1;
    if(x==2) return 3;
    if(x==3) return 1;
    if(x==4) return 5;
    long long &ret = overlap_dp[x];
    if(ret != -1) return ret;
    
    return ret = sol_overlap_dp(x-2) + 2 * sol_overlap_dp(x-4);
}


int main(){
    
    memset(dp, -1, sizeof(dp));
    memset(overlap_dp, -1, sizeof(overlap_dp));
    
    int n;
    cin >> n;
    long long a = sol_dp(n);
    long long b = sol_overlap_dp(n);
    
    long long answer = (a - b)/2 + b;

    cout << answer << endl;
    
    return 0;
}
