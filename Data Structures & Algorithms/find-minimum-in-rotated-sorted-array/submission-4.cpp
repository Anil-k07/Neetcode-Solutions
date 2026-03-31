class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int ans = nums[0];
        if(nums[0]<=nums[n-1])
            return nums[0];
        int l = 0,r=n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[l]>nums[mid])
                r = mid;
            else if(nums[l]<nums[mid])
                l = mid;
            else
                return nums[r];
        }
        return ans;
    }
};
