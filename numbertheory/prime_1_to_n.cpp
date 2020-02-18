//rohanmaheshwari9
// modulo multiplicative inverse only exist if gcd(a,m)=1
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
const ll m=1e9+7;
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
    ll n;
    cin>>n;
    ll a[n+1];
    For(i,0,n){
        a[i]=1;
    }
    a[0]=0;
    a[1]=0;
    For(i,2,sqrt(n)+1){
        if(a[i]){
            for(ll p=2;p*p<=n;p++){
                a[i*p]=0;
            }
        }
    }
    For(i,0,n){
        if(a[i]){
            cout<<i<<" ";
        }
    }
    print("");
}
int main(){
	fastio;
    solve();
}
// to use __int128_t take input as string then convert it
// __int128_t strtonum(string str){
//     __int128_t sum=0;
//     for(int i=0;i<str.length();i++){
//         sum=sum*10+(str[i]-48);
//     }
//     return sum;
// }
// string toString(__int128_t num){
//     string str;
//     int temp;
//     while(num!=0){
//         temp=num%10;
//         str=to_string(temp)+str;
//         num=num/10;
//     }
//     return str;
// }
// ostream& operator<<(std::ostream& os, __int128_t num) {
//     return os<<toString(num);
// }