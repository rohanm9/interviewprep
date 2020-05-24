#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define pb push_back
#define print(a) cout<<a<<"\n";
const ll mod=1e9+7;
// dp solution only
int search(ll a[],ll n){
    if(n==1) return 0;
    ll res=INF;
    for(int i=n-2;i>=0;i--){
        // a and new last index
        ll sub_res=search(a,i+1);
        if(sub_res!=INF) res=min(res,sub_res+1);
    }
    return res;
}
void solve1(){
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n) cin>>a[i];
    // print(search(a,n));
    ll dp[n];
    For(i,0,n) dp[i]=INF;
    dp[0]=0;
    // greedy soln
    // for(ll i=0;i<n;i++){
    //     if(dp[i]==INF) {print(-1); return;}
    //     for(ll j=i+1;j<n&&i+a[i]+1;j++){
    //         dp[j]=min(dp[j],dp[i]+1);
    //     }
    // }
    // print(dp[n-1]);
    // dp soln;
    ll dp[0]=0;
    for(ll i=1;i<n;i++){
        for(ll j=i-1;j>=0;j--){
            
        }
    }  
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    solve();
}