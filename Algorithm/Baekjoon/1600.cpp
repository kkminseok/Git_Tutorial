#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAX = 201;
int MAP[MAX][MAX] = { 0, };
bool v[MAX][MAX][32] = { false, };
int W, H, K;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int horsex[8] = { -1,-2,-2,-1,1,2, 2, 1 };
int horsey[8] = { -2,-1, 1, 2,2,1,-1,-2 };

void Input()
{
	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j <W; ++j)
			cin >> MAP[i][j];
	}
}

int Solve()
{
	//BFS
	//ÁÂÇ¥ °ª, k Ä«¿îÆ® °ª, ÀÌµ¿È½¼ö
	memset(v, false, sizeof(v));
	queue < pair<pair<int, int>, pair<int,int>>> q;

	q.push(make_pair(make_pair(0, 0), make_pair(0,0)));
	v[0][0][0] = true;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int horse = q.front().second.first;
		int result = q.front().second.second;
		//cout << "x : " << x << "y : " << y << "horse" <<horse<<"result : "<<result<< '\n';
		if (x == (H - 1) && y == (W - 1))
			return result;
		q.pop();
		//¸»Ã³·³ ¶Ù±â
		if (horse < K)
		{
			for (int k = 0; k < 8; ++k)
			{
				int newX = x + horsex[k];
				int newY = y + horsey[k];
				//cout << newX << " " << newY << '\n';
				if (0 <= newX && newX < H && 0 <= newY && newY < W && v[newX][newY][horse+1] == false && MAP[newX][newY] !=1)
				{
					q.push(make_pair(make_pair(newX, newY),make_pair(horse+1, result+1)));
					v[newX][newY][horse+1] = true;
				}
			}
		}
		//¸»Ã³·³ ¾È¶Ù±â
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];

			if (0 <= newX && newX < H && 0 <= newY && newY < W && v[newX][newY][horse] == false && MAP[newX][newY] != 1)
			{
				q.push(make_pair(make_pair(newX, newY), make_pair(horse, result + 1)));
				v[newX][newY][horse] = true;
			}
		}
	}
	return -1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	cout<<Solve();
	
	
	return 0;
}