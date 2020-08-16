int Solution::strStr(const string A, const string B) {
    string str = B + "$" + A;
    int n = str.length();
    int L , R , k;
    L = R = 0; 
    vector<int> Z(n);
    for(int i = 1 ; i < n ; i++){
        if(i > R){
            L = R = i;
            while(R < n && str[R - L] == str[R]){
                R++;
            }
            Z[i] = R - L;
            R--;
        }
        else{
            k = i - L;
            if(Z[k] + i <= R){
                Z[i] = Z[k];
            }
            else{
                L = i;
                while(R < n && str[R - L] == str[R]){
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
    for(int i = 0 ; i < n; i++){
        if(Z[i] == B.length()){
            return i - (B.length() + 1);
        }
    }
    return -1;
}
