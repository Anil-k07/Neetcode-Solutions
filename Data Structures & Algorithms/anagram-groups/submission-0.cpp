class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        int n = strs.size();
        for(int i=0;i<n;++i){
            vector<int>temp(26,0);
            int m = strs[i].size();
            for(int j=0;j<m;++j){
                temp[strs[i][j]-'a']++;
            }
            if(mp.count(temp)!=0){
                auto v = mp[temp];
                v.push_back(strs[i]);
                mp[temp] = v;
            }
            else{
                vector<string>v;
                v.push_back(strs[i]);
                mp[temp] = v;
            }
        }
        vector<vector<string>>ans;
        for(auto& m:mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};
