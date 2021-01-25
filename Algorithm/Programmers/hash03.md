#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    //문자열과 카운트 값
    map<string,int> m;
    for(size_t i=0;i<clothes.size();++i)
    {
        if(m.find(clothes[i][1])==m.end())
        {
            m.insert(make_pair(clothes[i][1],1));
        }
        else
            m[clothes[i][1]]++;
    }
    if(m.size()>1)
    {
        int counting = 1;
        map<string,int>::iterator iter;
        for(iter = m.begin(); iter!=m.end();++iter)
        {
            counting*=((*iter).second+1);
        }
        answer+=counting;
        answer-=1;
    }
    else
    {
        answer +=clothes.size();
    }
    return answer;
}
