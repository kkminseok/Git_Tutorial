//10:50
#include<iostream>
#include<deque>
using namespace std;

const int MAX = 101;

int N;
int MAP[MAX][MAX] = { 0, };
int applecount;
int movecount = 0;
typedef struct _move
{
	int second;
	char way;
}movez;
movez* movearr;


int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void Input()
{
	cin >> N;
	cin >> applecount;
	for (int i = 0; i < applecount; ++i)
	{
		int x = 0;
		int y = 0;
		cin >> x >> y;
		MAP[x - 1][y - 1] = 1;//0,0 ���� ����

	}
	
	cin >> movecount;
	movearr = new movez[movecount];
	for (int i = 0; i < movecount; ++i)
	{
		cin >> movearr[i].second >> movearr[i].way;
	}
}

int Solve()
{
	//deque�� ���� ��ġ�� ����.
	deque<pair<int, int>> dq;
	int snakex = 0;
	int snakey = 0;
	dq.push_back(make_pair(snakex, snakey));
	int direction = 0;
	int result = 0;
	int index = 0;
	MAP[snakex][snakey] = 2;
	while (1)
	{
		//�˻�
		if (result == movearr[index].second)
		{
			if (movearr[index].way == 'D')
				direction = (direction + 1) % 4;
			else
			{
				direction--;
				if (direction < 0)
					direction = 3;
			}
			++index;
		}
		snakex += dx[direction];
		snakey += dy[direction];
		if (0 <= snakex && snakex < N && 0 <= snakey && snakey < N)
		{
			//���� �ε���
			if (MAP[snakex][snakey] == 2)
				return result;
			else
			{
				//����� ����.
				if (MAP[snakex][snakey] == 1)
				{
					//�Ӹ��� ������
					dq.push_back(make_pair(snakex, snakey));

				}
				else
				{
					//��� ����.
					int tempx = dq.front().first;
					int tempy = dq.front().second;
					MAP[tempx][tempy] = 0;
					dq.pop_front();
					dq.push_back(make_pair(snakex, snakey));

				}
				MAP[snakex][snakey] = 2;
			}
			
		}
		else
		{
			return result;
		}
		/*for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				cout << MAP[i][j] << ' ';
			cout << '\n';
		}*/
		++result;
	}
	
}
void Solution()
{
	Input();
	cout<<Solve()+1<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}