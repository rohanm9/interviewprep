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

int main(){
	fastio;
    ll n,x;
    cin>>n>>x;
    ll array[n]_;
    For(i,0,n){
        cin>>array[i];
    }
    sort(array,array+n);
    ll k=0;
    for(ll b=n/2;b>=1;b/=2){
        // suppose the value of array[k+b] is greater then target value than we will not add b to k 
        //we are decreasing the steps with each each iteration of for loop
        while(k+b<n and array[k+b]<=x) k+=b;
    }
    if(array[k]==x){
        print("target value found");
    }
    else{
        print("target value not found");
    }
}