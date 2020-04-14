// interviewbitsolution
#define ll int
#define INF INT_MAX
#define NINF INT_MIN
#define print(a) cout<<a<<"\n" 
int Solution::solve(vector<vector<int> > &A){
    ll n,m;
    n=A.size();
    m=A[0].size();
    ll dp[n+1][m+1];
    for(ll j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(A[i][j]){
                dp[i][j]=dp[i-1][j]+1;
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    //value in 2-D array is not going to be greater then n as we are counting row-wise
    ll cnt[n+1][n+1];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            cnt[i][j]=0;
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cnt[i][dp[i][j]]++;
        }
    }
    // doing row-wise from n to 1 addition of values in count 
    for(ll i=1;i<=n;i++){
        for(ll j=n-1;j>=1;j--){
            cnt[i][j]=cnt[i][j]+cnt[i][j+1];
        }
    }
    
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ans=max(ans,dp[i][j]*cnt[i][dp[i][j]]);
        }
    }
    return ans;
}
