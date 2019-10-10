#include<stdio.h>
#include<stdlib.h>


int main()
{
	int T;
	scanf("%d", &T);
	getchar();

	for (int i = 0; i < T; ++i)
	{
		int N;
		scanf("%d", &N);
		getchar();
		double result = 0;
		double* p = (double*)calloc(sizeof(double),N);
		int* x = (int*)calloc(sizeof(int),N);

		for (int j = 0; j < N; ++j)
		{
			scanf("%lf %d", &p[j], &x[j]);
			printf("%lf %d\n", p[j], x[j]);
			result += p[j] * x[j];
		}
		printf("%.5lf\n", result);


		free(p);
		free(x);
	}


	return 0;
}