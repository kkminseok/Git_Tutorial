#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAX = 101;

bool MAP[MAX][MAX] = { false, };
bool v[MAX][MAX] = { false, };

int n, m;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cheese = 0;
int hour = 0;

void printMAP()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << MAP[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> MAP[i][j];
			if (MAP[i][j])
				++cheese;
		}
	}
}

void Solve()
{
	queue<pair<int,int>> q;
	while (cheese != 0)
	{
		memset(v, false, sizeof(v));
		q.push(make_pair(0, 0));

		//���� �ܺ� ������� �� check ���·� ����
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; ++k)
			{
				int newX = x + dx[k];
				int newY = y + dy[k];
				if (0 <= newX && newX < n && 0 <= newY && newY < m && MAP[newX][newY] == false && v[newX][newY] == false)
				{
					v[newX][newY] = true;
					q.push(make_pair(newX, newY));
				}
			}
		}
		//������� �� check�� �ٲ� ���� ���鼭 ġ�����

		//q�� �� �����ϰ��̹Ƿ�
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (MAP[i][j] == true)
				{
					//��ȭ�¿�˻�
					int count = 0;
					for (int k = 0; k < 4; ++k)
					{
						int newX = i + dx[k];
						int newY = j + dy[k];
						if (0 <= newX && newX < n && 0 <= newY && newY < m && v[newX][newY] == true && MAP[newX][newY]==false)// �� �����̰� �̹� �ܰ� �� ������
						{
							++count;
						}
					}
					if (count >= 2)//���� ġ��
					{
						MAP[i][j] = false;
						--cheese;
					}
				}
			}
		}
		
		++hour;
		printMAP();
	}
	cout << hour;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
}