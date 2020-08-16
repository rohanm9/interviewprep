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
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n) cin>>a[i];
    ll dp[n];
    // bases
    dp[0] = a[0];
    dp[1] = max(a[1],a[0]);
    For(i,2,n) dp[i] = max(a[i] + dp[i - 2],dp[i - 1]);
    print(dp[n - 1]);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}