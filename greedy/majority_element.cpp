#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define print(a) cout<<a<<"\n"
#define input(a) cin>>a
int main(){
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n){
        input(a[i]);
    }
    //implementing it my moore's voting machine
    ll majority_element=0;
    ll count=1;
    For(i,1,n){
        if(a[i]==a[majority_element]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            majority_element=i;
            count=1;
        }
    }
    //occurence greater than n/2
    print(a[majority_element]);
}