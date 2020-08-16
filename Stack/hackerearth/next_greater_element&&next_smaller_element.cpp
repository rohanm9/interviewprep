//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/a-game-of-numbers-1-5d3a8cb3/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define print(a) cout<<a<<'\n';
int main(){
    fastio;
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n){
        cin>>a[i];
    }
    ll next_greater[n],next_smaller[n];
    stack<ll>s1;
    rFor(i,n-1,0){
        // either stack gets empty!! OR (a[s1.top()]) we found next greater element!! -> will stop the loop 
        while(!s1.empty()&&a[s1.top()]<=a[i]){
            s1.pop();
        }
        if(!s1.empty()){
            next_greater[i]=s1.top();
        }
        else{
            next_greater[i]=-1;
        }
        // may be either it would be next greater element or elements already in stack
        s1.push(i);
    }
    stack<ll>s2;
    rFor(i,n-1,0){
        while(!s2.empty()&&a[s2.top()]>=a[i]){
            s2.pop();
        }
        if(!s2.empty()){
            next_smaller[i]=s2.top();
        }
        else{
            next_smaller[i]=-1;
        }
        s2.push(i);
    }
    For(i,0,n){
        if(next_greater[i]!=-1&&next_smaller[next_greater[i]]!=-1){
            cout<<a[next_smaller[next_greater[i]]]<<" ";
        }        
        else{
            cout<<-1<<" ";
        }
    }
    cout<<"\n";
}