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
vector<vector<ll>>a;
vector<vector<bool>visited;
struct point{
    ll i,j,level;
};
ll d[2]={-1,1};
void solve(){
    ll n,m;
    cin>>n>>m;
    a.resize(n,vector<ll>(m));
    visited.resize(n,vector<bool>(m,false));
    ll ans[n][m];
    queue<point>q;
    For(i,0,n) For(j,0,m){
        cin>>a[i][j];
        if(a[i][j]==1){
            q.push({i,j,0});
        }
    }
    while(!q.empty()){
        point p=q.front();
        q.pop();
        ans[p.i][p.j]=p.level;
        For(x,0,2){
            if(0<=p.i+d[x] && p.i+d[x]<n){
                if(!visited[p.i+d[x]][p.j]){
                    q.push({p.i+d[x],p.j,p.level+1});
                }
            }
        }
        For(x,0,2){
            if(0<=p.j+d[x] && p.j+d[x]<m){
                if(!visited[p.i][p.j+d[x]]){
                    q.push({p.i,p.j+d[x],p.level+1});
                }
            }
        }
    }
    For(i,0,n) For(j,0,m) cout<<ans[i][j]<<" ";
    print("");

}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;