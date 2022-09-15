class MyQueue {
public:
    stack<int> a,b;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        int n = a.size();
        int r;
        for(int i=0;i<n;i++) {
            r = a.top();
            if(i!=n-1) {b.push(a.top());}
            a.pop();
        }
        int m = b.size();
        for(int i=0;i<m;i++) {
            a.push(b.top());
            b.pop();
        }
        
        return r;
        
    }
    
    int peek() {
        int n = a.size();
        int r;
        for(int i=0;i<n;i++) {
            r = a.top();
            b.push(a.top());
            a.pop();
        }
        int m = b.size();
        for(int i=0;i<m;i++) {
            a.push(b.top());
            b.pop();
        }
        return r;
    }
    
    bool empty() {
        return a.empty();
    }
};