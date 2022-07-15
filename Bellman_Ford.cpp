#include<bits/stdc++.h>
using namespace std;
int n, s, t, a[100][100], d[100], e[100];
const int maxn = 1e9;
void _input_(){
    cin>>n>>s>>t;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin>>a[i][j];
        }
    }
}
void __Bellman_Ford_(){
    for(int i = 1;i <= n;i++){
        d[i] = a[s][i];
        e[i] = s;
    }
    d[s] = 0;
    e[s] = 0;
    for(int start = 1; start <= n - 2; start++){
        int ok = 1;
        for(int i = 1;i <= n - 2;i++){
            for(int j = 1;j <= n;j++){
                if(d[i] > d[j] + a[j][i]){
                    d[i] = d[j] + a[j][i];
                    e[i] = j;
                    ok = 0;
                }
            }
        }
        if(ok == 1) break;
    }
    cout<< d[t];
    vector<int> path;
    while(1){
        path.push_back(t);
        if(t == s){
            break;
        }
        t = e[t];
    }
    reverse(begin(path), end(path));
    for(int x : path){
        cout<< x<< " ";
    }
}
int main(){
    _input_();
    __Bellman_Ford_();
    return 0;
}