//rohanm9
//DA-IICT,Gandhinagar
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define FoR(i,a,b) for(ll i=a;i<=b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define print(a) cout<<a<<"\n"
const ll mod=1e9+7;
vector<vector<ll>>graph;
vector<bool>visited;
vector<vector<ll>> ddistance;
void solve(){
    // In this case we don't make adjacency list, we make adjacency matrix
    ll n,m;
    cin>>n>>m;
    graph.resize(n + 1,vector<ll>(n + 1,INT_MAX));
    FoR(i,1,n) graph[i][i] = 0;
    For(i,0,m){
        ll a,b,w;
        cin>>a>>b>>w;
        //lets take it as directed graph
        graph[a][b] = w;
    }
    ddistance=graph;
    FoR(k,1,n) FoR(i,1,n) FoR(j,1,n){
        if(ddistance[i][j] > ddistance[i][k] + ddistance[k][j]){
            ddistance[i][j] = ddistance[i][k] + ddistance[k][j];
        }
    }
    FoR(i,1,n){
        FoR(j,1,n){
            cout<<ddistance[i][j]<<" ";
        }
        print("");
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;