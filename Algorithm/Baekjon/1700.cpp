#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int* arr = new int[k];
	int muti[101] = { 0, };
	int count = 0;
	int result = 0;
	for (int i = 0; i < k; ++i)
		scanf("%d", &arr[i]);
	for (int i = 0; i < k; ++i)
	{
		bool pluggend = false;
		for (int j = 0; j < n; ++j)
		{
			if (arr[i] == muti[j])
			{
				pluggend = true;
				break;
			}
		}
		if (pluggend == true)
			continue;

		for (int j = 0; j < n; ++j)
		{
			if (!muti[j])
			{
				muti[j] = arr[i];
				pluggend = true;
				break;
			}
		}
		if (pluggend == true)
			continue;
		// 바꿔주는 알고리즘
		int idx, deviceidex = -1;
		for (int j = 0; j < n; ++j)
		{
			int lastindex = 0;
			for (int r = i + 1; r < k; ++r)
			{
				if (muti[j] == arr[r])
					break;
				lastindex++;
			}

			if (lastindex > deviceidex)
			{
				idx = j;
				deviceidex = lastindex;
			}
		}
		++result;
		muti[idx] = arr[i];
	}
	printf("%d", result);
	delete arr;
}