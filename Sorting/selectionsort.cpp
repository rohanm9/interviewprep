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
    ll a[n];
    For(i,0,n) cin>>a[i]; 
    For(i,0,n-1){
        ll min_index = i;
        For(j,i+1,n){
            if(a[min_index] > a[j]){
                min_index = j;
            }
        }
        swap(a[min_index],a[i]);
    }
    For(i,0,n) cout<<a[i]<<" ";
    print("");
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;
