#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm> //max
using namespace std;

const int MAX = 51;

int MAP[MAX][MAX] = { 0, };
int temp[MAX][MAX];
bool v[MAX][MAX] = { false, };
queue<pair<pair<int, int>, int>> q;
int arrx[11] = { 0, };
int arry[11] = { 0, };

int N, M;
int counting = 0;
int result = 987654321;

//좌표이동
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Input() {
	cin >> N >> M;
	int temp = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j) {
			cin >> temp;
			if (temp == 0)
				++counting;
			MAP[i][j] = temp;
		}
	}

}
void printMAP()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << temp[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';
}

void BFS()
{
	memcpy(temp, MAP, sizeof(MAP));
	memset(v, false, sizeof(v));
	int tempresult = 0;
	int tempcounting = counting;
	for (int i = 0; i < M; ++i)
	{
		//cout << arrx[i] << arry[i] << "\n";
		q.push(make_pair(make_pair(arrx[i], arry[i]), 0));
		v[arrx[i]][arry[i]] = true;
	}

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int minu = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < N && 0 <= newY && newY < N && v[newX][newY] == false && temp[newX][newY] != 1)
			{
				if (temp[newX][newY] == 0)
				{
					--tempcounting;
					if (tempcounting == 0)
					{
						//cout << "break" << minu+1 << '\n';
						result = min(result, minu + 1);
					}
				}
				temp[newX][newY] = 2;
				q.push(make_pair(make_pair(newX, newY), minu + 1));
				v[newX][newY] = true;
			}
		}

		//printMAP();
	}
	//printMAP();

}

void virus(int x, int y, int cnt) {
	if (cnt == M) {
		BFS();
		return;
	}
	bool check = false;
	for (int i = x; i < N; ++i)
	{
		int j;
		if (check == false)
		{
			j = y;
			check = true;
		}
		else
			j = 0;
		for (; j < N; ++j)
		{
			if (MAP[i][j] == 2)
			{
				MAP[i][j] = 3;
				//cout << i << " " << j <<" "<<cnt<< "\n";
				arrx[cnt] = i;
				arry[cnt] = j;
				virus(i, j, cnt + 1);
				MAP[i][j] = 2;
			}
		}
	}
}

void Solve() {
	//바이러스 선별 먼저
	//virus
	//복사 해두기
	if (counting == 0)
		cout << 0 << '\n';
	else
	{
		virus(0, 0, 0);
		if (result == 987654321)
			result = -1;
		cout << result;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();


}