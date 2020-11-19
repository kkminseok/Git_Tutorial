#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<deque>
int main()
{
	using namespace std;
	int n, k;
	char c[500001];
	deque<char> dq;
	scanf("%d %d", &n, &k);
	scanf("%s", c);

	for (int i = 0; i < n; ++i)
	{
		while (k && !dq.empty() && dq.back() < c[i])
		{
			dq.pop_back();
			--k;
		}
		dq.push_back(c[i]);
	}
	for (int i = 0; i < dq.size() - k; ++i)
		printf("%c", dq[i]);
	
}