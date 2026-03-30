class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();++i){
            auto s = tokens[i];
            if(s=="*" || s=="-" || s=="+" || s== "/"){
                auto y = st.top();
                st.pop();
                auto x = st.top();
                st.pop();
                if(s=="*"){
                    x*=y;
                }
                else if(s=="+"){
                    x+=y;
                }
                else if(s=="-"){
                    x-=y;
                }
                else{
                    x/=y;
                }
                st.push(x);
            }
            else{
                int x = 0;
                bool flag = false;
                for(int i=0;i<s.size();++i){
                    if(i==0 && (s[i]=='-'|| s[i] == '+')){
                        if(s[i]=='-')
                            flag = true;
                        continue;
                    }
                    x*=10;
                    x+=(s[i]-'0');
                }
                if(flag)
                    x*=-1;
                st.push(x);
            }
            //cout<<st.top();
        }
        return st.top();
    }
};
