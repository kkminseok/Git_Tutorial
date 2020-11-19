#include<string>
#include<iostream>	

int main()
{
	using namespace std;

	string str;
	getline(cin,str);
	string output = "UCPC";
	int idx = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == output[idx])
			++idx;
		if (idx == 4)
			break;
	}
	if (idx == 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";
}