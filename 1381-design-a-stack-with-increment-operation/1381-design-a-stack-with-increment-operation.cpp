class CustomStack {
public:
    stack<int>st;
    int som=0;
    int max1=0;
    CustomStack(int maxSize) {
       while(not(st.empty())){
           st.pop();
           som--;
       }
    max1=maxSize;
    }
    
    void push(int x) {
        if(som<max1){
        st.push(x);som++;}
    }
    
    int pop() { 
        if(st.empty())return -1;
        int val=st.top();
        st.pop();
        som--;
        return val;
    }
    
    void increment(int k, int val) {
        stack<int>st2;
        int som1=som;
        while(som>k){
            st2.push(st.top());
            st.pop();
            som--;
            
        }
    stack<int>st3;
    while(not(st.empty())){
        st3.push(st.top()+val);
        st.pop();
    }
    while(not(st3.empty())){
        st.push(st3.top());
        st3.pop();
    }
     while(not(st2.empty())){
        st.push(st2.top());
        st2.pop();
    }
    
    som=som1;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */