#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair <char, ll> pcl;

vector <pcl> num_store(10);
vector <string> v;
bool first_alp[10];
bool is_alp[10];
bool flag = false;


void init_num_store(){
    for(int i = 0; i<10; i++){
        char alphabet = 'A' + i;
        num_store[i] = {alphabet, 0};
    }
    return;
}

bool compare(pcl a, pcl b){
    if(a.second > b.second) return true;
    else return false;
}

ll ten(int x){
    ll ret = 1;
    while(x--){
        ret *= 10;
    }
    return ret;
}

int cnt_is_alp(){
    int ret = 0;
    for(int i = 0; i<10; i++){
        if(is_alp[i]) ret++;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init_num_store();
    
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
        
        int first_num = v[i][0] - 'A';
        first_alp[first_num] = true;
        
        for(int j = 0; j<v[i].size(); j++){
            int idx = v[i][v[i].size() - j - 1] - 'A';
            is_alp[idx] = true;
            num_store[idx].second += ten(j);
        }
    }
    if(cnt_is_alp() >= 10) flag = true;
    sort(num_store.begin(), num_store.end(), compare);
    
    if(flag){
        char non_first_alp;
        int index_non_zero = 0;
        for(int i = 9; i>=0; i--){
            int idx = num_store[i].first - 'A';
            if(!first_alp[idx]){
                non_first_alp = idx + 'A';
                index_non_zero = i;
                break;
            }
        }
        pcl temp = num_store[index_non_zero];
        num_store.erase(num_store.begin() + index_non_zero);
        num_store.push_back(temp);
    }
    
    ll sum = 0;
    for(int i = 0; i<10; i++){
        sum += (9-i) * num_store[i].second;
    }
    cout << sum << endl;
    
    
    
    
    
    
    
    
    
    return 0;
}
