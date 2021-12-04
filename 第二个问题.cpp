//˼·���������ֳɼ�����������������ͻ�ơ�
#include <stdio.h>
#include <math.h>
#include <stdlib.h>//����ͷ�ļ�

void show(void);//��ӡ����
int check(int queen_id);//��麯��
int eight_queen(int n);//�˻ʺ���

int queens[8];//���飬Ĭ�ϲ�ͬ�ʺ��ڲ�ͬ�С�
//ע��queens��n����ʾ�ڼ��У�n��ʾ�ڼ���
int sum = 0;//��ʼ�����ܹ��ڷŵ�������
int max = 8;//���ֵΪ8�����ܳ���

void show(void)//��ӡ����
{
	printf("\n��%2d��\n", sum);
	for (int row = 0; row < max; row++)//��ѭ��
	{
		for (int column = 0; column < max; column++)//��ѭ��
		{
			if (queens[row] == column)//�˻ʺ������Ѿ�����ֵ����44�С�
				printf("Q");//�ʺ�����λ��
			else
				printf("*");
		}
		printf("\n");//ÿ��ӡһ�ж�Ҫ��һ�С�
	}
}
int check(int n)//��ǵ�ǰ��
{
	for (int row = 0; row < n; row++)//һ��һ�п�ʼ
	{
		if (queens[row] == queens[n] || abs(queens[n] - queens[row]) == abs(n - row))//���ÿ�У��Խ����Ƿ��лʺ��໥����
			return 0;//�໥������Ϊ��
	}
	return 1;//���໥������Ϊ�棬����ִ�С�
}
int eight_queen(int n)//n��ʾ��n��
{
	if (n < max)//�ݹ����������
	{
		for (int cur_col = 0; cur_col < max; cur_col++)//��ǰ��
		{
			queens[n] = cur_col;//����ǰ�У�λ�ã���ֵ����n+1�лʺ󣨵�n+1���ʺ�
			if (check(n))//����n���ʺ󣬼���n�лʺ��Ƿ���ǰ��Ļʺ�����ͻ��
				eight_queen(n + 1);//���Ծ͵ݹ飬Ȼ������һ���ʺ�ֱ�����һ����
		}
		return 0;
	}
	else
	{
		sum++;//ÿ���һ�ְڷ���sum+1
		show();//�������ӡ����
	}
}
int main()
{
	eight_queen(0);//�ݹ飬�ӵ�һ�п�ʼ
	printf("һ����%d��", sum);
	return 0;
}