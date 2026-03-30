class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<pair<int,int>>s;
        vector<int>ans(n,0);
        s.push({t[0],0});
        for(int i=1;i<n;++i){
            while(!s.empty()){
                auto x = s.top();
                if(x.first<t[i]){
                    s.pop();
                    ans[x.second] = i-x.second;
                }
                else
                    break;
            }
            s.push({t[i],i});
        }
        return ans;
    }
};
