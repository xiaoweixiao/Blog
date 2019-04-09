#include <stdio.h>

//无聊的模拟题
int cvrt(int y, int m, int c, int w, bool B){//输入哪年哪月第几个星期几，以及正数还是倒数，输出几号
	int d,
		week,
		i;
	if (m == 1)
	{
		m = 13;
		y--;
	}//公式要求1月、2月要转为上一年13、14月
	if (m == 2)
	{
		m = 14;
		y--;
	}
	i = 0;

	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--))
	{
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//蔡勒公式
		if (week + 1 == w)
			++i;
		if (i == c)
			break;
	}
	return d;
}

int main(void){
	int y;
	while (scanf("%d", &y) != EOF)
	{
		printf("%d-01-01\n", y);
		printf("%d-01-%02d\n", y, cvrt(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, cvrt(y, 2, 3, 1, 1));
		printf("%d-05-%02d\n", y, cvrt(y, 5, 1, 1, 0));//倒数
		printf("%d-07-04\n", y);
		printf("%d-09-%02d\n", y, cvrt(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, cvrt(y, 11, 4, 4, 1));
		printf("%d-12-25\n\n", y);
	}
	return 0;
}

