```c++
#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int* stu = new int[n+2];
    for (int i = 0; i < n+1; ++i)
    {
        stu[i+1] = 1;
    }

    for (size_t i = 0; i < reserve.size(); ++i)
    {
        stu[reserve[i]]++;
    }
    for (size_t i = 0; i < lost.size(); ++i)
    {
        stu[lost[i]]--;
    }
    for (int i = 1; i < n+1; ++i)
    {
        if (stu[i]==0)
        {
            if (i + 1 < n + 1 && stu[i + 1] > 1)
            {
                stu[i]++;
                stu[i + 1]--;
            }
            else if (i - 1 > 0 && stu[i - 1] > 1)
            {
                stu[i]++;
                stu[i - 1]--;
            }
        }
        if (stu[i] > 0)
            ++answer;
        cout << stu[i] << " ";
    }



    return answer;
}
```
