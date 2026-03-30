class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty())
                    return false;
                auto y = st.top();
                if(y=='('){
                    if(s[i]!=')')
                        return false;
                }
                else if(y == '{'){
                    if(s[i]!='}')
                        return false;
                }
                else 
                    if(s[i]!=']')
                        return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
