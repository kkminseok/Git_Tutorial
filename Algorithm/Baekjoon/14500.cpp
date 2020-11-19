#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

const int MAX = 500;

typedef struct
{
	int y, x;
}Dir;

Dir movexy[4] = { {1,0}, {-1,0},{0,1},{0,-1} };
bool visited[MAX][MAX];
int cell[MAX][MAX];
int n, m;
int DFS(int y, int x, int cnt)
{
	if (cnt == 4)
		return cell[y][x];
	int sum = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nextY = y + movexy[i].y;
		int nextX = x + movexy[i].x;

		if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m && !visited[nextY][nextX])
		{
			visited[nextY][nextX] = true;
			sum = std::max(sum, cell[y][x] + DFS(nextY, nextX, cnt + 1));
			visited[nextY][nextX] = false;
		}
	}
	return sum;
}
int middle(int y, int x)
{
	int result = 0;

	//ㅗ (현재 좌표 ㅡ의 가운데)

	if (y >= 1 && x >= 1 && x < m - 1)

		result = std::max(result, cell[y][x - 1] + cell[y][x] + cell[y - 1][x] + cell[y][x + 1]);

	//ㅏ (현재 좌표 ㅣ의 가운데)

	if (y >= 1 && y < n - 1 && x < m - 1)

		result = std::max(result, cell[y - 1][x] + cell[y][x] + cell[y][x + 1] + cell[y + 1][x]);

	//ㅜ (현재 좌표 ㅡ의 가운데)

	if (y >= 0 && y < n - 1 && x < m - 1)

		result = std::max(result, cell[y][x - 1] + cell[y][x] + cell[y + 1][x] + cell[y][x + 1]);

	//ㅓ (현재 좌표 ㅣ의 가운데)

	if (y >= 1 && y < n - 1 && x >= 1)

		result = std::max(result, cell[y - 1][x] + cell[y][x] + cell[y][x - 1] + cell[y + 1][x]);

	return result;




}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &cell[i][j]);
		}
	}
	int result = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			visited[i][j] = true;
			result = std::max(result, DFS(i, j, 1));
			result = std::max(result, middle(i, j));
			visited[i][j] = false;
		}
	}
	printf("%d\n", result);
}