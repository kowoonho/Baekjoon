#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector <vector <int> > v(1001);
int indegree[1001];

void topologysort(){
    queue <int> q;
    vector <int> ans;
    for(int i = 1; i<=n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    for(int i = 0; i<n; i++){
        
        if(q.empty()){
            cout << 0 << endl;
            exit(0);
        }

        
        int x = q.front();
        q.pop();
        ans.push_back(x);
                
        for(int j = 0; j<v[x].size(); j++){
            int y = v[x][j];
            
            if(--indegree[y] == 0){
                q.push(y);
            }
        }
    }
    
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }
    return;
}

int main(){
    cin >> n >> m;
    while(m--){
        int t;
        cin >> t;
        vector <int> temp;
        for(int i = 0; i<t; i++){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        
        for(int i = 0; i<t-1; i++){
            int before = temp[i];
            int after = temp[i+1];
            indegree[after]++;
            
            v[before].push_back(after);
        }
    }
    
    topologysort();

    return 0;
}
