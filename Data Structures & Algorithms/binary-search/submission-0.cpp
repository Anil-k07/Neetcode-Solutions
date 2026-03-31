class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                r=mid;
            else
                l=mid+1;
        }
        return -1;
    }
};
