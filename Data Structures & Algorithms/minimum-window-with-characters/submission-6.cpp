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
        int ansSize = 1001;
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
            for(auto& x:f1){
                if(x.second>0){
                    flag = false;
                    break;
                }
            }
            flag1|=flag;
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
            // queue<pair<int,int>>q2;
            // q2 = q;
            // while(!q2.empty()){
            //     auto x = q2.front();
            //     q2.pop();
            //     cout<<x.first<<" "<<x.second<<"\n";
            // }
            // cout<<"--------------------------";
        }
        if(!flag1)
            return "";
        int r=ansSize-1;
        //cout<<ansString.substr(l,r-l+1)<<"\n";
        for(int i=ansSize-1;i>=0;--i){
            //cout<<ansString[i]<<" ";
            int index;
            if(ansString[i]>'Z'){
                index = ansString[i]-'a' + 26;
            }
            else{
                index = ansString[i]-'A';
            }
            if(f1.count(index)){
                if(f1[index]<0){
                    r--;
                    f1[index]++;
                    //cout<<"Here 1\n";
                }
                else{
                    //cout<<"Here 2\n";
                    break;
                }
            }
            else{
                //cout<<"Here 3\n";
                r--;
            }
        }
        //cout<<ansString.substr(l,r+1-l)<<"\n";
        for(int i=0;i<=r;++i){
            //cout<<ansString[i]<<" ";
            int index;
            if(ansString[i]>'Z'){
                index = ansString[i]-'a' + 26;
            }
            else{
                index = ansString[i]-'A';
            }
            if(f1.count(index)){
                if(f1[index]<0){
                    l++;
                    f1[index]++;
                    //cout<<"Here 1\n";
                }
                else{
                    //cout<<"Here 2\n";
                    break;
                }
            }
            else{
                //cout<<"Here 3\n";
                l++;
            }
        }
        //cout<<l<<" "<<r<<"\n";
        return ansString.substr(l,r+1-l);
    }
};
