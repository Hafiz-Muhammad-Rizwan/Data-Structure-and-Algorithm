#include<iostream>
#include<queue>
using namespace std;


class Solution {
    queue<char>obj;
    string Rotated_String;
public:
    bool rotateString(string s, string goal) {

        if (s == goal)
        {
            return true;
        }
        if (s.size() != goal.size())
        {
            return false;
        }

        string Concatenate = s + s;

        return Concatenate.find(goal) != string::npos;

        // Alternative Method 

          // int C_length=Concatenate.size();
          // int G_length=goal.size();

          // for(int i =0;i<C_length-G_length;i++)
          // {
          //     int j=0;

          //     while(j<G_length&&Concatenate[i+j]==goal[j])
          //     {
          //         j++;
          //     }
          //     if(j==G_length)
          //     {
          //         return true;
          //     }
          // }
          // return false;
    }
};