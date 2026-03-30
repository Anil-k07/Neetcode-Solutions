class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,bool> mp;
        for(auto x: nums){
            if(!mp.count(x)){
                mp[x] = true;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};