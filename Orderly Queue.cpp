#include<iostream>
#include<queue>
using namespace std;


class Solution {
public:
    queue<char>obj;
    string orderlyQueue(string s, int k) {
        if (k == 1)
        {
            for (int i = 0; i < s.size(); i++)
            {
                obj.push(s[i]);
            }

            string Smallest_String = s;
            string Rotated_String;
            char Ch;
            for (int i = 0; i < s.size(); i++)
            {
                Ch = obj.front();
                obj.pop();
                obj.push(Ch);

                Rotated_String = "";
                for (int j = 0; j < s.size(); j++)
                {
                    Rotated_String += obj.front();
                    obj.pop();
                }

                if (Rotated_String < Smallest_String)
                {
                    Smallest_String = Rotated_String;
                }


                for (int i = 0; i < Rotated_String.size(); i++)
                {
                    obj.push(Rotated_String[i]);
                }

            }
            return Smallest_String;
        }
        else
        {
            for (int i = 0; i < s.size() - 1; i++)
            {
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (s[i] > s[j])
                    {
                        char Swap;
                        Swap = s[i];
                        s[i] = s[j];
                        s[j] = Swap;
                    }
                }
            }
            return s;
        }
    }
};