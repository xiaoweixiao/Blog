#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include <stdio.h>
#include<stdlib.h>

struct Date
{
	int year;
	int month;
};

struct Reader
{
	char name[15];
	char addr[20];
	char phone[15];
	int journal_num;//�ڿ����
	int sub_num;//���ķ���
	struct Date d_begin;//������
	struct Date d_end;//ֹ������
	int money;
};
struct Journal{
	int journal_num;
	char name[20];
	int times;//ÿ���ڿ���
	int money;//ÿ�ڵ���
};

struct Date get_now_date_()//��ȡ���ڵ�����
{
	time_t now;
	struct tm *tm_now;
	time(&now);
	tm_now = localtime(&now);
	//printf("now datetime: %d-%d-%d\n",tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday) ;��ǰ����
	struct Date today;
	today.year = tm_now->tm_year + 1900;
	today.month = tm_now->tm_mon + 1;
	return today;
}
int count_month_of_data(struct Date d1, struct Date d2)//������������֮�������
{
	int ret = 0;
	while (d1.year != d2.year||d1.month != d2.month)
	{
		ret++, d1.month++;
		if (d1.month == 13)
		{
			d1.month = 1;
			d1.year++;
		}
	}
	return ret;
}
void menu()
{
	printf("1.�����¶��Ļ�		  	        2.�����ڶ�����Ϣ\n");
	printf("3.��Ч�ڿ�������\t	        4.ÿ���ڿ�������\n");
	printf("5.�ȵ��ڿ����а�\t\t        6.���ڶ���������Ȼû����\n");
	printf("������ѡ��>");
}
void increase_new_reader()
{
	FILE *Reader, *Mag;

	if ((Mag = fopen("MAG.txt", "r")) == NULL)
		printf("���ڿ��ļ�����\n"); // ���ļ�
	if ((Reader = fopen("Reader.txt", "a+")) == NULL)
		printf("�򿪶����ļ�����\n"); // ���ļ�

	struct Journal journal[10];
	struct Journal one;
	int i = 0;//�����±�
	while (fscanf(Mag, "%d%s%d%d", &one.journal_num, &one.name, &one.times, &one.money) != EOF)
		journal[i++] = one;
	struct Reader reader;

	printf("�����붩��������:");
	scanf("%s", &reader.name);

	printf("�����붩����סַ:");
	scanf("%s", &reader.addr);

	printf("�����붩���ߵ绰:");
	scanf("%s", &reader.phone);

	printf("�����붩���ڿ���:");
	scanf("%d", &reader.journal_num);

	printf("�����붩�ķ���:");
	scanf("%d", &reader.sub_num);

	printf("�����붩������:");
	scanf("%d", &reader.d_begin.year);

	printf("�����붩������:");
	scanf("%d", &reader.d_begin.month);

	printf("�����붩��ֹ����:");
	scanf("%d", &reader.d_end.year);

	printf("�����붩��ֹ����:");
	scanf("%d", &reader.d_end.month);

	//���㶩���߸�֧������Ǯ��
	int n = count_month_of_data(reader.d_begin, reader.d_end);//���ļ�����
	reader.money = n*journal[reader.journal_num].times*journal[reader.journal_num].money;//��*ÿ�¿���*ÿ�ε���

	fprintf(Reader, "%s\t%s\t\t%s\t%d\t%d\t%d %d\t%d %d\t%d\n", reader.name, reader.addr, reader.phone,
		reader.journal_num, reader.sub_num,
		reader.d_begin.year, reader.d_begin.month, reader.d_end.year, reader.d_end.month, reader.money);
	fclose(Reader); // �ر��ļ�ָ��
	fclose(Mag);
	printf("����µĶ��Ļ��ɹ���");
	system("pause");
}

int update_reader_inf()//������Ч��־������
{
	int ret = 0;
	 struct Date today = get_now_date_();
	 struct Reader readers[30];//��Ҫ��������û����Ȱ��û���Ϣȫ����ȡ������ʹ������洢�û���Ϣ
	 FILE* fp = fopen("Reader.txt","r+");
	 FILE* out = fopen("Out.txt","a+");
	 if (out == NULL)
		 puts("���ļ�����\n");
	 struct Reader one;//���ж�ȡ�洢�ڽṹ����
	 int i = 0;//�����±�
	 while (fscanf(fp, "%s%s%s%d%d%d%d%d%d%d", &one.name, &one.addr, &one.phone, &one.journal_num,&one.sub_num,
		 &one.d_begin.year, &one.d_begin.month, &one.d_end.year, &one.d_end.month, &one.money) != EOF)
		 readers[i++] = one;


	 //�������ų������û�����д���ļ�,�ܹ���Ҫд��i��reader��Ϣ
	 fp = fopen("Reader.txt", "w+");
	 fseek(fp, 0, SEEK_SET);
	 int j = 0;//��һ�α���������±�
	 for (; j < i;j++)
	 {
		 if ((readers[j].d_end.year> today.year) ||
			 ((readers[j].d_end.year == today.year) && (readers[j].d_end.month> today.month)))//�û�����ʱ��δ����д��
		 {
			 ret++;
			 fprintf(fp, "%s\t%s\t\t%s\t%d\t%d\t%d %d\t%d %d\t%d\n", readers[j].name, readers[j].addr, readers[j].phone,
				 readers[j].journal_num, readers[j].sub_num,
				 readers[j].d_begin.year, readers[j].d_begin.month,
				 readers[j].d_end.year, readers[j].d_end.month, readers[j].money);
		 }
		 else
		 {
			 fprintf(out, "%s\t%s\t\t%s\t%d\t%d\t%d %d\t%d %d\t%d\n", readers[j].name, readers[j].addr, readers[j].phone,
				 readers[j].journal_num, readers[j].sub_num,
				 readers[j].d_begin.year, readers[j].d_begin.month,
				 readers[j].d_end.year, readers[j].d_end.month, readers[j].money);
		 }
	 }
	 fclose(fp);
	 fclose(out);
	 return ret;
}
void effective_journal_num()
{
	int num=update_reader_inf();//ɸ�������û���Ϣ
	printf("��Ч��־������Ϊ%d\n",num);
	system("pause");
}
void every_journal_num()
{
	update_reader_inf();
	printf("����	סַ		�绰		�ڿ���	���ķ���	������	ֹ������	�۸�\n");
	struct Reader readers[30];
	FILE* fp = fopen("Reader.txt", "r+");
	struct Reader one;//���ж�ȡ�洢�ڽṹ����
	int i = 0;//�����±�
	while (fscanf(fp, "%s%s%s%d%d%d%d%d%d%d", &one.name, &one.addr, &one.phone, &one.journal_num, &one.sub_num,
		&one.d_begin.year, &one.d_begin.month, &one.d_end.year, &one.d_end.month, &one.money) != EOF)
		readers[i++] = one;
	int j = 0;
	for (; j < i; j++)
	{
		printf("%s\t%s\t\t%s\t%d\t%d\t%d %d\t%d %d\t%d\n", readers[j].name, readers[j].addr, readers[j].phone,
			readers[j].journal_num, readers[j].sub_num,
			readers[j].d_begin.year, readers[j].d_begin.month, readers[j].d_end.year, readers[j].d_end.month, readers[j].money);
	}
	system("pause");
}
void sort_reader()
{
	FILE* Mag;
	FILE* Reader;
	int num[10] = {0};//�����±�+1=��Ӧ�ڿ�����
	int j = 0, flag = 0;
	int sum = 0;
	struct Journal journal[10];
	struct Journal one;
	int i = 0;//�����±�
	int num_of_journal = 0;

	if ((Mag = fopen("MAG.txt", "r")) == NULL)
		printf("���ڿ��ļ�����\n"); // ���ļ�
	if ((Reader = fopen("Reader.txt","r"))== NULL)
		puts("���ļ�����\n");
	
	while (fscanf(Mag, "%d%s%d%d", &one.journal_num, &one.name, &one.times, &one.money) != EOF)
		journal[i++] = one;

	num_of_journal = i;
	i = 0;
	struct Reader readers[30];
	struct Reader read;
	while (fscanf(Reader, "%s%s%s%d%d%d%d%d%d%d", &read.name, &read.addr, &read.phone, &read.journal_num, &read.sub_num,
		&read.d_begin.year, &read.d_begin.month, &read.d_end.year, &read.d_end.month, &read.money) != EOF)
		readers[i++] = read;
	
	for (; j < i; j++)
		num[readers[j].journal_num - 1] += readers[j].sub_num;

	sum = j;
	i = 0, j = 0;
	for (; i < sum - 1;i++)//ð������ð�ݴ���
	{
		flag = 0;
		for (j = 0; j < sum - i - 1; j++)
		{
			if (num[j]>num[j + 1])
			{
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;

				struct Journal j1 = journal[j];
				journal[j] = journal[j + 1];
				journal[j + 1] = j1;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	j = 0;
	for (; j < num_of_journal; j++)
		printf("%s������Ŀ:%d\n", journal[j].name, num[j]);

	system("pause");
}
void overdue_subscriber_not_subscribed()
{
	FILE* Out;
	FILE* Reader;
	int num[10] = { 0 };//�����±�+1=��Ӧ�ڿ�����
	int j = 0;
	int i = 0;//�����±�
	int num_of_journal = 0;
	struct Reader out[30];
	struct Reader readers[30];
	struct Reader read;

	if ((Out = fopen("Out.txt", "r")) == NULL)
		printf("���ڿ��ļ�����\n"); // ���ļ�
	if ((Reader = fopen("Reader.txt", "r")) == NULL)
		puts("���ļ�����\n");
	
	while (fscanf(Reader, "%s%s%s%d%d%d%d%d%d%d", &read.name, &read.addr, &read.phone, &read.journal_num, &read.sub_num,
		&read.d_begin.year, &read.d_begin.month, &read.d_end.year, &read.d_end.month, &read.money) != EOF)
		readers[i++] = read;

	i = 0;
	while (fscanf(Out, "%s%s%s%d%d%d%d%d%d%d", &read.name, &read.addr, &read.phone, &read.journal_num, &read.sub_num,
		&read.d_begin.year, &read.d_begin.month, &read.d_end.year, &read.d_end.month, &read.money) != EOF)
		out[i++] = read;
	for (; j < i; j++)
	{
		printf("�����û�������δ������\n������%sסַ��%s�绰��%s\n", &out[j].name, &out[j].addr, &out[j].phone);
	}
	system("pause");
}
int main()
{
	int n;
	menu();
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		increase_new_reader();//�����¶�����Ϣ¼��
		break;
	case 2:
		update_reader_inf();//���¶�������Ϣ
		break;
	case 3:
		effective_journal_num();//��Ч�ڿ�������Ŀ
		break;
	case 4:
		every_journal_num();//ÿ���ڿ�������
		break;
	case 5:
		sort_reader();//һ��ʱ����ڣ��ڿ���������
		break;
	case 6:
		overdue_subscriber_not_subscribed();//���ڶ���δ������չʾ
		break;
	default:
		break;
	}
	return 0;
}