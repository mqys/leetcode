class MinStack {
public:
    // could use another container to store the min
    // when the pop equals to min, pop the min as well
    void push(int x) {
        data.push_back(x);
        if (x < min)
            min = x;
    }

    void pop() {
        // need to refresh min
        int temp = data.back();
        data.pop_back();
        if (temp == min)
            min = searchMin();
    }

    int top() {
        return data.back();
    }

    int getMin() {
        return min;
    }
private:
    vector<int> data;
    int min = INT_MAX;
    int searchMin() {
        if (data.empty()) return INT_MAX;
        int m = data[0];
        for (int i = 1; i < data.size(); ++i) {
            if (data[i] < m)
                m = data[i];
        }
        return m;
    }
};