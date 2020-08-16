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
const ll mod = 1e9 + 7;
vector<vector<ll>>adjList;
vector<bool>visited;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n + 4];
    For(i,2,n + 2) cin>>a[i];
    // taking n+2 will help in implementation 
    ll dp[n + 4] = {0};
    // dp[i] represents that we are visiting that 
    // n + 2 this loop and 
    For(i,k + 2,n + 2){
        dp[i] = max(dp[i - 1], dp[i - 2]) + a[i];
    }
    // n + 2 + 2, for this loop
    // we are visiting again from n-2 to 0 not gonna revisit n-1 we did it in first time  
    rFor(i,n,2){
        if(i >= k + 1)
            dp[i] = max(max(dp[i + 1],dp[i + 2]) + a[i], dp[i]);
        else
            dp[i] = max(dp[i + 1],dp[i + 2]) + a[i];
    }
    print(dp[2]);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}