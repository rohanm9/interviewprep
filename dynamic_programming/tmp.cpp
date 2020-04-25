//rohanm9
//DAIICT,Gandhinagar
#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define print(a) cout<<a<<"\n";
const ll mod=1e9+7;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    For(i,0,n) cin>>a[i];
    vector<ll>v;
    For(i,0,n/2){
        v.pb(a[i]+a[n-1-i]);
    }
    ll mini=INF;
    For(x,0,2*k+1){
    ll count=0;
        For(i,0,n/2){
            if(x!=a[i]+a[n-1-i]){
                ll x1=a[i]+x-(a[i]+a[n-1-i]);
                ll x2=a[n-1-i]+x-(a[i]+a[n-1-i]);
                if(x1>=1&&x1<=k){
                    count++;
                }
                else if(x2>=1&&x2<=k){
                    count++;
                }
                else{
                    count=count+2;
                }
            }
        }
        mini=min(mini,count);
    }
    print(mini);
}
int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--) solve();
}