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
	int journal_num;//期刊编号
	int sub_num;//订阅份数
	struct Date d_begin;//起订年月
	struct Date d_end;//止定年月
	int money;
};
struct Journal{
	int journal_num;
	char name[20];
	int times;//每月期刊次
	int money;//每期单价
};

struct Date get_now_date_()//获取现在的日期
{
	time_t now;
	struct tm *tm_now;
	time(&now);
	tm_now = localtime(&now);
	//printf("now datetime: %d-%d-%d\n",tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday) ;当前日期
	struct Date today;
	today.year = tm_now->tm_year + 1900;
	today.month = tm_now->tm_mon + 1;
	return today;
}
int count_month_of_data(struct Date d1, struct Date d2)//计算两个日期之间的月数
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
	printf("1.增加新订阅户		  	        2.清理到期订户信息\n");
	printf("3.有效期刊订阅数\t	        4.每种期刊订阅数\n");
	printf("5.热点期刊排行榜\t\t        6.过期订户今年仍然没订阅\n");
	printf("请输入选择>");
}
void increase_new_reader()
{
	FILE *Reader, *Mag;

	if ((Mag = fopen("MAG.txt", "r")) == NULL)
		printf("打开期刊文件出错\n"); // 打开文件
	if ((Reader = fopen("Reader.txt", "a+")) == NULL)
		printf("打开读者文件出错\n"); // 打开文件

	struct Journal journal[10];
	struct Journal one;
	int i = 0;//数组下标
	while (fscanf(Mag, "%d%s%d%d", &one.journal_num, &one.name, &one.times, &one.money) != EOF)
		journal[i++] = one;
	struct Reader reader;

	printf("请输入订阅者姓名:");
	scanf("%s", &reader.name);

	printf("请输入订阅者住址:");
	scanf("%s", &reader.addr);

	printf("请输入订阅者电话:");
	scanf("%s", &reader.phone);

	printf("请输入订阅期刊号:");
	scanf("%d", &reader.journal_num);

	printf("请输入订阅份数:");
	scanf("%d", &reader.sub_num);

	printf("请输入订阅起订年:");
	scanf("%d", &reader.d_begin.year);

	printf("请输入订阅起订月:");
	scanf("%d", &reader.d_begin.month);

	printf("请输入订阅止订年:");
	scanf("%d", &reader.d_end.year);

	printf("请输入订阅止订月:");
	scanf("%d", &reader.d_end.month);

	//计算订阅者该支付多少钱？
	int n = count_month_of_data(reader.d_begin, reader.d_end);//订阅几个月
	reader.money = n*journal[reader.journal_num].times*journal[reader.journal_num].money;//月*每月刊次*每次单价

	fprintf(Reader, "%s\t%s\t\t%s\t%d\t%d\t%d %d\t%d %d\t%d\n", reader.name, reader.addr, reader.phone,
		reader.journal_num, reader.sub_num,
		reader.d_begin.year, reader.d_begin.month, reader.d_end.year, reader.d_end.month, reader.money);
	fclose(Reader); // 关闭文件指针
	fclose(Mag);
	printf("添加新的订阅户成功！");
	system("pause");
}

int update_reader_inf()//返回有效杂志订户数
{
	int ret = 0;
	 struct Date today = get_now_date_();
	 struct Reader readers[30];//需要清理过期用户，先把用户信息全部读取，这里使用数组存储用户信息
	 FILE* fp = fopen("Reader.txt","r+");
	 FILE* out = fopen("Out.txt","a+");
	 if (out == NULL)
		 puts("打开文件出错\n");
	 struct Reader one;//按行读取存储在结构体中
	 int i = 0;//数组下标
	 while (fscanf(fp, "%s%s%s%d%d%d%d%d%d%d", &one.name, &one.addr, &one.phone, &one.journal_num,&one.sub_num,
		 &one.d_begin.year, &one.d_begin.month, &one.d_end.year, &one.d_end.month, &one.money) != EOF)
		 readers[i++] = one;


	 //将数组排除过期用户重新写入文件,总共需要写入i个reader信息
	 fp = fopen("Reader.txt", "w+");
	 fseek(fp, 0, SEEK_SET);
	 int j = 0;//再一次遍历数组的下标
	 for (; j < i;j++)
	 {
		 if ((readers[j].d_end.year> today.year) ||
			 ((readers[j].d_end.year == today.year) && (readers[j].d_end.month> today.month)))//用户订阅时间未过期写入
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
	int num=update_reader_inf();//筛除过期用户信息
	printf("有效杂志订户数为%d\n",num);
	system("pause");
}
void every_journal_num()
{
	update_reader_inf();
	printf("姓名	住址		电话		期刊号	订阅份数	起订年月	止订年月	价格\n");
	struct Reader readers[30];
	FILE* fp = fopen("Reader.txt", "r+");
	struct Reader one;//按行读取存储在结构体中
	int i = 0;//数组下标
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
	int num[10] = {0};//数组下标+1=对应期刊号码
	int j = 0, flag = 0;
	int sum = 0;
	struct Journal journal[10];
	struct Journal one;
	int i = 0;//数组下标
	int num_of_journal = 0;

	if ((Mag = fopen("MAG.txt", "r")) == NULL)
		printf("打开期刊文件出错\n"); // 打开文件
	if ((Reader = fopen("Reader.txt","r"))== NULL)
		puts("打开文件出错\n");
	
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
	for (; i < sum - 1;i++)//冒泡排序冒泡次数
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
		printf("%s订阅数目:%d\n", journal[j].name, num[j]);

	system("pause");
}
void overdue_subscriber_not_subscribed()
{
	FILE* Out;
	FILE* Reader;
	int num[10] = { 0 };//数组下标+1=对应期刊号码
	int j = 0;
	int i = 0;//数组下标
	int num_of_journal = 0;
	struct Reader out[30];
	struct Reader readers[30];
	struct Reader read;

	if ((Out = fopen("Out.txt", "r")) == NULL)
		printf("打开期刊文件出错\n"); // 打开文件
	if ((Reader = fopen("Reader.txt", "r")) == NULL)
		puts("打开文件出错\n");
	
	while (fscanf(Reader, "%s%s%s%d%d%d%d%d%d%d", &read.name, &read.addr, &read.phone, &read.journal_num, &read.sub_num,
		&read.d_begin.year, &read.d_begin.month, &read.d_end.year, &read.d_end.month, &read.money) != EOF)
		readers[i++] = read;

	i = 0;
	while (fscanf(Out, "%s%s%s%d%d%d%d%d%d%d", &read.name, &read.addr, &read.phone, &read.journal_num, &read.sub_num,
		&read.d_begin.year, &read.d_begin.month, &read.d_end.year, &read.d_end.month, &read.money) != EOF)
		out[i++] = read;
	for (; j < i; j++)
	{
		printf("过期用户今年仍未订阅者\n姓名：%s住址：%s电话：%s\n", &out[j].name, &out[j].addr, &out[j].phone);
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
		increase_new_reader();//进行新订户信息录入
		break;
	case 2:
		update_reader_inf();//更新订阅者信息
		break;
	case 3:
		effective_journal_num();//有效期刊订阅数目
		break;
	case 4:
		every_journal_num();//每种期刊订阅数
		break;
	case 5:
		sort_reader();//一个时间段内，期刊降序排列
		break;
	case 6:
		overdue_subscriber_not_subscribed();//过期订户未订阅者展示
		break;
	default:
		break;
	}
	return 0;
}