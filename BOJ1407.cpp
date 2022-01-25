#include <iostream>
#include <map>
#define ll long long

using namespace std;

ll sum(ll x){
    if(x==0) return 0;
    if(x==1) return 1;

    if(x%2 == 1) return x/2 + 2*sum(x/2) + 1;
    else return x/2 + 2*sum(x/2);
}


int main() {
    ll a, b;
    cin >> a >> b;
    cout << sum(b) - sum(a-1);
}
