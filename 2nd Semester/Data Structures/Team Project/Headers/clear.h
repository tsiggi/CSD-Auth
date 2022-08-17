#ifndef clear_h
#define clear_h

#include <string>
using namespace std;

string clear(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] < 'A' || s[i] > 'Z')&&(s[i] < 'a' || s[i] > 'z'))
        {
            s.erase(i, 1);
            i--;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i]=s[i]+32;
        }
    }
    return s;
}

#endif