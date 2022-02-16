#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

vector <pll> v;

long long cross(pll a, pll b){
    return ((a.first*b.second) - (a.second*b.first));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    long long start_x, start_y;
    cin >> start_x >> start_y;
    for(int i = 0; i<n-1; i++){
        long long x, y;
        cin >> x >> y;
        
        v.push_back({x-start_x, y-start_y});
    }
    
    
    long long area_sum = 0;
    
    for(int i = 0; i<v.size()-1; i++){
        area_sum += cross(v[i], v[i+1]);
    }
    if(area_sum < 0){
        area_sum *= -1;
    }
    if(area_sum % 2 == 0){
        cout << area_sum/2 << ".0" << endl;
    }
    else{
        cout << area_sum/2 << ".5" << endl;
    }

    
    
    
    
    
    
    
    return 0;
}
