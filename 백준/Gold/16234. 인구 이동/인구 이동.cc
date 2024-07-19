#include <bits/stdc++.h>
using namespace std;

int a[54][54], visited[54][54], n, l, r, p, k, area, num, day;
vector<int> result;
vector<pair<int, int>> v;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
    num += a[y][x];
    area++;
    visited[y][x] = 1;
    v.push_back({y, x});
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] == 1) continue;
        if(abs(a[y][x] - a[ny][nx]) <= r && abs(a[y][x] - a[ny][nx]) >= l){
            dfs(ny, nx);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    k = 1;

    while(k == 1){
        k = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                area = 0;
                num = 0;
                v.clear();
                if(!visited[i][j]){
                    dfs(i, j);
                    if(area > 1) k = 1;
                    p = num / area;
                    if(v.size() == 1) continue;
                        for(pair<int, int> b : v){
                            a[b.first][b.second] = p;
                        }
                }
            }
        }
        day++;
    }
    
    cout << day - 1;
    
}