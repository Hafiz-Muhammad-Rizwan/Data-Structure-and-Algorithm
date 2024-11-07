#include<iostream>
#include<queue>
using namespace std;


class FrontMiddleBackQueue {
public:

    // Make two Queues
    queue<int>Original_queue;
    queue<int>Temp_queue;
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        //First clear the Original queue then push data in it
        while (Original_queue.empty() == false)
        {
            Temp_queue.push(Original_queue.front());
            Original_queue.pop();
        }
        Original_queue.push(val);

        while (Temp_queue.empty() == false)
        {
            Original_queue.push(Temp_queue.front());
            Temp_queue.pop();
        }

    }

    void pushMiddle(int val) {
        int Size = Original_queue.size();
        for (int i = 0; i < (Size) / 2; i++)
        {
            Temp_queue.push(Original_queue.front());
            Original_queue.pop();
        }
        Temp_queue.push(val);

        while (Original_queue.empty() == false)
        {
            Temp_queue.push(Original_queue.front());
            Original_queue.pop();
        }


        while (Temp_queue.empty() == false)
        {
            Original_queue.push(Temp_queue.front());
            Temp_queue.pop();
        }
    }

    void pushBack(int val) {
        Original_queue.push(val);
    }

    int popFront() {
        int x = 0;
        if (Original_queue.empty() == true)
        {
            return -1;
        }
        x = Original_queue.front();
        Original_queue.pop();
        return x;
    }

    int popMiddle() {
        int x = 0;
        int Size = Original_queue.size();
        if (Original_queue.empty() == true)
        {
            return -1;
        }

        for (int i = 0; i < (Size - 1) / 2; i++)
        {
            Temp_queue.push(Original_queue.front());
            Original_queue.pop();
        }

        x = Original_queue.front();
        Original_queue.pop();

        while (Original_queue.empty() == false)
        {
            Temp_queue.push(Original_queue.front());
            Original_queue.pop();
        }

        while (Temp_queue.empty() == false)
        {
            Original_queue.push(Temp_queue.front());
            Temp_queue.pop();
        }
        return x;
    }

    int popBack() {
        if (Original_queue.empty() == true)
        {
            return -1;
        }
        while (Original_queue.size() > 1)
        {
            Temp_queue.push(Original_queue.front());
            Original_queue.pop();
        }
        int x = Original_queue.front();
        Original_queue.pop();
        while (Temp_queue.empty() == false)
        {
            Original_queue.push(Temp_queue.front());
            Temp_queue.pop();
        }
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */