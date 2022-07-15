#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge{
    int u, v;
    int w;
};
vector<edge> canh;
const int maxn = 1001;
int n, m;
int parent[maxn], sz[maxn];
void make_set(){
    for(int i = 1;i < n;i++){
        parent[i] = i; sz[i] = 1;
    }   
}
int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false; //Khong the gop a, b vao voi nhau
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}
void _input_(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x, y , w;
        cin >> x >> y >> w;
        edge e;
        e.u = x, e.v = y, e.w = w;
        canh.push_back(e);
    }
}
bool cmp(edge a, edge b){
    return a.w < b.w;
}
void _Kruskal_(){
    //Tao cay khung
    vector<edge> mst;
    //Sort danh sach canh theo chieu dai tang dan 
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for(int i = 0;i < m;i++){
        if(mst.size() == n - 1) break;
        edge e = canh[i]; //chon e la canh nho nhat
        if(Union(e.u, e.v)){
            mst.push_back(e);
            d += e.w;
        }
    }
    //Tra ve ket qua 
    if(mst.size() != n - 1){
        cout << "Do thi khong lien thong" << endl;

    }
    else {
        cout << "MST: " << d << endl;
        for(auto it : mst){
            cout << it.u <<" " << it.v << " " << it.w << endl;
        }
    }
}
int main(){
    _input_();
    make_set();
    _Kruskal_();
    return 0;
}