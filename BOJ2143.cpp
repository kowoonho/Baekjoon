#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll t;
int a_n, b_n;
vector <ll> a, b;
vector <ll> pfsum_a, pfsum_b;
ll ans_cnt = 0;

void input(){
    cin >> t;
    cin >> a_n;
    a.resize(a_n+1);
    for(int i = 1; i<=a_n; i++){
        cin >> a[i];
    }
    cin >> b_n;
    b.resize(b_n+1);
    for(int i = 1; i<=b_n; i++){
        cin >> b[i];
    }
}

void prefix_sum(){
    for(int i = 1; i<=a_n; i++){
        ll sum = a[i];
        pfsum_a.push_back(sum);
        
        for(int j = i+1; j<=a_n; j++){
            sum += a[j];
            pfsum_a.push_back(sum);
        }
    }
    
    for(int i = 1; i<=b_n; i++){
        ll sum = b[i];
        pfsum_b.push_back(sum);
        
        for(int j = i+1; j<=b_n; j++){
            sum += b[j];
            pfsum_b.push_back(sum);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    prefix_sum();
    
    sort(pfsum_a.begin(), pfsum_a.end());
    sort(pfsum_b.begin(), pfsum_b.end());
    
    for(int i = 0; i<pfsum_a.size(); i++){
        ll low = lower_bound(pfsum_b.begin(), pfsum_b.end(), t-pfsum_a[i]) - pfsum_b.begin();
        ll high = upper_bound(pfsum_b.begin(), pfsum_b.end(), t-pfsum_a[i]) - pfsum_b.begin();
        
        ans_cnt += high - low;
    }
    
    cout << ans_cnt << endl;
    return 0;
}
