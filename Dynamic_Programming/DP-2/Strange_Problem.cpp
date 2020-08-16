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
    ll n,k;
    cin>>n>>k;
    ll a[n],dp[n];
    For(i,0,n) cin>>a[i];
    For(i,0,k) dp[i] = a[i];
    if(k == 1){
        ll mx = 0;
        // window ki size ek hi hain
        For(i,0,n) mx = max(mx , a[i]);
        print(mx);
        return 0; 
    }
    // j ko window ki size se intialise kr rhe hain  
    ll j = k;
    while(j < n){
        ll first_large = 0 , first_index = 0 , second_large = 0 , second_index = 0;
        For(i,j - k,j){
            if(dp[i] > first_large){
                second_large = first_large;
                second_index = first_index;
                first_large = dp[i];
                first_index = i;
            }
            else if(dp[i] > second_large){
                second_large = dp[i];
                second_index = i;
            }
        }
        For(i,j,min(n,j+k)){
            if(i - j != first_index){
                dp[i] = a[i] + first_large;
            }
            else{
                dp[i] = a[i] + second_large;
            }
        }
        j += k;
    } 
    ll mx = 0;
    For(i,0,n) mx = max(mx,dp[i]);
    print(mx);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    ll t; cin>>t;
    while(t--) solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;