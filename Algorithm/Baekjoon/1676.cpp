#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

//5�� ����� 0�� ������ �þ. maybe
int main()
{
	
	int n;
	int result = 0;
	scanf("%d", &n);
	if (n == 0)
		result = 1;
	else
		result = n / 5 + n/25 + n/125;
	printf("%d", result);
	
	
}