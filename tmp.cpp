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
bool cmp(pair<ll,ll> &a,pair<ll,ll> &b){
    if(a.ff < b.ff){
        return 1;
    }
    else if(a.ff == b.ff){
        if(a.ss > b.ss){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}
void solve(){
    ll n = 4;
    pair<ll,ll> p[n]={{6,8},{1,9},{2,4},{4,7}};
    vector<pair<ll,ll>> v;
    For(i,0,n){
        v.pb({p[i].ff,1});
        v.pb({p[i].ss,-1});
    }
    sort(v.begin(),v.end(),cmp);
    ll count = 0;
    bool flag = true;
    For(i,0,2*n){
        count += v[i].ss;
        if(count == 1 && flag == true){
            cout<<v[i].ff<<" ";
            flag = false;
        }
        if(count == 0){
            cout<<v[i].ff<<"\n";
            flag = true;
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;