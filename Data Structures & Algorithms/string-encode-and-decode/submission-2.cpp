class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto& s:strs){
            int n = s.size();
            ans+=to_string(n);
            ans+="#";
            ans+=s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int count = 0;
        int n = s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='#'){
                ans.push_back(s.substr(i+1,count));
                if(count)
                    i += count;
                count=0;
            }
            else if(s[i]>='0' && s[i]<='9'){
                count*=10;
                count+=(s[i]-'0');
            }
        }
        return ans;
    }
};
