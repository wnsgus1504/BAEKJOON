    #include <bits/stdc++.h>
    using namespace std;
    
    int a[9][9], arr[9][9], visited[9][9], n, x, y, area, area_max, m;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    vector<pair<int, int>> v;
    
    void virus(int y, int x){
        visited[y][x] = 1;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(a[ny][nx] == 0){
                a[ny][nx] = 2;
                virus(ny, nx);
            }
        }
        return;
    }
    
    int main() {
    
        cin >> n >> m;
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 0) v.push_back({i,j});
            }
        }

        
        copy(&arr[0][0], &arr[0][0] + 81, &a[0][0]);
    
        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                for(int k = j + 1; k < v.size(); k++){
                    a[v[i].first][v[i].second] = 1;
                    a[v[j].first][v[j].second] = 1;
                    a[v[k].first][v[k].second] = 1;
                    for(int p = 0; p < n; p++){
                        for(int q = 0; q < m; q++){
                            if(a[p][q] == 2 && !visited[p][q]) virus(p, q);
                        }
                    }
                    for(int p = 0; p < n; p++){
                        for(int q = 0; q < m; q++){
                            if(a[p][q] == 0) area++;
                        }
                    }
                    if(area_max < area) area_max = area;
                    area = 0;
                    copy(&arr[0][0], &arr[0][0] + 81, &a[0][0]);
                    memset(visited, 0, sizeof(visited));
                }
            }
        }

        cout << area_max;
        
    }