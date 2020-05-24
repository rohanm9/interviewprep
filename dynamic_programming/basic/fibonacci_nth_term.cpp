//rohanm9
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
const ll mod=998244353;
//F[0][0] F[0][1]
//F[1][0] F[1][1]

//f(n+1) f(n)
//f(n) f(n-1)
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
void matrixpow(ll F[2][2],ll n){
    if(n==1||n==0) return;
    matrixpow(F,n/2);
    multiply(F,F);
    if(n%2!=0){
        ll M[2][2]={{1,1},{1,0}};
        multiply(F,M);
    }
}
void solve(){
    ll n;
    cin>>n;
    ll F[2][2]={{1,1},{1,0}};
    matrixpow(F,n-1);
    print(F[0][0]);
}
int main(){
    fastio;
    solve();
}