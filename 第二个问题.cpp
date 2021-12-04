//思路，将问题拆分成几个函数搭建起来，逐个突破。
#include <stdio.h>
#include <math.h>
#include <stdlib.h>//声明头文件

void show(void);//打印函数
int check(int queen_id);//检查函数
int eight_queen(int n);//八皇后函数

int queens[8];//数组，默认不同皇后在不同行。
//注：queens【n】表示第几列，n表示第几行
int sum = 0;//初始化，总共摆放的种数。
int max = 8;//最大值为8，不能超过

void show(void)//打印函数
{
	printf("\n第%2d种\n", sum);
	for (int row = 0; row < max; row++)//行循环
	{
		for (int column = 0; column < max; column++)//列循环
		{
			if (queens[row] == column)//八皇后函数中已经将赋值，见44行。
				printf("Q");//皇后所在位置
			else
				printf("*");
		}
		printf("\n");//每打印一行都要跳一行。
	}
}
int check(int n)//标记当前列
{
	for (int row = 0; row < n; row++)//一行一行开始
	{
		if (queens[row] == queens[n] || abs(queens[n] - queens[row]) == abs(n - row))//检查每列，对角线是否有皇后相互攻击
			return 0;//相互攻击就为假
	}
	return 1;//不相互攻击就为真，继续执行。
}
int eight_queen(int n)//n表示第n行
{
	if (n < max)//递归结束的条件
	{
		for (int cur_col = 0; cur_col < max; cur_col++)//当前列
		{
			queens[n] = cur_col;//将当前列（位置）赋值给第n+1行皇后（第n+1个皇后）
			if (check(n))//检查第n个皇后，即第n行皇后是否与前面的皇后发生冲突。
				eight_queen(n + 1);//可以就递归，然后检查下一个皇后直到最后一个。
		}
		return 0;
	}
	else
	{
		sum++;//每完成一种摆法就sum+1
		show();//并将其打印出来
	}
}
int main()
{
	eight_queen(0);//递归，从第一行开始
	printf("一共有%d种", sum);
	return 0;
}