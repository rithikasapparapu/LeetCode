class MyHashMap {
public:
    vector<pair<int,int>> hashmap;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i=0; i<hashmap.size(); i++){
            if(hashmap[i].first == key){
                hashmap[i].second = value;
                return;
            }
        }
        hashmap.push_back(make_pair(key,value));
    }
    
    int get(int key) {
        for(int i=0; i<hashmap.size(); i++){
            if(hashmap[i].first == key) return hashmap[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0; i<hashmap.size(); i++){
            if(hashmap[i].first == key) hashmap.erase(hashmap.begin()+i);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */