#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[50001] = { 0,1,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <=n;++i)
	{
		if ((int)sqrt(i) * (int)sqrt(i) == i) 
			dp[i] = 1;//Á¦°ö ¼ö´Â 1
		else
			dp[i] = 500;
	}
	
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <=(int)sqrt(j); ++k)
			{
				dp[j] = min(dp[j], dp[k*k] + dp[j - k * k]);
			}
		}
	}
	
	cout << dp[n];
	

}