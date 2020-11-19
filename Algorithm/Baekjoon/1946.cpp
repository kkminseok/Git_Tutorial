#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
class attendant
{
public:
	int file;
	int view;
	bool operator<(attendant& a)
	{
		if (this->file == a.file)
			return this->view < a.view;
		else
			return this->file < a.file;
	}
};


int main()
{
	using namespace std;
	int T;
	int N;
	int minview =100001;
	int count = 0;
	scanf("%d", &T);
	getchar();
	for (int i = 0; i < T; ++i)
	{
		scanf("%d", &N);
		getchar();
		attendant* arr = new attendant[N];
		for (int j = 0; j < N; ++j)
		{
			scanf("%d %d", &arr[j].file, &arr[j].view);
		}
		sort(arr, arr + N);
		
		//비교하여 탈락
		for (int j = 0; j < N; ++j)
		{
			if ( (arr[j].view < minview))
			{
				minview = arr[j].view;
				++count;
			}
		}
		cout <<count << endl;
		count = 0;
		minview = 100001;
		delete arr;
	}
}