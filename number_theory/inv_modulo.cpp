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
ll power(ll x,ll y,ll m){
    if(y==0) return 1;
    ll p=power(x,y/2,m);
    p=(p*p)%m;
    if(y%2==1){
        return (x*p)%m;
    }
    else{
        return p;
    }
}
void solve(){
    ll a=5;
    ll g=__gcd(a,m);
    if(g!=1){
        print("Inverse modulo doesn't exist");
    }
    else{
        cout<<"Inverse modulo is"<<" "<<power(a,m-2,m)<<"\n";
    }
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