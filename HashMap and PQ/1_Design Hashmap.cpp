class MyHashMap {
public:
    map<int, int> hMap;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        hMap[key] = value;
    }
    
    int get(int key) {
        map<int, int>::iterator it = hMap.find(key);
        if (it == hMap.end()) return -1;
        else return it->second;
    }
    
    void remove(int key) {
        map<int, int>::iterator it = hMap.find(key);
        if (it == hMap.end()) return;
        else hMap.erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */