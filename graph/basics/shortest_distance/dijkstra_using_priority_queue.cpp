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
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define print(a) cout<<a<<"\n"
const ll mod=1e9+7;
vector<vector<pair<ll,ll>>>adjList;
vector<bool>visited;
vector<ll>ddistance;
void solve(){
    ll n,m;
    cin>>n>>m;
    adjList.resize(n + 1);
    // processed
    visited.resize(n + 1,false);
    ddistance.resize(n + 1,INF);
    priority_queue<pair<ll,ll>>pq;
    For(i,0,m){
        ll a,b,w;
        cin>>a>>b>>w;
        adjList[a].pb(mp(b,w));
        adjList[b].pb(mp(a,w));
    }
    ll src;
    cin>>src;
    ddistance[src]=0;
    // since the implementation of proirity is max heap implementation we will use negative fo the distance
    pq.push({-ddistance[src],src});
    while(!pq.empty()){
        // its different from normal queue i meant there is front in queue and top in priority queue
        ll v = pq.top().ss; pq.pop();
        if(visited[v]) continue;
        // if it enters one time in the frontier than it will never should again
        visited[v] = true;
        for(auto &u : adjList[v]){
            ll w = u.ss;
            if(ddistance[v] + w < ddistance[u.ff]){
                ddistance[u.ff] = ddistance[v] + w;
                pq.push({-ddistance[u.ff],u.ff});
            }
        }
    }
    FoR(i,1,n){
        cout<<i<<" "<<ddistance[i]<<"\n";
    }
}
//to compute path we can use predecessor map
//complexity : O(V+ElogE) referred from pdf...for explaination see set implementation for dijkstra
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}