```c++
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool compare(string a,string b, int size)
{
    for(int i=0;i<size;++i)
    {
        //하나라도 다른 부분이 있다면
        if(a[i]!=b[i])
        {
            return true;
        }
    }
    return false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(size_t i = 0; i<phone_book.size()-1;++i)
    {
        int sizet = min(phone_book[i].size(),phone_book[i+1].size());
        answer = compare(phone_book[i],phone_book[i+1],sizet);
        if(!answer)
        {
            return answer;
        }
    }
    return answer;
}
```
