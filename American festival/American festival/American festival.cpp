#include <stdio.h>

//���ĵ�ģ����
int cvrt(int y, int m, int c, int w, bool B){//�����������µڼ������ڼ����Լ��������ǵ������������
	int d,
		week,
		i;
	if (m == 1)
	{
		m = 13;
		y--;
	}//��ʽҪ��1�¡�2��ҪתΪ��һ��13��14��
	if (m == 2)
	{
		m = 14;
		y--;
	}
	i = 0;

	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--))
	{
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//���չ�ʽ
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
		printf("%d-05-%02d\n", y, cvrt(y, 5, 1, 1, 0));//����
		printf("%d-07-04\n", y);
		printf("%d-09-%02d\n", y, cvrt(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, cvrt(y, 11, 4, 4, 1));
		printf("%d-12-25\n\n", y);
	}
	return 0;
}

