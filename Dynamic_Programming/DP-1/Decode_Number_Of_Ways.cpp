//rohanm9
//DA-IICT,Gandhinagar
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define FoR(i,a,b) for(ll i=a;i<=b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define print(a) cout<<a<<"\n"
const ll mod=1e9+7;
vector<vector<ll>>adjList;
vector<bool>visited;
void solve(){
    ll n;
    cin>>n;
    string str;
    cin>>str;
    ll dp[n + 1];
    dp[n] = 1;
    dp[n - 1] = 1;
    rFor(i,n - 2,0){
        if((str[i] != '1' and str[i] !='2') and str[i+1] == '0') { print(0); return; }
        if(str[i] == '0') continue;
        string tmp; tmp.pb(str[i]); tmp.pb(str[i + 1]);
        ll num = stol(tmp);
        dp[i] = (dp[i + 1]%mod + ((num > 0 && num <= 26)? dp[i + 2] : 0)%mod)%mod;
    }
    print(dp[0]);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}