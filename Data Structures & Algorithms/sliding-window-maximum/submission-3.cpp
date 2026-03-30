class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n-k+1,-10001);
        priority_queue<pair<int,int>>pq;
        int count = 0;
        for(int i=0;i<n;++i){
            pq.push({nums[i],i});
            count++;
            if(count>=k){
                while(!pq.empty()){
                    auto x = pq.top();
                    if(x.second<count && x.second>count-k-1)
                        break;
                    pq.pop();
                }
                ans[count-k] = pq.top().first;
            }
        }
        return ans;
    }
};
