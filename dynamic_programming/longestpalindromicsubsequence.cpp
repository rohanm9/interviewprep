#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define print(a) cout<<a<<"\n"
int main(){
    fastio;
    string str;
    cin>>str;
    ll n=str.length();
    ll L[n][n];
    For(i,0,n) L[i][i]=1;
    For(cl,1,n){
        For(i,0,n-(cl)){
            ll j=i+cl; 
            if(str[i]==str[j]&&cl==1){
                L[i][j]=2;
            }
            else if(str[i]==str[j]){
                L[i][j]=L[i+1][j-1]+2;
            }
            else{
                L[i][j] = max(L[i][j-1],L[i+1][j]);
            }
        }
    }
    print(L[0][n-1]);
}