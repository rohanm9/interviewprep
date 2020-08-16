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
    ll a[n];
    For(i,0,n){
        cin>>a[i];
    }
    deque<ll> dq;
    // initialisation
    For(i,0,k){
        while(!dq.empty() and a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    For(i,k,n){
        cout<<a[dq.front()]<<" ";
        while(!dq.empty() and dq.front()<=i-k){
            //pop them
            dq.pop_front();
        }
        while(!dq.empty() and a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<a[dq.front()]<<"\n";
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;