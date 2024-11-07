#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
    queue<int>obj1;
    queue<int>obj2;
    MyStack() {

    }

    void push(int x) {
        if (obj1.empty() == true)
        {
            obj1.push(x);
            return;
        }
        while (obj1.empty() == false)
        {
            obj2.push(obj1.front());
            obj1.pop();
        }
        obj1.push(x);
        while (obj2.empty() == false)
        {
            obj1.push(obj2.front());
            obj2.pop();
        }

    }

    int pop() {
        int Delete_Value = 0;
        if (obj1.empty() == false)
        {
            Delete_Value = obj1.front();
            obj1.pop();
            return Delete_Value;
        }
        throw std::out_of_range("Stack is Empty");
    }

    int top() {
        if (obj1.empty() == false)
        {
            return obj1.front();
        }
        throw std::out_of_range("Stack is Empty");
    }

    bool empty() {
        return obj1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */