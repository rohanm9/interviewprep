rFor(i,n-1,0){
        // either stack gets empty!! OR (a[s1.top()]) we found next greater element!! -> will stop the loop 
        while(!s1.empty()&&a[s1.top()]<=a[i]){
            s1.pop();
        }
        if(!s1.empty()){
            next_greater[i]=s1.top();
        }
        else{
            next_greater[i]=-1;
        }
        // may be either it would be next greater element or elements already in stack
        s1.push(i);
    }