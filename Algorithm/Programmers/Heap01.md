```c++
#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include <iostream>


using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (size_t i = 0; i < scoville.size(); ++i)
    {
        q.push(scoville[i]);
    }
    while (!q.empty() &&q.top() <= K )
    {
        int Nspicy = q.top();
        q.pop();
        if (q.empty())
        {
            answer = -1;
            break;
        }
        int Nspicy2 = q.top();
        q.pop();
        int mix = Nspicy + (Nspicy2 * 2);
        q.push(mix);
        ++answer;
    }



    return answer;
}
```
