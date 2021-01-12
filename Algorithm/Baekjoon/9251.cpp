#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int const MAX = 1001;
int LCS[MAX][MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input1, input2;
	cin >> input1 >> input2;

	int result = 0;

	//LCS¸¸µé±â
	for (int i = 1; i < input1.size() + 1; ++i)
	{
		for (int j = 1; j < input2.size() + 1; ++j)
		{
			if (input1[i - 1] == input2[j - 1])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else
			{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
			result = max(result, LCS[i][j]);
		}
	}
	cout << result;

	return 0;
}
/*
XMJYAUZ
MZJAWXU

*/