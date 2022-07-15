//Shortest path (tim duong di ngan nhat giua hai dinh trong do thi)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 100001;
int n, m, s, t;
// Creat vector matrix
int a[maxn][maxn];
// Creat vector 
vector<pair<int, int>> adj[maxn];
// nhap danh sach ke
void _nhap_(){
    cin>>n>>m>>s;
    for(int i = 0;i < m;i++){
        int x, y, w; cin>>x>>y>>w>>t;
        adj[x].push_back({y, w});
        //adj[y].push_back({x, w});
    }
}
const int INF = 1e9;
int pre[maxn];

// nhap ma tran trong so

void _nhap_(){
    cin>>m;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= m;j++) cin>>a[i][j];
    }
}
//option for edge list (danh sách cạnh)
void _dijkstra_(int s, int t){
    //
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    //vector<bool> visited(n + 1, false);
    // priority_queue 
    pre[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;  // smallest
    // {khoang cach, dinh}
    Q.push({0, s});
    while(!Q.empty()){
        pair<int , int> top = Q.top(); // canh va dinh 
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if(kc > d[u]) continue;
        // relaxation
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});   
                pre[v] = u; // truoc v la u;
            }
        }
    }
    // shortest path
    cout << d[t] <<endl;
    vector<int> path;
    while(1){
        path.push_back(t);
        if(t == s) break;
        t = pre[t];
    }
    reverse(begin(path), end(path));
    for(int x : path) 
    for(int i = 1;i <= n;i++){
        cout << d[i] <<" ";
    }
}

//option for adjacency matrix (ma trận kề)__-
void _dijkstra_(int s, int t){
    //
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    //vector<bool> visited(n + 1, false);
    // priority_queue 
    pre[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;  // smallest
    // {khoang cach, dinh}
    Q.push({0, s});
    while(!Q.empty()){
        pair<int , int> top = Q.top(); // canh va dinh 
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if(kc > d[u]) continue;
        // relaxation
        for(int i = 1;i <= m;i++){
            if(a[u][i] < )
            int v = i;
            int w = a[u][i];
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});   
                pre[v] = u; // truoc v la u;
            }
        }
    }
    // shortest path
    cout << d[t] <<endl;
    vector<int> path; 
    while(1){
        path.push_back(t);
        if(t == s) break;
        t = pre[t];
    }
    reverse(begin(path), end(path));
    for(int x : path) 
    for(int i = 1;i <= n;i++){
        cout << d[i] <<" ";
    }
}
//version basic
void __Dijkstra2_(int s, int t){   
    int d[m + 1], p[maxn], vs[m + 1];
    for(int i = 1;i <= m;i++){
        d[i] = a[s][t];  
        p[i] = s;
        vs[i] = 0;
    }
    int u;
    d[s] = 0;
    vs[s] = 1;
    while(!vs[i]){
        int min = 2000;
        for(int i = 1;i <= m;i++){
            //heck dinh xet chua
            if(!vs[i] && d[i] < min){
                min = d[i];
                u = i;
            }
        }
        cout<< u <<" ";
        vs[u] = 1;
        if(!vs[t]){
            for(int i = 1;i <= n;i++)
            {
                if(!vs[i] && d[i] > d[u] + a[u][i]){
                    d[i] = d[u] + a[u][i];
                    p[i] = u;
                }
            }
        }
    }
}
//
int main(){
    _nhap_();
    _dijkstra_(s, t);
    return 0;
}

