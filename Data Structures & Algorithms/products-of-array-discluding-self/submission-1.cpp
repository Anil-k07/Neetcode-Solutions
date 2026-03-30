class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ans = 1;
        int countZ = 0;
        for(auto& x:nums){
            if(x!=0)
                ans*=x;
            else
                countZ++;
        }
        int n = nums.size();
        if(countZ>1){
            return vector<int>(n,0);
        }
        for(int i=0;i<nums.size();++i)
            if(countZ==1){
                if(nums[i]==0)
                    nums[i] = ans;
                else
                    nums[i] = 0;
            }
            else{
                nums[i] = ans/nums[i];
            }
        return nums;
    }
};
