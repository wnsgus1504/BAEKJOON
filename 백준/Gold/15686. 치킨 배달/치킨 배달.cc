#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> clist;
vector<pair<int, int>> home, chicken;
int a[54][54], n, m, result;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void combination(int start, vector<int> v){
    if(v.size() == m){
        clist.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++){
        v.push_back(i);
        combination(i, v);
        v.pop_back();
    }
    return;
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) home.push_back({i, j});
            if(a[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<int> v;
    combination(- 1, v);
    result = 987654321;

    for(vector<int> l : clist){
        int ret = 0;
        for(pair<int, int> h : home){
            int minimum = 987654321;
            for(int c : l){
                int dis = abs(h.first - chicken[c].first) + abs(h.second - chicken[c].second);
                minimum = min(minimum, dis);
            }
            ret += minimum;
        }
        result = min(result, ret);
    }

    cout << result;

}