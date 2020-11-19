#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
int main()
{
	using namespace std;
	int n, endindex,j,startindex=0;
	int input,result=0;
	int size = 0;
	scanf("%d %d", &n, &size);
	endindex = size - 1;
	getchar();
	scanf("%d", &j);
	getchar();
	for (int i = 0; i < j; ++i)
	{
		scanf("%d", &input);
		input--;
		if (startindex <= input && input <= endindex)
			continue;
		else if (input > endindex) // µÚ¿¡ ¶³¾îÁü
		{
			result += input - endindex;
			endindex = input;
			startindex = endindex - size+1;
		}
		else if (input < startindex)// ¾Õ¿¡ ¶³¾îÁü
		{
			result += startindex - input;
			startindex = input;
			endindex = startindex + size - 1;
		}

	}
	cout << result;

}