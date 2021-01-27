```c++
#include <string>
#include <vector>
#include<deque>
#include<iostream>
#include<algorithm>
using namespace std;

bool pred(int& a, int& b)
{
    return a < b;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    string str;
    bool check =  false;
    for (size_t i = 0; i < operations.size(); ++i)
    {
        str = operations[i];
        char query = str[0];
        str = str.substr(2);
        int insert = stoi(str);
        if (query == 'I')//insert
        {
            dq.push_back(insert);
            check = true;
        }
        else
        {
            if (insert == 1)
            {
                if (check)
                {
                    sort(dq.begin(), dq.end(),pred);
                    check = false;
                }
                if(!dq.empty())
                    dq.pop_back();
            }
            else
            {
                if (check)
                {
                    sort(dq.begin(), dq.end(),pred);
                    check = false;
                }
                if (!dq.empty())
                    dq.pop_front();
            }
        }
    }
    if (dq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        sort(dq.begin(), dq.end(), pred);
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }

    return answer;
}
```
