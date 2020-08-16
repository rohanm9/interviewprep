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
// void solve(){
//     string str1,str2;
//     cin>>str1;
//     cin>>str2;
//     ll n = str1.length(), m = str2.length();
//     ll dp[n + 1][m + 1];
//     For(i,0,n + 1){
//         dp[i][0] = 0;
//     }
//     For(j,0,m + 1){
//         dp[0][j] = 0;
//     }
//     For(i,1,n + 1) For(j,1,m + 1){
//         if(str1[i - 1] == str2[j - 1]){
//             dp[i][j] = dp[i - 1][j - 1] + 1;
//         }
//         else{
//             //dp[i - 1][j - 1] is anyway gonna be cover in that + we are not taking anything twice
//             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
//     print(dp[n][m]);
// }
// we are trying to improve timecomplexity here
void solve(){
    string str1,str2;
    cin>>str1;
    cin>>str2;
    ll n = str1.length(), m = str2.length();
    ll dp[2][m+1];
    For(j,0,m + 1){
        dp[0][j] = 0;
    }
    dp[1][0] = 0;
    For(i,1,n + 1){
        For(j,1,m + 1){
            if(str1[i - 1] == str2[j - 1]){
                dp[1][j] = dp[0][j] + 1;
            }
            else{
                dp[1][j] = max(dp[0][j], dp[1][j - 1]);
            }
        }
        For(j,1,m + 1){
            dp[0][j] = dp[1][j];
        }
    }
    print(dp[1][m]);
}

int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}