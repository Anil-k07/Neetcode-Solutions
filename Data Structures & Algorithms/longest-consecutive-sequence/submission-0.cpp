class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            if(s.find(nums[i]-1)==s.end()){
                int count = 0;
                int now = nums[i];
                while(s.find(now)!=s.end()){
                    count++;
                    now+=1;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
