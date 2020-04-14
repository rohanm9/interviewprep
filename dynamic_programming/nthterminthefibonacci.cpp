//F[0][0] F[0][1]
//F[1][0] F[1][1]
void multiply(ll F[2][2],ll M[2][2]){
    ll w=F[0][0]*M[0][0]+F[0][1]*M[1][0];
    ll x=F[0][0]*M[0][1]+F[0][1]*M[1][1];
    ll y=F[1][0]*M[0][0]+F[1][1]*M[1][0];
    ll z=F[1][0]*M[0][1]+F[1][1]*M[1][1];
    F[0][0]=w;
    F[0][1]=x;
    F[1][0]=y;
    F[1][1]=z;
}
void powerfuncformatrix(ll F[2][2],ll n){
    if(n==0||n==1)// stop the recursion
        return;
    powerfuncformatrix(F,n/2);
    multiply(F,F);
    if(n%2!=0){
        ll M[2][2]={{1,1},{1,0}};
        multiply(F,M);
    }
}
ll fib(ll n){
    ll F[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    powerfuncformatrix(F,n-1);
    return F[0][0];
}