//rohanm9
//DA-IICT,Gandhinagar
#include<bits/stdc++.h>
using namespace std;
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
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define print(a) cout<<a<<"\n"
const ll mod=1e9+7;
vector<vector<ll>>adjList;
vector<bool>visited;
// void solve(){
//     stack<ll>st,minst;
//     while(1){
//         print("1.push\n2.pop\n3.exit");
//         ll temp;
//         cin>>temp;
//         if(temp == 1){
//             ll delta;
//             cin>>delta;
//             st.push(delta);
//             if(minst.empty()||minst.top() >= delta){
//                 minst.push(delta);
//             }
//             print(minst.top());
//         }
//         else if(temp == 2){
//             if(st.empty()){
//                 print("No element in the stack to pop\n");
//                 
//             }
//             else if(st.top() == minst.top()){
//                 st.pop();
//                 minst.pop();
//                 if(!st.empty())
//                     print(minst.top());
//                 else
//                     print("Stack is empty");
//             }
//             else{
//                 st.pop()
//                 print(minst.top());
//             }
//         }
//         else if(temp == 3){
//             return;
//         }
//         else{
//             print("Invalid input");
//         }
//     }
// }
//More efficient with out using extra stack,the minst one
//We know that x - minEle<0 when x is less than minEle
//So x + x- minELe < x where is going to next minEle
//So we push(2*x - minEle) in that case(x < minEle) 

//similarly while poping we would if y < minELe then update minELe = 2*minELe - y why 
//becuz y is equal to 2*minEle - minEle_old so minEle = 2*minEle - (2*minEle - minEle_old) => minEle will be updated with old minimum
void solve(){
    stack<ll>st;
    ll minEle;
    while(1){
        print("1.push\n2.pop\n3.exit");
        ll temp;
        cin>>temp;
        if(temp == 1){
            ll x;
            cin>>x;
            if(st.empty() == 0){
                minEle = x;
            }
            else{
                if(x < minEle){
                    st.push(2*x - minEle);
                    minEle = x;
                }
                else{
                    st.push(x);
                }
            }
            print(minEle);
        }
        else if(temp == 2){
            if(st.empty()){
                print("No element in the stack to pop\n");
            }
            else{
                ll y = st.top();
                st.pop();
                if(st.empty()){
                    print("Stack is empty");
                }
                else{
                    if(y < minEle){
                        minEle = 2*minEle - y;
                    }   
                }
            }
        }
        else if(temp==3){
            return;
        }
        else{
            print("Invalid input");
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;
