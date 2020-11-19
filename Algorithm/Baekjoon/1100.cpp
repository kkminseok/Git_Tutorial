#include<string>
#include<iostream>
int main()
{
	using namespace std;
	const int size = 8;
	int out = 0;
	string chess[size];
	for (int i = 0; i < size; ++i)
	{
		cin >> chess[i];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (i % 2 == 0 && j % 2 == 0 && chess[i][j]=='F')
				++out;
			if (i % 2 == 1 && j % 2 == 1 && chess[i][j]=='F')
				++out;
		}
	}

	cout << out;
}