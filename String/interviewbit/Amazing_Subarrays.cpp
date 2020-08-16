//question is wrong or we have to consider substring different if it 
//starts with different index
bool isVowel(char c){
    bool cond1 = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    bool cond2 = c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    if( cond1 || cond2 ){
        return true;
    }
    else{
        return false;
    }
}
int mod = 1e4 + 3;
int Solution::solve(string A){
    int n = A.length();
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(isVowel(A[i])){
            ans = (ans%mod + (n - i)%mod)%mod; 
        }
    }
    return ans;
}