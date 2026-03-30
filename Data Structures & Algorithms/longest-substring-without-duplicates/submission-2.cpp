class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1;
        int right = -1;
        int ans = 0;
        map<char,int>mp;
        for(int i=0;i<s.size();++i){
            if(mp.count(s[i]) == 0){
                mp[s[i]] = i;
            } 
            else{
                if(left<mp[s[i]]){
                    left = mp[s[i]];
                }
                mp[s[i]] = i;
            }
            right++;
            ans = max(ans,right-left);
            //cout<<s.substr(left+1,right-left)<<"\n";
        }
        ans = max(ans,right-left);
        return ans;
    }
};
