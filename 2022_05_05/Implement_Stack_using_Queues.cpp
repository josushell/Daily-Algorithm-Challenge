class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    int index = 0;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        index++;
    }
    
    int pop() {
        int temp;
        
        for(int i = 0;i < index - 1;i++)
        {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        
        temp = q1.front();
        q1.pop();
        
        while (!q2.empty())
        {
            int item = q2.front();
            q1.push(item);
            q2.pop();
        }
        
        index--;
        return temp;
    }
    
    int top() {
        int temp = 0;
        
        while (!q1.empty())
        {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        
        while (!q2.empty())
        {
            int item = q2.front();
            q1.push(item);
            q2.pop();
        }
        
        return temp;
    }
    
    bool empty() {
        return q1.empty();
    }
};


