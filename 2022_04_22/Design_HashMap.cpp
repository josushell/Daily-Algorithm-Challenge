class MyHashMap {
private:
    vector<pair<int, int>> v;
public:
    MyHashMap() {
        for(int i = 0;i <= 1000000;i++)
            v.push_back(make_pair(i, -1));
    }
    
    void put(int key, int value) {
        v[key].second = value;
    }
    
    int get(int key) {
        return v[key].second;
    }
    
    void remove(int key) {
        v[key].second = -1;
    }
};
