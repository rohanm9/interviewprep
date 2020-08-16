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
    ll dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    FoR(i,2,n){
        dp[i] = dp[i-1] + dp[i-2];
    }
    print(dp[n]);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}