class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0,r = 0;
        int n = s.size();
        int ans = 0;
        vector<int>fre(26,0);
        while(r<n){
            fre[s[r]-'A']++;
            int mfre = 0;
            for(int i=0;i<26;++i){
                mfre = max(mfre,fre[i]);
            }
            if((r-l+1)-mfre<=k){
                ans = max(ans,r-l+1);
            }
            else{
                fre[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
