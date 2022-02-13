#include <iostream>
#include <map>
#include <vector>
using namespace std;

map <int, int> mp;
int arr[41];
int n, s;
long long cnt = 0;
int mid;
void solveright(int idx, int sum){
    if(idx == n){
        mp[sum]++;
        return;
    }
    
    solveright(idx+1, sum+arr[idx]);
    solveright(idx+1, sum);
}

void solveleft(int idx, int sum){
    if(idx == mid){
        cnt += mp[s-sum];
        return;
    }
    
    solveleft(idx+1, sum+arr[idx]);
    solveleft(idx+1, sum);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> s;
    
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    mid = n/2;
    solveright(mid, 0);
    solveleft(0, 0);
    if(s == 0) cnt--;
    cout << cnt << endl;
    
    
    return 0;
}
