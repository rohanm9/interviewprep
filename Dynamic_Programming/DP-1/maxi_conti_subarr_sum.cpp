#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define print(a) cout<<a<<"\n"
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n) cin>>a[i];
    ll sum=0,maxi=NINF;
    For(i,0,n){
        sum=sum+a[i];
        maxi=max(maxi,sum);
        if(sum<0) sum=0;
    }
    print(sum);
}
int main(){
    fastio;
    solve();
}