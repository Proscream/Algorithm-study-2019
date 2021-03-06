
#include <iostream>
using namespace std;
#include<algorithm>
#include<thread>

int n;
int board[100][100]; //보드생성
int row_i=0;
int col_i=0;

//jump 함수
bool jump(int y, int x)
{
	if (y >= n || x >= n) //판을 벗어나면 stop
	{
		return false;
	 }
	if (y == n - 1 && x == n - 1) //도착하면 stop
	{
		return true;
	}
	if (board[y][x] == 0) //0일 경우 더이상 갈 수 없다
	{
		return false;
	}
	row_i = x;
	col_i = y;
	int jumpSize = board[y][x];
	return (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

//result 부터 다시 되돌아가면서 만나면 stop
bool jumpReverse(int y, int x)
{
	if (y >= n || x >= n)
	{
		return false;
	}
	if (row_i==x && col_i==y)
	{
		return true;
	}
	if (y == 0 && x == 0)
	{
		return true;
	}
	int jumpSize = board[y][x];
	return (jumpReverse(y - jumpSize, x) || jumpReverse(y, x - jumpSize));
}
int main()
{
	int nGameCount; //게임 횟수 카운트
	
	int val,row,col;

	cin >> nGameCount;
	
	for (int i = 0; i < nGameCount; i++)
	{
		cin >> n;
		
		
		for (row = 0; row < n; row++)
		{
			for (col = 0; col < n; col++)
			{
				cin >> val;
				board[row][col] = val;
			}
		}
		//재귀 시작
		bool result=jump(0, 0);
		bool result_reverse = jumpReverse(n - 1, n - 1);
		
		if (result)
		{
			cout << "YES"<<endl;
		}
		else
		{
			cout << "NO"<<endl;
		}
	}
   
}

