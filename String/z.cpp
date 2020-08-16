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
    string str;
    cin>>str
    ll n = str.length();
    ll L , R , k;
    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    ll Z[n] = {0};
    For(i,1,n){
        if(i > R){
            // for the starting
            L = R = i;
            while(R < n and str[R - L] == str[R])
                R++;
            // length of prefix matched
            Z[i] = R - L;
            R--;
        }
        else{
            // k represents which index does the i matched when the window was calculated
            k = i - L;
            // if z[k] represents amount of prefix matched and z[]
            if(Z[k] + i <= R)
                Z[i] = Z[k];
            else{
                // changing window to L = i ----> until index matches prefix
                L = i;
                while(R < n and str[R - L] == str[R])
                    R++;
                // length of new prefix matched
                Z[i] = R - L;
                R--;
            }
        }
    }
    For(i,0,n){
        cout<<Z[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;
