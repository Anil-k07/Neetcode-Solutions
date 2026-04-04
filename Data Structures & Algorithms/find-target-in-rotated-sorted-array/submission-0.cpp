class Solution {
public:
    int binary_search(int l,int r,vector<int>& nums,int target){
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]>target)
                r = mid;
            else if(nums[mid]<target)
                l = mid+1;
            else{
                return mid;
            }
        }
        return -1;
    }
    int find_min(vector<int>& nums){
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            //cout<<mid<<"\n";
            if(nums[mid]>nums[l])
                l = mid;
            else if(nums[mid] == nums[l])
                return r;
            else
                r = mid;
        }
        return r;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0]<=nums[n-1])
            return binary_search(0,n,nums,target);
        int index = find_min(nums);
        if(target>=nums[0] && target<=nums[index-1])
            return binary_search(0,index,nums,target);
        else
            return binary_search(index,n,nums,target);
    }
};
