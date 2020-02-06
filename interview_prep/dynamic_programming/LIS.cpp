#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define print(a) cout<<a<<"\n"
int main(){
    fastio;
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n){
        cin>>a[i];
    }
    ll dp[n];
    For(i,0,n){
        dp[i]=1;
    }
    ll maxi;
    For(i,0,n){
        maxi=0;
        rFor(j,i-1,0){
            if(a[i]>a[j])
                maxi=max(maxi,dp[j]);
        }
        dp[i]=maxi+1;
    }
    ll ans=LLONG_MIN;
    For(i,0,n){
        cout<<dp[i]<<" ";
        ans=max(ans,dp[i]);
    }
    print("");
    print(ans);
}