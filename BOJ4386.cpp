#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct star{
    double x, y;
};

struct constellation{
    int a, b;
    double cost;
};

double distance(star a, star b){
    return sqrt((a.x - b.x)*(a.x- b.x) + (a.y - b.y)*(a.y-b.y));
}

int get_parent(int parent[], int x){
    if(parent[x] == x) return x;
    
    return parent[x] = get_parent(parent, parent[x]);
}

void union_parent(int parent[], int x, int y){
    x = get_parent(parent, x);
    y = get_parent(parent, y);
    
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

bool find_parent(int parent[], int x, int y){
    x = get_parent(parent, x);
    y = get_parent(parent, y);
    
    if(x == y) return true;
    else return false;
}

bool compare(constellation a, constellation b){
    if(a.cost < b.cost) return true;
    else return false;
}

vector <star> v;
vector <constellation> vc;

int main(){
    int n;
    cin >> n;
    v.resize(n);
    int node[n];
    for(int i = 0; i<n; i++){
        node[i] = i;
        
        cin >> v[i].x >> v[i].y;
    }
    
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            vc.push_back({i,j,distance(v[i], v[j])});
        }
    }
    sort(vc.begin(), vc.end(), compare);
    double d = 0;
    
    for(int i = 0; i<vc.size(); i++){
        int start = vc[i].a;
        int end = vc[i].b;
        
        if(!find_parent(node, start, end)){
            union_parent(node, start, end);
            d += vc[i].cost;
        }
    }
    
    cout << d << endl;
    
    
    
    
    
    return 0;
}
