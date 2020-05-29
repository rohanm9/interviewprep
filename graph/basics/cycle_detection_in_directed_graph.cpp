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
vector<vector<ll>>adjList;
vector<bool>visited;
// to check whether there is backedge or not we are going to make use of recStack; 
vector<bool>recStack;
bool isCycleUtil(ll v){
    if(!visited[v]){
        visited[v]=true;
        recStack[v]=true;
        for(auto &u:adjList[v]){
            // because all path possible to v will be explored at once 
            if(!visited[u]){
                if(isCycleUtil(u)){
                    return true;
                }
            }
            else if(recStack[u]){
                return true;
            }
        }
    }
    recStack[v]=false;
    return false;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    adjList.resize(n+1);
    visited.resize(n+1,false);
    recStack.resize(n+1,false);
    For(i,0,m){
        ll a,b;
        cin>>a>>b;
        // since it a directed graph;
        adjList[a].pb(b);
    }
    For(i,1,n+1){
        // calling again and again because graph may be disconnected
        if(isCycleUtil(i)){
            print("YES");
            return;
        }
    }
    print("NO");
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;