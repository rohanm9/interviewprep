//rohanm9
#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define ll int
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
#define print(a) cout<<a<<"\n";
const ll m=998244353;
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n),b(n);
    For(i,0,n) cin>>a[i];
    For(i,0,n) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<ll>());
    For(i,0,k){
        if(a[i]<b[i])
        swap(a[i],b[i]);
    }
    ll sum=0;
    For(i,0,n) sum=sum+a[i];
    print(sum);
}
int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--)
        solve();
}