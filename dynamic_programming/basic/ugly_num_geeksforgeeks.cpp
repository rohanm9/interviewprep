#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define pb push_back
#define print(a) cout<<a<<"\n";
const ll mod=1e9+7;
// the bruteforce soln
// void solve(){
//     ll n;
//     cin>>n;
//     ll count=1,i=1;
//     while(count<n){
//         bool flag=false;
//         ll ii=i;
//         while(ii%2==0){
//             ii=ii/2;
//         }
//         while(ii%3==0){
//             ii=ii/3;
//         }
//         while(ii%5==0){
//             ii=ii/5;
//         }
//         if(ii==1){
//             count++;
//         }
//         i++;
//     }
//     print(i);
// }

void solve(){
    ll n;
    cin>>n;
    ll dp[n];
    dp[0]=1;
    ll i2=0,i3=0,i5=0;
    For(i,1,n){
       dp[i]=min(2LL*dp[i2],min(3LL*dp[i3],5LL*dp[i5]));
       if(2LL*dp[i2]==dp[i]){
           i2++;
       }
       if(3LL*dp[i3]==dp[i]){
           i3++;
       }
       if(5LL*dp[i5]==dp[i]){
           i5++;
       }
    }
    print(dp[n-1]);
}
int main(){
    fastio;
    solve();
}