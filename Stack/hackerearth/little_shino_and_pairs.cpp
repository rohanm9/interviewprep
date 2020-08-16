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
const ll m=1e9+7;
// to stop g++ for using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n){
        cin>>a[i];
    }
    stack<ll>s;
    ll ans=0;
    rFor(i,n-1,0){
        // either stack is empty or a[s.top()] (which is next greater element) is greater than a[i] 
        while(!s.empty()&&a[s.top()]<=a[i]){
            s.pop();
            ans++;
        }
        if(!s.empty()){
            ans++;
        }
        s.push(i);
    }
    print(ans);
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