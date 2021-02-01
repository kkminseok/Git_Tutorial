```c++
#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
bool* PrimeArray;

int counting[10] = { 0, };
void Eratos(int n)
{
	PrimeArray = new bool[n + 1];
	cout << n;
	if (n <= 1) return;

	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;
	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}

	// 이후의 작업 ...
}
bool check(int* counting,int input)
{
	while (input != 0)
	{
		int num1 = input % 10;
		if (counting[num1] == 0)
			return false;
		else
			counting[num1]--;
		input /= 10;
	}
	return true;
	
}

int solution(string numbers) {
	int answer = 0;
	size_t strsize = numbers.size();
	int tempcount[10] = { 0, };
	for (size_t i = 0; i < strsize; ++i)
	{
		counting[numbers[i] - 48]++;
	}
	int maxsize = pow(10, strsize);
	Eratos(maxsize);
	for (int i = 2; i < maxsize; ++i)
	{
		if (PrimeArray[i])
		{
			memcpy(tempcount, counting,sizeof(counting));
			answer += check(tempcount,i);
		}
	}
	return answer;
}
```
