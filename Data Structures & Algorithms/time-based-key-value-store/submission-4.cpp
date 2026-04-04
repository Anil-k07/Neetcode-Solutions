class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        mp.clear();
    }
    
    string binary_search(int l,int r,vector<pair<int,string>>v,int t){
        while(l<r){
            int mid = l + (r-l)/2;
            if(v[mid].first<t){
                l = mid+1;
            }
            else if(v[mid].first == t)
                return v[mid].second;
            else
                r = mid;
        }
        return v[l-1].second;
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        sort(mp[key].begin(),mp[key].end());
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>values = mp[key];
        int sz = values.size();
        if(sz == 0 || values[0].first>timestamp)
            return "";
        if(timestamp>=values[sz-1].first)
            return values[sz-1].second;
        return binary_search(0,sz,values,timestamp);
    }
};
