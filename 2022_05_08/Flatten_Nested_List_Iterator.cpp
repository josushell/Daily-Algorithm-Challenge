/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> v;
    int index = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        pushBack(nestedList);
    }
    
    void pushBack(vector<NestedInteger> &nestedList)
    {
        for(int i = 0;i < nestedList.size();i++)
        {
            if (nestedList[i].isInteger() == true)
                v.push_back(nestedList[i].getInteger());
            else
            {
                pushBack(nestedList[i].getList());
            }
        }
    }
    
    int next() {
        return v[index++];
    }
    
    bool hasNext() {
        return index < v.size();
    }
};
