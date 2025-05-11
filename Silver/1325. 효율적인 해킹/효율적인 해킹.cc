#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, num, result, x;
vector<int> t[100004];
vector<int> r;
int visited[100004];


void dfs(int a){
    visited[a] = 1;
    for(int i : t[a]){
        if(visited[i]) continue;
        dfs(i);
        num++;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    result = 0;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        t[b].push_back(a);
    }
    

    for(int i = 1; i <= n; i++){
        num = 1;
        memset(visited, 0, sizeof(visited));
        dfs(i);
        if(result < num){
            r.clear();
            r.push_back(i);
            result = num;
        }
        else if(result == num) r.push_back(i);

    }

    for(int i = 0; i < r.size(); i++){
        cout << r[i] << ' ';
    }
    
}