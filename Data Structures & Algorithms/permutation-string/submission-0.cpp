class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>f1(26,0),f2(26,0);
        if(s2.size()<s1.size())
            return false;
        for(int i=0;i<s1.size();++i){
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }
        if(f1==f2)
            return true;
        for(int i=s1.size();i<s2.size();++i){
            f2[s2[i-s1.size()]-'a']--;
            f2[s2[i]-'a']++;
            if(f1==f2)
                return true;
        }
        return false;
    }
};
