//its maximum cut problem not number of ways to cut 
#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define print(a) cout<<a<<"\n";
void solve(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    ll a[k];
    For(i,0,k){
        cin>>a[i];
    }
    ll dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=NINF;
        For(j,0,k){
            if(i-a[j]>=0&&dp[i]<dp[i-a[j]]+1){
                dp[i]=dp[i-a[j]]+1;
            }
        }
    }
    print(dp[n]);
}
int main(){
    fastio;
    solve();
}
