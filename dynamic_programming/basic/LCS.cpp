#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define print(a) cout<<a<<"\n"
#define n A.size()
#define m B.size
void solve(){
    string A;
    string B;
    cin>>A>>B;
    ll dp[n+1][m+1];
    For(i,0,n+1) dp[i][0]=0;
    For(j,0,m+1) dp[0][j]=0;

}
int main(){
    fastio;
    solve();
}