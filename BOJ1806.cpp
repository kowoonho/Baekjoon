#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, s;
    cin >> n >> s;
    v.resize(n);
    int temp_sum = 0;
    for(int i = 0; i<n; i++){
        cin >> v[i];
        temp_sum += v[i];
    }
    
    if(temp_sum < s){
        cout << 0 << endl;
        return 0;
    }
    
    int l = 0;
    int r = 0;
    int sum = v[l];
    int ans_len = n;
    while(l<=r && r<n){
        if(sum < s){
            r++;
            sum += v[r];
        }
        else{
            ans_len = min(ans_len, r-l+1);
            sum -= v[l];
            l++;
        }
    }
    
    cout << ans_len << endl;
    
    return 0;
}
