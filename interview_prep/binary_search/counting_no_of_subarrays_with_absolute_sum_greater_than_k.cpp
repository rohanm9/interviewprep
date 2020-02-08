#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define print(a) cout<<a<<"\n"
int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n+1];
        For(i,1,n+1){
            cin>>a[i];
        }
        ll pref[n+1];
        pref[0]=0;
        For(i,1,n+1){
            pref[i]=pref[i-1]+a[i];
        }
        sort(pref,pref+n+1);
        ll ans=0;
        For(i,0,n+1){
            ll x=upper_bound(pref,pref+n+1,pref[i]+k)-pref;
            ans=ans+(n+1-x);
        }
        print(ans);
    }
}