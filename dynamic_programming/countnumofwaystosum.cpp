#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define print(a) cout<<a<<"\n";
// sample test case
// 3 2 
// 1 2
// ans : 3
// explaination: 1 1 1
// 2 1 
// 1 2
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(k);
    For(i,0,k){
        cin>>a[i];
    }
    ll dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(auto &x:a){
            if(i-x>=0){
                dp[i]=dp[i]+dp[i-x];
            }
        }
    }
    print(dp[n]);
}
int main(){
    fastio;
    solve();
}