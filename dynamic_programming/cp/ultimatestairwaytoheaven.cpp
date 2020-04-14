void solve(){
    ll n;
    cin>>n;
    ll a[n],sum=0,dp[n],temp[n];
    For(i,0,n) cin>>a[i],temp[i]=0;
    dp[0]=1;
    For(i,0,n-1){
// dp[i] is added to temp[i+1] which is then added to sum 
        temp[i+1]=(temp[i+1]+dp[i])%m;
//when temp [a[i]+i+1] is added to sum dp[i] should be subtract hence when adding temp[i+1]
        if(a[i]+i+1<n) temp[i+1+a[i]]=(m+temp[i+1+a[i]]-dp[i])%m;
        sum=(sum+temp[i+1])%m;
        dp[i+1]=sum;
    }
    print(dp[n-1]);
}