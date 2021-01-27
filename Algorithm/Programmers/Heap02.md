```c++
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;



int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    int ms = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int i = 0;
    while (i<jobs.size() || !pq.empty())
    {
        while (i<jobs.size() && jobs[i][0] <= ms)
        {
            pq.push(make_pair(jobs[i][1], jobs[i][0]));
            ++i;
        }

        //작업 처리 하나만
        if (!pq.empty())
        {
            int time = pq.top().first;
            int request = pq.top().second;
            pq.pop();
            ms += time;
            answer += (ms - request);
        }
        else
        {
            ms = jobs[i][0];
        }
        
    }
  
    answer = trunc(answer / jobs.size());
    return answer;
}
```
