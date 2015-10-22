class Queue {
public:
    // use two stacks to get the top element
    // 没有必要每次调用都取出再放回，当输出栈没有元素的时候才需要双栈之间传数据
    // (队列特性：维护队首元素即可) 保证队首一直再输出栈的首部
    
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        // stack<int> temp;
        // while (!s.empty()) {
        //     temp.push(s.top());
        //     s.pop();
        // }
        // temp.pop();
        // while (!temp.empty()) {
        //     s.push(temp.top());
        //     temp.pop();
        // }
        peek();
        out.pop();
    }

    // Get the front element.
    int peek(void) {
        // stack<int> temp;
        // while (!s.empty()) {
        //     temp.push(s.top());
        //     s.pop();
        // }
        // int r = temp.top();
        // while (!temp.empty()) {
        //     s.push(temp.top());
        //     temp.pop();
        // } 
        // return r;
        if (out.empty()) {
            while (!s.empty()) {
                out.push(s.top());
                s.pop();
            }
        }
        return out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        // return s.empty();
        return s.empty() && out.empty();
    }
private:
    stack<int> s;
    stack<int> out;
};