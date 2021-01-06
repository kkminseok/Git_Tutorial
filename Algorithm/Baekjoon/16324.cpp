#include<iostream>// 입출력
#include<queue>// BFS
#include<cmath>// trunc
#include<cstring>// memset
using namespace std;

const int MAX = 51;
int MAP[MAX][MAX];
bool v[MAX][MAX];

int n, l, r;
//결과
int counting = 0;

//좌표 이동을 위한
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
//중간 출력
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
	queue<pair<int, int>> q2;// 값을 바꿔줄 때 필요
	// 구역 갯수
	int num;
	//제일 큰 반복문을 끝내기 위한 변수
	int temp;
	//특정 조건을 거챠야 couting할 수 있도록 하는 변수
	bool check = false;
	//먼저 선언
	int add;
	do {
		//이전 값을 저장
		temp = counting;
		//초기화를 안해주면 무한루프 돈다.
		check = false;

		//이걸 해주는 이유는 MAP어디에 조건을 만족하는 좌표가 있을지 모르므로 순차접근
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				//이미 queue에 들어갔던 것이면 skip
				if (v[i][j] == false)
				{
					//일단 넣고보는 거라 효율적이지 않지만 복잡하게는 생각하기 힘듬
					q.push(make_pair(i, j));
					num = 1;
					add = 0;

					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						v[x][y] = true;
						q.pop();
						//일단 더함
						add += MAP[x][y];
						//일단 넣음.
						q2.push(make_pair(x, y));
						//범위를 돌면서 조건에 맞는건 queue에 넣음.
						for (int k = 0; k < 4; ++k)
						{
							int newX = dx[k] + x;
							int newY = dy[k] + y;
							if (0 <= newX && newX < n && 0 <= newY && newY < n && v[newX][newY] == false)
							{
								//메인 조건 절대값이 주어진 조건보다 <=,>=
								int absnum = abs(MAP[x][y] - MAP[newX][newY]);
								if (absnum >= l && absnum <= r)// 절대값이 범위안에 들어옴.
								{
									++num;
									q.push(make_pair(newX, newY));
									v[newX][newY] = true;
								}
							}
						}
					}
					//cout << add <<" "<< num << '\n';
					//1개 이상의 좌표에 접근했을 시 인구이동이 일어난 것.
					if (num > 1)
						check = true;
					//임시 큐인 q2에 든 값들을 다 수정해줌. 
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
		//다음 인구이동을 위해 초기화
		memset(v, false, sizeof(v));
		//인구이동이 일어났는 지 체크
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