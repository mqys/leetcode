class Stack {
public:
    // can only use one queue: do something in push, and other operations can be only O(1)
    // void push(int x) {
    //     que.push(x);
    //     for(int i=0;i<que.size()-1;++i){
    //         que.push(que.front());
    //         que.pop();
    //     }
    // }
    
    
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }
        q.pop();
        q.swap(temp);
    }

    // Get the top element.
    int top() {
        while (q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }
        int topNum = q.front();
        temp.push(topNum);
        q.pop();
        q.swap(temp);
        return topNum;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:    
    queue<int> q, temp;
};