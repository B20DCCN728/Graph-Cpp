#include<bits/stdc++.h>
using namespace std;
struct canh{
    int x, y, w;
};
const int maxn = 10001;
vector<pair<int, int>> adj[maxn];
bool used[maxn];
int n, m, d;
void _input_(){
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        int x, y, w; cin>>x>>y>>w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
}
void _Prim_(int u){
    d = 0;
    used[u] = true;
    vector<canh> MST;
    while(MST.size() < n - 1){  
        int min_w = INT_MAX;
        int X, Y;
        for(int i = 1;i <= n;i++){
            if(used[i]){
                for(pair<int, int> it : adj[i]){
                    int j = it.first, trongso = it.second;
                    if(!used[j] && trongso < min_w){
                        min_w = trongso;
                        X = j; Y = i;
                    }
                }
            }
        }
        MST.push_back({X, Y, min_w});
        d += min_w;
        used[X] = true;
    }
    cout << d << endl;
    for(canh it : MST){
        cout << it.x << " " << it.y << " "<< it.w << endl;
    }
}



int main(){
    _input_();
    _Prim_(1);
    return 0;
}