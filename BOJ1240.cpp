#include <iostream>
#include <vector>
#include <algorithm>
#define inf 987654321
using namespace std;

typedef pair <int, int> pii;
int n, m;
vector < vector <pii> > v;
int answer = inf;
bool visit[1001];

void dfs(int start, int end, int ans_dist){
    if(start == end){
        answer = min(answer, ans_dist);
        return;
    }
    if(visit[start]) return;
    visit[start] = true;

    for(int i = 0; i<v[start].size(); i++){
        int nxt = v[start][i].first;
        dfs(nxt, end, ans_dist + v[start][i].second);
    }
    return;
}

int main(){
    cin >> n >> m;
    v.resize(n+1);
    for(int i = 0; i<n-1; i++){
        int a, b, dist;
        cin >> a >> b >> dist;
        v[a].push_back({b, dist});
        v[b].push_back({a, dist});
    }

    for(int i = 0; i<m; i++){
        answer = inf;
        fill(&visit[0], &visit[1001], false);
        int a, b;
        cin >> a >> b;
        dfs(a, b, 0);
        cout << answer << endl;
    }


    return 0;
}