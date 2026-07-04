class MyQueue {
public:
    stack<int> inp;
    stack<int> outp;
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if (outp.empty()){
            while(!inp.empty()){
                outp.push(inp.top());
                inp.pop();
            }
        }
        int val = outp.top();
        outp.pop();
        return val;
    }
    
    int peek() {
        if (outp.empty()) {
            while (!inp.empty()) {
                outp.push(inp.top());
                inp.pop();
            }
        }
        return outp.top();

    }
    
    bool empty() {
        return inp.empty() && outp.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */