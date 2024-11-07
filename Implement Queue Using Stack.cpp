#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int>obj1;
    stack<int>obj2;
    MyQueue() {

    }

    void push(int x) {
        if (empty() == true)
        {
            obj1.push(x);
            return;
        }
        while (obj1.empty() == false)
        {
            obj2.push(obj1.top());
            obj1.pop();
        }
        obj1.push(x);
        while (obj2.empty() == false)
        {
            obj1.push(obj2.top());
            obj2.pop();
        }
    }

    int pop() {
        int x = 0;
        if (empty() == false)
        {
            x = obj1.top();
            obj1.pop();
            return x;
        }
        return -1;
    }

    int peek() {
        if (empty() == false)
        {

            return obj1.top();
        }
        return -1;

    }

    bool empty() {
        return (obj1.empty());
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