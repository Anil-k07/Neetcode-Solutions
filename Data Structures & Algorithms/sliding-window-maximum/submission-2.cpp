class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n-k+1,-10001);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;++i){
            pq.push({nums[i],i});
        }
        int have = 0;
        while(have<n-k+1){
            auto x = pq.top();
            pq.pop();
            int index = x.second;
            int y = index-k+1;
            for(int i=0;i<k;++i){
                if(y+i<0)
                    continue;
                if(y+i>=n-k+1)
                    break;
                if(index+i<n && ans[y+i]==-10001){
                    //cout<<y+i<<" "<<x.first<<"\n";
                    ans[y+i] = x.first;
                    have++;
                }
            }
        }
        return ans;
    }
};
