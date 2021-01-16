#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n=0;
	int result = 0;
	cin >> n;

	int* arr = new int[n + 1];
	int* dpup = new int[n + 1];
	int* dpdown = new int[n + 1];

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		dpup[i] = 1;
		dpdown[i] = 1;
	}
	
	
	for (int i = 2; i <= n; ++i)
	{
		int maxnum = 0;
		for (int j = i - 1; j > 0; --j)
		{
			//up ����
			//up ���� ���� �ڽź��� ���� ���� �� ã�� �� dp+1 up������ �ؾ���. 
			if (arr[i] > arr[j])
			{
				if (maxnum < dpup[j])
					maxnum = dpup[j];
			}
		}
		dpup[i] = maxnum + 1;
		maxnum = 0;
		int temp = 0;
		for (int j = i - 1; j > 0; --j)
		{
			//dpdown�� �ڱ⺸�� ū ������ up,down���ؼ� ū ��
			if (arr[i] < arr[j])
			{
				if (maxnum < max(dpdown[j], dpup[j]))
					maxnum = max(dpdown[j], dpup[j]);
					
			}
		}
		dpdown[i] = maxnum + 1;
		if (result < dpup[i])
			result = dpup[i];
		else if (result < dpdown[i])
			result = dpdown[i];
	}
	/*for (int i = 0; i <= n; ++i)
	{
		cout << dpup[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i <= n; ++i)
		cout << dpdown[i] << " ";*/
	cout << result;
	
	return 0;
}