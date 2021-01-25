```c++
#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int counting =0;
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    for (int size = 0;size<participant.size();++size)
    {
        if(size>completion.size())
        {
            answer = participant[size];
            return answer;
        }
        if(participant[size]!=completion[size])
        {
            answer = participant[size];
            return answer;
        }
    }
    

    return answer;
}
```
