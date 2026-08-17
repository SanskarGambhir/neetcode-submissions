class MyHashSet {
public:
    vector<int> present = vector<int>(1000001, -1);
    MyHashSet() {
        
    }
    
    void add(int key) {
        present[key] = key;
    }
    
    void remove(int key) {
        present[key] = -1;
    }
    
    bool contains(int key) {
        if(present[key]!=-1){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */