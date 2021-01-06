#include<iostream>// �����
#include<queue>// BFS
#include<cmath>// trunc
#include<cstring>// memset
using namespace std;

const int MAX = 51;
int MAP[MAX][MAX];
bool v[MAX][MAX];

int n, l, r;
//���
int counting = 0;

//��ǥ �̵��� ����
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Input()
{
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> MAP[i][j];
	}
}
//�߰� ���
void printarr()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << MAP[i][j] << ' ';
		cout << '\n';
	}

}

void BFS()
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;// ���� �ٲ��� �� �ʿ�
	// ���� ����
	int num;
	//���� ū �ݺ����� ������ ���� ����
	int temp;
	//Ư�� ������ ��í�� couting�� �� �ֵ��� �ϴ� ����
	bool check = false;
	//���� ����
	int add;
	do {
		//���� ���� ����
		temp = counting;
		//�ʱ�ȭ�� �����ָ� ���ѷ��� ����.
		check = false;

		//�̰� ���ִ� ������ MAP��� ������ �����ϴ� ��ǥ�� ������ �𸣹Ƿ� ��������
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				//�̹� queue�� ���� ���̸� skip
				if (v[i][j] == false)
				{
					//�ϴ� �ְ��� �Ŷ� ȿ�������� ������ �����ϰԴ� �����ϱ� ����
					q.push(make_pair(i, j));
					num = 1;
					add = 0;

					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						v[x][y] = true;
						q.pop();
						//�ϴ� ����
						add += MAP[x][y];
						//�ϴ� ����.
						q2.push(make_pair(x, y));
						//������ ���鼭 ���ǿ� �´°� queue�� ����.
						for (int k = 0; k < 4; ++k)
						{
							int newX = dx[k] + x;
							int newY = dy[k] + y;
							if (0 <= newX && newX < n && 0 <= newY && newY < n && v[newX][newY] == false)
							{
								//���� ���� ���밪�� �־��� ���Ǻ��� <=,>=
								int absnum = abs(MAP[x][y] - MAP[newX][newY]);
								if (absnum >= l && absnum <= r)// ���밪�� �����ȿ� ����.
								{
									++num;
									q.push(make_pair(newX, newY));
									v[newX][newY] = true;
								}
							}
						}
					}
					//cout << add <<" "<< num << '\n';
					//1�� �̻��� ��ǥ�� �������� �� �α��̵��� �Ͼ ��.
					if (num > 1)
						check = true;
					//�ӽ� ť�� q2�� �� ������ �� ��������. 
					while (!q2.empty())
					{
						int x = q2.front().first;
						int y = q2.front().second;
						q2.pop();
						MAP[x][y] = trunc(add / num);
					}
				}
			}
		}
		//���� �α��̵��� ���� �ʱ�ȭ
		memset(v, false, sizeof(v));
		//�α��̵��� �Ͼ�� �� üũ
		if (check)
			++counting;
		//printarr();
		//cout << '\n' << counting<<'\n';
	} while (counting != temp);
	cout << counting;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	BFS();


	return 0;
}