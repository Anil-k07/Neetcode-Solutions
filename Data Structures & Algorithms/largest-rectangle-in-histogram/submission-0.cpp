class Solution {
public:
    int maxArea(int l,int r,int n,vector<int>&h){
        if(l<0 || r>n || l>=r)
            return 0;
        // if(dp[l][r]!=-1)
        //     return dp[l][r];
        vector<pair<int,int>>temp;
        for(int i=l;i<r;++i){
            temp.push_back({h[i],i});
        }
        sort(temp.begin(),temp.end());
        int ans = temp[0].first*(r-l);
        ans = max(ans,max(maxArea(l,temp[0].second,n,h),maxArea(temp[0].second+1,r,n,h)));
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //dp.resize(n,vector<int>(n,-1));
        return maxArea(0,n,n,heights);
    }
};
