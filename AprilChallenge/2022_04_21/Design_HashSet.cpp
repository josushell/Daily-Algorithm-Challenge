class MyHashSet
{
private:
    vector<pair<int, int>> v;
    int index;
public:
    MyHashSet()
    {
        for(int i = 0;i <= 1000000;i++)
            v.push_back(make_pair(0, 0));
    }
    
    void add(int key)
    {
        if (v[key].first == 0)
        {
            v[key].second = key;
            v[key].first = 1;
        }
    }
    
    void remove(int key)
    {
        if (v[key].first == 1)
        {
            v[key].second = 0;
            v[key].first = 0;
        }
    }
    
    bool contains(int key)
    {
        if (v[key].first == 0)
            return false;
        else
            return true;
    }
};

