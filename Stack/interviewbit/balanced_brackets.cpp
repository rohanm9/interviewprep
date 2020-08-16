//rohanmaheshwari9
#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
#define print(a) cout<<a<<"\n";
ll ncr(ll n,ll r){
    ll x=1;
    For(i,n-r+1,n+1){
        x=x*(i);
    }
    For(i,1,r+1){
        x=x/(i);
    }
    return x;
}
bool sortinrev(pair<ll,string> &a,pair<ll,string> &b){
    if(a.first>b.first){
        return 0;
    }
    else{
        return 1;
    }
}
// to stop g++ for using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;

void solve(){
    string str;
    cin>>str;
    stack<char>s;
    s.push(str[0]);
    For(i,1,str.length()){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            s.push(str[i]);
        }
        else{
            if(!s.empty()){
                if(str[i]==')'&& s.top()=='('){
                    s.pop();
                }
                else if(str[i]=='}'&& s.top()=='{'){
                    s.pop();
                }
                else if(str[i]==']'&& s.top()=='['){
                    s.pop();
                }
                else{
                    break;
                }
            }
            else{
                s.push(str[i]);
                break;
            }
        }
    }
    if(!s.empty()){
        print("NO");
    }
    else{
        print("YES");
    }
}
int main(){
    fastio;
	ll t;
    cin>>t;
    while(t--) solve();
