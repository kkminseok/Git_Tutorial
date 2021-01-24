#include<iostream>
#include<queue>
#include<cstring>
using namespace std;


char MAP[13][7] = { '0' };
bool v[13][6] = { false, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


void Input() {
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 6; ++j)
			cin >> MAP[i][j];
	}
}

bool BFS(int i,int j,char remove)
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> countPuyo;
	q.push(make_pair(i, j));
	countPuyo.push(make_pair(i, j));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < 12 && 0 <= newY && newY < 6 && MAP[newX][newY] == remove && v[newX][newY] == false)
			{
				countPuyo.push(make_pair(newX, newY));
				v[newX][newY] = true;
				q.push(make_pair(newX, newY));
			}
		}

	}
	if (countPuyo.size() >= 4)
	{
		while (!countPuyo.empty())
		{
			int x = countPuyo.front().first;
			int y = countPuyo.front().second;
			countPuyo.pop();
			MAP[x][y] = '.';
		}
		return true;
	}
	return false;
}

void swap(int start, int end,int col)
{
	int lange = start - end;
	//cout << "start " << start << " end " << end << " col" << col << '\n';
	for (int i = 0; i < lange; ++i)
	{
		char temp = MAP[start][col];
		MAP[start][col] = MAP[end][col];
		MAP[end][col] = temp;
		--start;
		--end;
		if (end < 0)
			break;
	}
}

void Down() {
	
	bool check = false;

	for (int i = 0; i < 6; ++i)
	{
		int start = 13;
		for (int j = 11; j >= 0; --j)
		{
			if (MAP[j][i] == '.' && !check )
			{
				start = j;
				check = true;
			}
			if (MAP[j][i]!='.' && start !=13)//어디선가  걸리긴했고 문자를 만낫을 때
			{
				int end = j;// 걸린곳의 높이
				//cout << "start" << start << "end" << end <<"i"<<i<< '\n';
				swap(start, end,i);
				check = false;
				j = 11;
				start = 13;
				continue;
				
			}
		}
		check = false;
	}
}
void printMAP()
{
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 6; ++j)
			cout << MAP[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';
}
void Solve() {
	
	int result = 0;
	bool check = false;
	bool counting = true;
	while (counting)
	{
		check = false;
		counting = false;
		memset(v, false, sizeof(v));
		for (int i = 0; i < 12; ++i) {

			for (int j = 0; j < 6; ++j) {
				if (MAP[i][j] != '.' && v[i][j] == false)
				{
					v[i][j] = true;
					check = BFS(i, j, MAP[i][j]);
					if (check == true)
						counting = true;
				}
			}
		}
		if (counting)
			++result;
		//땡겨줌
		//printMAP();
		Down();
		//cout << "땡긴 후\n";
		//printMAP();
	}
	cout << result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();

	return 0;
}