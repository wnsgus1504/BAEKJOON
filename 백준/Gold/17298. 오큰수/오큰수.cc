#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000004], result[1000004];
stack<int> s;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    memset(result, -1, sizeof(result));

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        while(s.size() && arr[s.top()] < arr[i]){
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; i++){
        cout << result[i] << ' ';
    }

}