#include <bits/stdc++.h>
using namespace std;

char a[101][101];
int visited[101][101], n, m, max_dis, dis, ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(int y, int x){
    visited[y][x] = 1;
    ret = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(!q.empty()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!visited[ny][nx] && a[ny][nx] == 'L'){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
                ret = visited[ny][nx];
            }
        }
    }
    return ret;
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    max_dis = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'W') continue;
            dis = dfs(i, j);
            if(dis > max_dis) max_dis = dis;
            memset(visited, 0, sizeof(visited));
        }
    }

    cout << max_dis - 1;

}