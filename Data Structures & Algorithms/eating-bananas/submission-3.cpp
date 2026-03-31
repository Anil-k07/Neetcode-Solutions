class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minE = 1,maxE= 1;
        for(auto x:piles){
            maxE = max(maxE,x);
        }
        maxE++;
        int n = piles.size();
        while(minE<maxE){
            int mid = minE+(maxE-minE)/2;
            int count = 0;
            for(int i=0;i<n;++i){
                count+=((piles[i]/mid) + ((piles[i]%mid)>0));
            }
            if(count>h){
                minE = mid+1;
            }
            else{
                maxE = mid;
            }
        }
        return minE;
    }
};
