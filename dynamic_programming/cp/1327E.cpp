//rohanmaheshwari9
#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
#define print(a) cout<<a<<"\n";
const ll m=998244353;
ll ncr(ll n,ll r){
    ll x=1;
    For(i,n-r+1,n+1){
        x=x*(i);
    }
    For(i,1,r+1){
        x=x/(i);
    }
    return x;
}
bool sortinrev(pair<ll,string> &a,pair<ll,string> &b){
    if(a.first>b.first){
        return 0;
    }
    else{
        return 1;
    }
}
//F[0][0] F[0][1]
//F[1][0] F[1][1]
void multiply(ll F[2][2],ll M[2][2]){
    ll w=F[0][0]*M[0][0]+F[0][1]*M[1][0];
    ll x=F[0][0]*M[0][1]+F[0][1]*M[1][1];
    ll y=F[1][0]*M[0][0]+F[1][1]*M[1][0];
    ll z=F[1][0]*M[0][1]+F[1][1]*M[1][1];
    F[0][0]=w;
    F[0][1]=x;
    F[1][0]=y;
    F[1][1]=z;
}
void powerfuncformatrix(ll F[2][2],ll n){
    if(n==0||n==1)// stop the recursion
        return;
    powerfuncformatrix(F,n/2);
    multiply(F,F);
    if(n%2!=0){
        ll M[2][2]={{1,1},{1,0}};
        multiply(F,M);
    }
}
ll fib(ll n){
    ll F[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    powerfuncformatrix(F,n-1);
    return F[0][0];
}
// to stop g++ for using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;
ll powmod(ll x,ll y,ll m){
    if(y==0) return 1;
    if(y==1) return x;
    ll t=powmod(x,y/2,m);
    t=(t%m*t%m)%m;
    if(y%2) t=(t%m*x%m)%m;
    return t%m;
}
void solve(){
    ll n;
    cin>>n;
    ll dp[n+1];
    dp[1]=10;
    dp[2]=180;
    For(i,3,n+1){
        // dp(i)= ((10*dp[i-1]-9*pow(10,i-2))+9*10*pow(10,i-2));
        dp[i]=((10LL*dp[i-1]%m)+9LL*9LL*powmod(10LL,i-2,m)%m)%m;
    }
    rFor(i,n,1) cout<<dp[i]<<" ";
}
int main(){
    fastio;
    solve();
}