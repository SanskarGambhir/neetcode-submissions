class TimeMap {
public:
    map<pair<string, int>, string> timemap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[{key,timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        string value = "";

        while(timestamp > -1){
            if(timemap.find({key,timestamp}) != timemap.end()){
                value = timemap[{key,timestamp}];
                return value;
            }
            timestamp--;
        }

        return "";
    }
};
