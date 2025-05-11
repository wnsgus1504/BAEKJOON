    #include <bits/stdc++.h>
    using namespace std;
    
    int a[101][101], visited[101][101], n, x, y, remain, t, m, r;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    vector<pair<int, int>> v;

    void bfs(int y, int x){
        visited[y][x] = 1;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == 1) continue;
            if(a[ny][nx] == 1){
                remain++;
                a[ny][nx] = 0;
                visited[ny][nx] = 1;
            }
            if(a[ny][nx] == 0 && !visited[ny][nx]) bfs(ny, nx);
        }
        return;
    }

    int main() {
    
        cin >> n >> m;

    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }

        while(true){
            remain = 0;
            bfs(0, 0);
            t++;
            memset(visited, 0, sizeof(visited));
            if(remain == 0) break;
            r = remain;
        }

        cout << t - 1 << '\n' << r;
        
    }