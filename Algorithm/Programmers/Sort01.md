```c++
#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;


	for (size_t i = 0; i < commands.size(); ++i)
	{
		int* temp = new int[array.size()];
		for (size_t i = 0; i < array.size(); ++i)
		{
			temp[i] = array[i];
		}
		
		int start = commands[i][0]-1;
		int end = commands[i][1];
		int index = commands[i][2]-1;


		sort(temp+start, temp+end);
		for (int i = 0; i < array.size(); ++i)
			cout << temp[i] << " ";
		cout << '\n';

		answer.push_back(temp[index+start]);


		delete temp; 
	}

	
		return answer;
}
```
