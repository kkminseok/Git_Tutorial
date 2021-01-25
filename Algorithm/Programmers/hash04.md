```c++
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include <map>
using namespace std;

bool pred(pair<pair<string, int>, int> pair1, pair<pair<string, int>, int> pair2)
{
    if (pair1.first.first == pair2.first.first)
    {
        if (pair1.first.second == pair2.first.second)
            return pair1.second < pair2.second;
        else
            return pair1.first.second > pair2.first.second;
    }
    else
        return pair1.first.first < pair2.first.first;
}

bool countingvec(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}
int binarysearch(vector<pair<pair<string, int>, int>> vec, string str, int size)
{
    int lower = 0;
    int upper = size - 1;
    int mid;
    while (lower <= upper)
    {
        mid = (lower + upper) / 2;
        if (str > vec[mid].first.first)
            lower = mid + 1;
        else
            upper = mid - 1;
    }
    return lower;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    vector<pair<pair<string, int>, int>> vec;


    for (size_t i = 0; i < genres.size(); ++i)
    {

        //cout << vec[i].first.first << vec[i].first.second << vec[i].second << '\n';
        vec.push_back(make_pair(make_pair(genres[i], plays[i]), i));

        //map에 카운트 값을 넣는다. 맨처음꺼라면
        if (m.find(vec[i].first.first) == m.end())
        {
            m.insert(make_pair(vec[i].first.first, vec[i].first.second));
        }
        else//찾았다면
        {
            m[vec[i].first.first] += vec[i].first.second;
        }
    }
    sort(vec.begin(), vec.end(), pred);
    map<string, int>::iterator iter;
    vector<pair<string, int>> countvec(m.begin(), m.end());
    sort(countvec.begin(), countvec.end(), countingvec);
    for (size_t i = 0; i < countvec.size(); ++i)
    {
        int range = 0;
        string findstr = "";
        findstr += countvec[i].first;
        int index = binarysearch(vec, findstr, vec.size());
        //cout << findstr << index << '\n';
        for (; range < 2; ++range)
        {
            //1개인 경우
            if (vec[index].first.first != findstr)
            {
                break;
            }
            else
            {
                answer.push_back(vec[index].second);
                ++index;
            }
        }
    }   

    return answer;
}
```
