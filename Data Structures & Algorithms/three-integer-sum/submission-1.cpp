class Solution {
public:
    int binary_search(vector<int>&nums, int target, int index){
        int left=index;
        int right = nums.size()-1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid]>target){
                right = mid - 1;
            }
            else if(nums[mid]<target){
                left = mid + 1;
            }
            else if (nums[mid] == target)
                return mid;
        }
        return nums[left] == target ? left : -1;
    }
    vector<vector<int>>twoSum(vector<int>& nums,int index){
        set<vector<int>>ans;
        for(int i=index;i<nums.size();++i){
                //cout<<nums[i]<<" ";
                int search = binary_search(nums,-nums[index-1]-nums[i],i+1);
                if(search!=-1){
                    ans.insert({nums[i],nums[search]});
                    //cout<<nums[i] << " " <<nums[search] << " " << nums[index-1] <<"\n";
                }
        }
        //cout<<"\n";
        return vector<vector<int>>(ans.begin(),ans.end());
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        for(int i=0;i<n;++i){
            vector<vector<int>>temp = twoSum(nums,i+1);
            if(temp.size()){
                for(auto& x:temp){
                    x.push_back(nums[i]);
                    sort(x.begin(),x.end());
                    ans.insert(x);
                    // for(auto y:x)
                    //     cout<<y<<" ";
                    // cout<<"\n";
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
