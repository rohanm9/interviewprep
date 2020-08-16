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
string Solution::countAndSay(int A) {
    string str = "1";
    A--;
    if(A==0) return str;
    str.pb('1');
    A--;
    if(A==0) return str;
    while(A){
        ll n = str.length();
        ll count = 0;
        string tmp;
        For(i,1,n){
            if(str[i] == str[i-1]){
                count++;
            }
            else{
                tmp.pb((char)(count+1+'0'));
                tmp.pb(str[i-1]);
                count = 0;
            }
        }
        if(str[n-2]!=str[n-1]){
            tmp.pb((char)(1 + '0'));
            tmp.pb(str[n-1]);
        }
        else if(count!=0){
            tmp.pb((char)(count +1 + '0'));
            tmp.pb(str[n-1]);
        }
        str = tmp;
        A--;
    }
    return str;
}
