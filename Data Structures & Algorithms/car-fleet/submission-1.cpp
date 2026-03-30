class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>>l(n);
        for(int i=0;i<n;++i){
            l[i] = {position[i],speed[i]};
        }
        sort(l.rbegin(),l.rend());
        int count = 0;
        double last_reached;
        for(int i=0;i<n;++i){
            double present_reached = (double)(target-l[i].first)/(double)(l[i].second);
            if(i==0){
                count++;
                last_reached = present_reached;
            }
            else if(last_reached<present_reached){
                count++;
                last_reached = present_reached;
            }
        }
        return count;
    }
};
