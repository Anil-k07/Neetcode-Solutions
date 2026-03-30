class MinStack {
public:
    vector<pair<int,int>>st;
    int left;
    vector<pair<int,int>>mn;

    MinStack() {
        st.clear();
        mn.clear();
        left = -1;
    }
    
    void push(int val) {
        if(left<0){
            st.clear();
            mn.clear();
            mn.push_back({val,1});
        }
        else{
            mn.push_back({min(mn[left].first,val),1});
        }
        st.push_back({val,1});
        left++;
        while(!st[left].second)
            left++;
    }
    
    void pop() {
        st[left].second = 0;
        left--;
        while(!st[left].second)
            left--;
    }
    
    int top() {
        return st[left].first;
    }
    
    int getMin() {
        return mn[left].first;
    }
};
