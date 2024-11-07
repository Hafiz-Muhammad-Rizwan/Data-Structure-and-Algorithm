#include<iostream>
#include<queue>
using namespace std;

class Solution {
    queue<char>Queue;
    char ch;
public:
    bool isCircularSentence(string sentence) {
        int size = sentence.size();
        bool isSpace = false;
        if (sentence[0] != sentence[size - 1])
        {
            return false;
        }


        for (int i = 0; i < size; i++)
        {

            if (sentence[i] == ' ')
            {
                isSpace = true;
                continue;
            }

            if (isSpace == true)
            {
                if (ch != sentence[i])
                {
                    return false;
                }
            }
            Queue.push(sentence[i]);
            ch = sentence[i];
            isSpace = false;


        }
        return Queue.front() == sentence[0];
    }
};
