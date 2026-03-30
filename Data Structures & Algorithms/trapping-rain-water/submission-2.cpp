class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>maxLR(n),maxRL(n);
        maxLR[0] = 0;
        maxRL[n-1] = 0;
        int ans = 0;
        for(int i=1;i<n;i++){
            maxLR[i] = max(maxLR[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;--i){
            maxRL[i] = max(maxRL[i+1],height[i+1]);
        }

        for(int i=0;i<n;++i){
            ans+=max(0,(min(maxRL[i],maxLR[i])-height[i]));
        }
        return ans;
    }
};
