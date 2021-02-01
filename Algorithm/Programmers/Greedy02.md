```c++
#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int move = 0;
    string compare(name.length(), 'A');
    for (size_t i = 0; i < compare.size(); ++i)
        cout << compare[i];
    while (compare != name)
    {
        int next = 0; int left = 0; int right = 0;
        for (int i = 0; i < name.size(); ++i)
        {
            if (move + i < name.size()) right = move + i;
            else  right = move + i - name.size();

            if (move - i >= 0) left = move - i;
            else left = move - i + name.size();

            if (compare[right] != name[right]) next = right;
            else if (compare[left] != name[left])next = left;
            else
                continue;


            answer += i;
            answer += min(name[next] - 'A', 'Z' - name[next] + 1);
            compare[next] = name[next];
            cout << next;
            break;
        }
        move = next;
    }

    return answer;
}
```
