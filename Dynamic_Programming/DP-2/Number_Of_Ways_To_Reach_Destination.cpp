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
void solve(){
    ll n,m;
    cin>>n>>m;
    ll dp[n][m];
    For(i,0,n+1){
        dp[i][0] = 1;
    }
    For(j,0,m+1){
        dp[0][j] = 1;
    }
    For(i,1,n) For(j,1,m){
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    // (m+n-2)!(m-1)!(n-1)! can also be used ...
    print(dp[n-1][m-1]);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}