#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define print(a) cout<<a<<"\n"
int main(){
    fastio;
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n){
        cin>>a[i];
    }
    ll dp[n];
    For(i,0,n){
        dp[i]=1;
    }
    ll maxi;
    For(i,0,n){
        maxi=0;
        rFor(j,i-1,0){
            if(a[i]>a[j])
                maxi=max(maxi,dp[j]);
        }
        dp[i]=maxi+1;
    }
    ll ans=LLONG_MIN;
    For(i,0,n){
        cout<<dp[i]<<" ";
        ans=max(ans,dp[i]);
    }
    print("");
    print(ans);
}


// alternate way is to use binary search
// ll ceil_index(ll low,ll high,ll temp[],ll key){
//     ll mid,ans=high;
//     while(low<=high){
//         mid=low+(high-low)/2;
//         if(temp[mid]>=key) ans=mid,high=mid-1;
//         else low=mid+1;
//     }
//     return ans;
// }
// ll delta(ll a[],ll temp[],ll n){
//     ll len=1;
//     temp[0]=a[0];
//     For(i,1,n){
//         if(a[i]<temp[0]) temp[0]=a[i];
//         else if(a[i]>temp[len-1]) temp[len]=a[i],len++;
//         else temp[ceil_index(0,len-1,temp,a[i])]=a[i];
//     }
//     return len;
// }