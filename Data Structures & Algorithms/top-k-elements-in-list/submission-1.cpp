class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp1;
        vector<int>a;
        vector<pair<int,int>>ans;
        for(auto x:nums)
            mp1[x]++;
        for(auto it=mp1.begin();it!=mp1.end();it++){
            ans.push_back({it->second,it->first});
        }
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        for(int i=0;i<k;i++)
            a.push_back(ans[i].second);
        return a;
    }
};