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
int Solution::isPalindrome(string A) {
    ll n = A.length();
    string str; 
    For(i,0,n){
        if('A' <= A[i] && A[i] <='Z' )
            A[i] = tolower(A[i]);
    }
    For(i,0,n){
        if('a' <= A[i] && A[i] <='z' || '0' <= A[i] && A[i] <= '1'){
            str.pb(A[i]);
        }
    }
    For(i,0,str.length()/2){
        if(str[i] != str[str.length()-1-i]){
            return 0;
        }
    }
    return 1;
}
