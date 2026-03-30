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
        string ansString = "";
        queue<pair<int,int>>q;
        int l = 0;
        bool flag1 = false;
        for(int i=0;i<s.size();++i){
            int index;
            if(s[i]>'Z'){
                index = s[i]-'a' + 26;
            }
            else{
                index = s[i]-'A';
            }
            if(index == q.front().first && f1[index]<=0){
                q.pop();
                //cout<<s[i]<<" "<<i<<"\n";
                q.push({index,i});
            }
            else if(f1.count(index)){
                f1[index]--;
                //cout<<s[i]<<" "<<i<<"\n";
                q.push({index,i});
            }
            bool flag = true;
            while(flag){
                for(auto& x:f1){
                    if(x.second>0){
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    break;
                if(flag){
                    auto x = q.front();
                    //cout<<s.substr(x.second,i-x.second+1)<<"\n";
                    if(ansSize>i-x.second+1){
                        ansSize = i-x.second+1;
                        ansString = s.substr(x.second,ansSize);
                        //cout<<ansString<<"\n";
                    }
                    q.pop();
                    f1[x.first]++;
                }
            }
        }
        return ansString;
    }
};