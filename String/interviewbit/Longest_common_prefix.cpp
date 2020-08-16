
#define ll long long
#define ld long double
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define FoR(i,a,b) for(ll i=a;i<=b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
string solver(string &str1,string &str2){
    ll n = str1.length();
    ll m = str2.length();
    string sum;
    For(i,0,min(n,m)){
        if(str1[i] == str2[i]){
            sum = sum + str1[i];
        }
    }
    return sum;
}
string Solution::longestCommonPrefix(vector<string> &A) {
    if(A.size()==1){
        return A[0];
    }
    string ans;
    For(i,0,min(A[0].length(),A[1].length())){
        if(A[0][i] == A[1][i]){
            ans = ans + A[0][i];
        }
    }
    For(i,2,A.size()){
        ans = solver(ans,A[i]);
    }
    return ans;
}