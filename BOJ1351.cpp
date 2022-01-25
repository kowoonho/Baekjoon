#include <iostream>
#include <algorithm>
#include <map>
#define ll long long


using namespace std;

ll n, p, q;
map <ll, ll> dp;


ll solution(ll number){
    if(number == 0) return dp[number] = 1;
    ll &ret = dp[number];
    if(ret) return ret;
    return ret = solution(number/p) + solution(number/q);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> q;
    dp[0] = 1;
    cout << solution(n) << endl;
    return 0;
}
