#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int good_cnt = 0;

int main(){
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i<n; i++){
        int small_p = 0;
        int big_p = n-1;
        
        while(small_p < big_p){
            if(small_p == i || big_p == i){
                if(small_p == i){
                    small_p++;
                    continue;
                }
                else{
                    big_p--;
                    continue;
                }
            }
            if(v[small_p] + v[big_p] < v[i]) small_p++;
            else if(v[small_p] + v[big_p] > v[i]) big_p--;
            else{
                good_cnt++;
                break;
            }
        }
    }
    
    cout << good_cnt << endl;
    
    return 0;
}
