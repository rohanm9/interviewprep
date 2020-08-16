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
    adjList.clear();
    visited.clear();
    ddistance.clear();
    adjList.resize(n + 1);
    visited.resize(n + 1,false);
    ddistance.resize(n + 1,INF);
    set<pair<ll,ll>>s;
    For(i,0,m){
        ll a,b,w;
        cin>>a>>b>>w;
        adjList[a].pb(mp(b,w));
        adjList[b].pb(mp(a,w));
    }
    ll src;
    cin>>src;
    ddistance[src]=0;
    s.insert({ddistance[src],src});
    while(s.size()!=0){
        auto it = s.begin();
        ll v = (*it).ss;
        s.erase(it);
        if(visited[v]) continue;
        visited[v] = true;
        for(auto &u : adjList[v]){
            ll w = u.ss;
            if(ddistance[v] + w < ddistance[u.ff]){
                auto x = s.find({ddistance[u.ff],u.ff});
                if(x!=s.end()) s.erase(x);
                ddistance[u.ff] = ddistance[v] + w;
                s.insert({ddistance[u.ff],u.ff});
            }   
        }
    }
    FoR(i,1,n){
        cout<<i<<" "<<ddistance[i]<<"\n";
    }
}
// to compute path we can use predecessor map
// complexity : O((V+E)logV) 
// O(V) for initialisation
// O(VlogV) for constructing edge set
// O(ElogV) for key update(removing and inserting again that is the only way to do that when using a set in cpp)
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
//sample input
// 9 14
// 1 2 4
// 1 8 8
// 2 3 8
// 2 8 11 
// 3 4 7
// 3 9 2
// 3 6 4
// 4 5 9
// 4 6 14
// 5 6 10
// 6 7 2
// 7 8 1
// 7 9 6
// 8 9 7 
// 1