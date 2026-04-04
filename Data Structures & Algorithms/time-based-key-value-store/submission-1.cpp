class TimeMap {
public:
    unordered_map<string,vector<string>>mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        //cout<<"Set\n";
        if(!mp.count(key))
            mp[key] = vector<string>(1002,"");
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        //cout<<"Get\n";
        if(!mp.count(key))
            return "";
        vector<string>res = mp[key];
        if(timestamp>1001)
            timestamp = 1001;
        if(timestamp<=0)
            timestamp = 1;
        for(int i=timestamp;i>=0;--i){
            if(res[i].size()>0)
                return res[i];
        }
        return "";
    }
};
