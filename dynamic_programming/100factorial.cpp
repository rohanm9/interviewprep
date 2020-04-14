//Given two array of integers A, B of equal size N. Power of an array is defined as the product of all the elements of the array. If the power of array A >= power of array B return 1 else return 0.
#define ll long long
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
const ll m=1e9+7;
ll multiply(ll x,ll res[],ll res_size){
    ll carry=0;
    For(i,0,res_size){
        ll prod=res[i]*x+carry;
        res[i]=prod%10;
        carry=prod/10;
    }
    while(carry){
        res[res_size]=carry%10;
        carry=carry/10;
        res_size++;
    }
    return res_size;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    ll n=A.size();
    ll max=1e5+1;
    ll res1[max];
    res1[0]=1;
    ll res1_size=1;
    For(i,0,n){
        res1_size=multiply(A[i],res1,res1_size);
    }
    // ll res2[max];
    // res2[0]=1;
    // ll res2_size=1;
    // For(i,0,n){
    //     res2_size=multiply(B[i],res2,res2_size);
    // }
    // if(res1_size>res2_size){
    //     return 1;
    // }
    // else if(res1_size==res2_size){
    //     ll i=0;
    //     while(res1[res1_size-1-i]==res2[res2_size-1-i]&&i<res1_size){
    //         i++;
    //     }
    //     if(i==res1_size){
    //        return 1; 
    //     }
    //     else{
    //         if(res1[res1_size-1-i]>=res2[res2_size-1-i]){
    //             return 1;
    //         }
    //         else{
    //             return 0;
    //         }
    //     }
    // }
    // else{
    //     return 0;
    // }
}
