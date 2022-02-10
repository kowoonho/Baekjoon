#include <iostream>
#include <vector>
using namespace std;

bool check[2000001];
int n;
vector <int> v;
void sum(int idx, int ans){
    if(idx == n){
        check[ans] = true;
        return;
    }
    
    sum(idx+1, ans+v[idx]);
    sum(idx+1, ans);
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sum(0,0);
    int k = 1;
    while(1){
        if(check[k] != true){
            cout << k << endl;
            return 0;
        }
        k++;
    }
    
    
    return 0;
}
