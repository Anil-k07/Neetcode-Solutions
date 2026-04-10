class Solution {
public:
    string minWindow(string s, string t) {
        map<int,int>f1;
        for(int i=0;i<t.size();++i){
            if(t[i]>'Z'){
                f1[t[i]-'a' + 26]++;
            }
            else{
                f1[t[i]-'A']++;
            }
        }
        int ansSize = 100001;
        int start = -1;
        queue<pair<int,int>>q;
        for(int i=0;i<s.size();++i){
            int index;
            if(s[i]>'Z')
                index = s[i]-'a' + 26;
            else
                index = s[i] - 'A';
            if(f1.count(index)){
                f1[index]--;
                q.push({index,i});
                int flag = true;
                for(auto& x:f1)
                    if(x.second>0){
                        flag = false;
                        break;
                    }
                if(flag){
                    while(!q.empty()){
                        auto y = q.front();
                        q.pop();
                        if(ansSize>i-y.second+1){
                            ansSize = i-y.second+1;
                            start = y.second;
                        }
                        f1[y.first]++;
                        if(f1[y.first]>0)
                            break;
                    }
                }
            }
        }
        return start==-1?"":s.substr(start,ansSize);
    }
};