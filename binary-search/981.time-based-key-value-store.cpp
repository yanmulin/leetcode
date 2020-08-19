class TimeMap {
private:
    unordered_map<string, map<int, string>> _s;
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        _s[key].emplace(timestamp, move(value));
    }
    
    string get(string key, int timestamp) {
        auto m = _s.find(key);
        if (m == _s.end()) return "";
        auto found = m->second.upper_bound(timestamp);
        if (found == begin(m->second)) return "";
        else return prev(found)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
