class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(),m = t.size();
        if(n!=m)
            return false;
        vector<int>test(26,0);
        for(auto& ch:s)
            test[ch-'a']++;
        for(auto& ch:t)
            test[ch-'a']--;
        for(auto& x: test)
            if(x>0)
                return false;
        return true;
    }
};
