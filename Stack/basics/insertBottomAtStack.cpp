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
void insertAtBottom(stack<ll> &st,ll &x){
    if(st.empty()){
        st.push(x);
    }
    else{
        ll t=st.top(); st.pop();
        insertAtBottom(st,x);
        st.push(t);
    }
}
void solve(){
    ll n;
    cin>>n;
    stack<ll>st;
    For(i,0,n){
        ll temp;
        cin>>temp;
        st.push(temp);
    }
    ll x;
    cin>>x;
    insertAtBottom(st,x);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    print("");
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;
