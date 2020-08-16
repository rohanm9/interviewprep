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
vector<vector<char>>a;
vector<vector<bool>>visited;
struct point{
    ll x,y,level;
};
ll d[2]={-1,1};
//--->y
//|
//|
//v
//x
void solve(){
    ll n,m;
    cin>>n>>m;
    a.resize(n,vector<char>(m));
    visited.resize(n,vector<bool>(m,false));
    queue<point>q;
    For(i,0,n) For(j,0,m){
        cin>>a[i][j];
        if(a[i][j]=='s'){
            q.push({i,j,0});
        }
    }
    while(!q.empty()){
        point p=q.front();
        q.pop();
        if(a[p.x][p.y]=='d'){
            print(p.level);
            // or break;
            return;
        }
        For(i,0,2){
            if(0<=p.x+d[i] && p.x+d[i]<n){
                if(!visited[p.x+d[i]][p.y] && a[p.x+d[i]][p.y]!='o'){
                    q.push({p.x+d[i],p.y,p.level+1});
                    visited[p.x+d[i]][p.y]=true;
                }
            }
        }
        For(i,0,2){
            if(0<=p.y+d[i] && p.y+d[i]<m){
                if(!visited[p.x][p.y+d[i]] && a[p.x][p.y+d[i]]!='o'){
                    q.push({p.x,p.y+d[i],p.level+1});
                    visited[p.x][p.y+d[i]]=true;
                }
            }
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