//#include"Gift.h"
//
//static Gift_list Gifts;//存储奖品的数组应该唯一存在
//void Search()
//{
//	cout << "请输入你想要的查询方式：" << endl;
//	cout << "1.员工编号查找						2.员工姓名查找	" << endl;
//	cout << "3.员工手机号查找				    0.退出抽奖系统" << endl;
//	int n;
//	cin >> n;
//	switch (n)
//	{
//	case 0:
//		exit(0);
//		break;
//	case 1:
//	{
//			  cout << "请输入你所要查询的员工编号:";
//			  int n;
//			  cin >> n;
//			  Gifts.tool_person.SearchPerson_Jobnum(n);
//	}
//		break;
//	case 2:
//	{
//			  cout << "请输入你所要查询的员工姓名:";
//			  string str;
//			  cin >> str;
//			  Gifts.tool_person.SearchPerson_Name(str);
//	}
//		break;
//	case 3:
//	{
//			  cout << "请输入你所要查询的员工手机号:";
//			  string str;
//			  cin >> str;
//			  Gifts.tool_person.SearchPerson_Phone(str);
//	}
//		break;
//	default:
//		cout << "选择错误" << endl;
//		break;
//	}
//}
//void Person_Set()
//{
//	cout << endl << "****************************************************************************" << endl;
//	cout << "1.员工信息导入						2.添加员工	" << endl;
//	cout << "3.员工查找						    4.修改员工信息" << endl;
//	cout << "5.删除某员工					    6.员工信息保存至文件" << endl;
//	cout << "0.退出抽奖系统" << endl;
//	int n;
//	cin >> n;
//	switch (n)
//	{
//	case 0:
//		exit(0);
//		break;
//	case 1:
//		Gift_list::tool_person.Read_File();
//		cout << "已经完成员工信息导入，请选择其它操作：" << endl;
//		Person_Set();
//		break;
//	case 2:
//		Gift_list::tool_person.InsertNode(Person::CreateNode());
//		cout << "已经完成员工信息添加，请选择其它操作：" << endl;
//		Person_Set();
//		break;
//	case 3:
//		Search();
//		break;
//	case 4:
//		Gift_list::tool_person.ModifyNode(Person::CreateNode());
//		break;
//	case 5:
//		Gift_list::tool_person.DeleteNode(Person::CreateNode());
//		break;
//	case 6:
//		Gift_list::tool_person.Write_to_File();
//	default:
//		break;
//	}
//}
//void ModifyGift()//修改奖项
//{
//	Gifts.ShowGift();
//	cout << "请输入你想修改的奖项编号：";
//	int n;
//	cin >> n;
//	cout << "请输入该奖项的最新信息：";
//	Gifts.Getgift()[n] = Gift::CreateGift();
//}
//void Gift_Set()
//{
//	cout << "****************************************************************************" << endl;
//	cout << "1.添加奖项							2.修改奖项	" << endl;
//	cout << "3.保存奖项							4.删除奖项" << endl;
//	cout << "5.列出奖项信息				        0.退出抽奖系统" << endl;
//	int n;
//	cin >> n;
//	switch (n)
//	{
//	case 0:
//		break;
//	case 1:
//		Gifts.InsertGift(Gift::CreateGift());
//		break;
//	case 2:
//		//修改奖项
//		ModifyGift();
//		break;
//	case 3:
//		Gifts.Write_to_file();//写入文件保存了
//		break;
//	case 4:
//		Gifts.DelGift(Gift::CreateGift());//删除奖项
//		break;
//	case 5:
//		//列出奖项信息
//		Gifts.ShowGift();
//		break;
//	default:
//		exit(0);
//		break;
//	}
//}
//
//bool  Luck_one(int n)//抽一个奖
//{
//	int pos = rand() % Gift_list::tool_person.GetPerMap().size();//生成的随机数
//	Gifts.Getgift()[n].GetPeople().push_back(Gift_list::tool_person.GetPerMap()[pos]);
//	return true;
//}
//
//bool Luck_All(int n)//一次完成抽奖活动
//{
//	int size = Gifts.Getgift()[n].GetTotalGift();//总共要抽取的奖数目
//	while (size--)
//		Luck_one(n);
//	return true;
//}
//void Game_Gift()//抽奖操作选择菜单
//{
//	cout << "****************************************************************************" << endl;
//	//列出奖项信息
//	Gifts.ShowGift();
//	cout << "请输入你想要先抽取的奖项编号：";
//	size_t n;
//	cin >> n;
//	if (n > Gifts.Getgift().size())
//	{
//		cout << "输入编号有误，请重新输入：";
//		//列出奖项信息
//		Gifts.ShowGift();
//	}
//	else
//	{
//		//抽奖之前，先检查剩余名额
//		if (Gifts.Getgift()[n].GetPeople().size() >= Gifts.Getgift()[n].GetTotalGift())
//		{
//			cout << "你想要抽取的奖在此之前已经完成了抽奖，你可以选择：";
//			cout << "****************************************************************************" << endl;
//			cout << "1.查看该奖获奖信息				    2.置空获奖信息，并开始新一轮开始抽奖	" << endl;
//			cout << "3.抽取其它奖						0.退出抽奖系统" << endl;
//			int n;
//			cin >> n;
//			switch (n)
//			{
//			case 0:
//				exit(0);
//				break;
//			case 1:
//				Gifts.Getgift()[n].Write_to_Shell();
//				break;
//			case 2:
//				Gifts.Getgift().clear();
//				//置空Gift数组，再抽奖
//				Gifts.ShowGift();
//				break;
//			case 3:
//				//抽其他奖品
//				Gifts.ShowGift();
//				break;
//			default:
//				break;
//			}
//		}
//		else
//		{
//			cout << "是否一次完成抽奖？y/n";//n是一次一次进行抽奖
//			cout << endl;
//			char c;
//			cin >> c;
//			if (c == 'y' || c == 'Y')
//				Luck_All(n);
//			else if (c == 'N' || c == 'n')
//				Luck_one(n);
//			else
//			{
//				cout << "输入错误，请重新选择：";
//				Game_Gift();
//			}
//		}
//	}
//}
//void Menu()
//{
//	cout << "****************************************************************************" << endl;
//	cout << "1.员工人员操作						2.奖项操作	" << endl;
//	cout << "3.抽奖操作						    0.退出抽奖系统" << endl;
//	int n;
//	cin >> n;
//	switch (n)
//	{
//	case 0:
//		exit(0);
//	case 1:
//		Person_Set();
//		break;
//	case 2:
//		Gift_Set();
//		break;
//	case 3:
//		Game_Gift();
//		break;
//	default:
//		cout << "输入错误,请重新输入。" << endl;
//		break;
//	}
//}
//
//int main()
//{
//	Menu();
//	return 0;
//}

#include"Gift.h"

void Pause() {
	cout << "继续请按回车" << endl;
	while (1) {
		getchar();
		char c = getchar();
		if (c == '\n') {
			break;
		}
	}
}

static Gift_list Gifts;//存储奖品的数组应该唯一存在
void Search()
{
	while (1) {
		cout << "请输入你想要的查询方式：" << endl;
		cout << "1.员工编号查找						2.员工姓名查找	" << endl;
		cout << "3.员工手机号查找				    0.返回上一层菜单" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
		{
				  system("cls");
				  cout << "请输入你所要查询的员工编号:";
				  int n;
				  cin >> n;
				  Gifts.tool_person.SearchPerson_Jobnum(n);
				  Pause();
		}
			break;
		case 2:
		{
				  system("cls");
				  cout << "请输入你所要查询的员工姓名:";
				  string str;
				  cin >> str;
				  Gifts.tool_person.SearchPerson_Name(str);
				  Pause();
		}
			break;
		case 3:
		{
				  system("cls");
				  cout << "请输入你所要查询的员工手机号:";
				  string str;
				  cin >> str;
				  Gifts.tool_person.SearchPerson_Phone(str);
				  Pause();
		}
			break;
		default:
			system("cls");
			cout << "选择错误" << endl;
			Pause();
			break;
		}
		system("cls");
	}
}
void Person_Set()
{
	while (1) {
		system("cls");
		cout << endl << "****************************************************************************" << endl;
		cout << "1.员工信息导入						2.添加员工	" << endl;
		cout << "3.员工查找						    4.修改员工信息" << endl;
		cout << "5.删除某员工					    6.员工信息保存至文件" << endl;
		cout << "0.返回上层菜单" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
			system("cls");
			Gift_list::tool_person.Read_File();
			cout << "已经完成员工信息导入" << endl;
			Pause();
			break;
		case 2:
			system("cls");
			Gift_list::tool_person.InsertNode(Person::CreateNode());
			cout << "已经完成员工信息添加" << endl;
			Pause();
			break;
		case 3:
			Search();
			break;
		case 4:
			Gift_list::tool_person.ModifyNode(Person::CreateNode());
			break;
		case 5:
			Gift_list::tool_person.DeleteNode(Person::CreateNode());
			break;
		case 6:
			Gift_list::tool_person.Write_to_File();
		default:
			break;
		}
		if (n == 0) {
			break;
		}
		system("cls");
	}
}

void ModifyGift()//修改奖项
{
	Gifts.ShowGift();
	cout << "请输入你想修改的奖项编号：";
	int n;
	cin >> n;
	cout << "请输入该奖项的最新信息：";
	Gifts.Getgift()[n] = Gift::CreateGift();
}
void Gift_Set()
{
	cout << "****************************************************************************" << endl;
	cout << "1.添加奖项							2.修改奖项	" << endl;
	cout << "3.保存奖项							4.删除奖项" << endl;
	cout << "5.列出奖项信息				        0.退出抽奖系统" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 0:
		break;
	case 1:
		Gifts.InsertGift(Gift::CreateGift());
		break;
	case 2:
		//修改奖项
		ModifyGift();
		break;
	case 3:
		Gifts.Write_to_file();//写入文件保存了
		break;
	case 4:
		Gifts.DelGift(Gift::CreateGift());//删除奖项
		break;
	case 5:
		//列出奖项信息
		Gifts.ShowGift();
		break;
	default:
		exit(0);
		break;
	}
}

bool  Luck_one(int n)//抽一个奖
{
	int pos = rand() % Gift_list::tool_person.GetPerMap().size();//生成的随机数
	Gifts.Getgift()[n].GetPeople().push_back(Gift_list::tool_person.GetPerMap()[pos]);
	return true;
}

bool Luck_All(int n)//一次完成抽奖活动
{
	int size = Gifts.Getgift()[n].GetTotalGift();//总共要抽取的奖数目
	while (size--)
		Luck_one(n);
	return true;
}
void Game_Gift()//抽奖操作选择菜单
{
	cout << "****************************************************************************" << endl;
	//列出奖项信息
	Gifts.ShowGift();
	cout << "请输入你想要先抽取的奖项编号：";
	size_t n;
	cin >> n;
	if (n > Gifts.Getgift().size())
	{
		cout << "输入编号有误，请重新输入：";
		//列出奖项信息
		Gifts.ShowGift();
	}
	else
	{
		//抽奖之前，先检查剩余名额
		if (Gifts.Getgift()[n].GetPeople().size() >= Gifts.Getgift()[n].GetTotalGift())
		{
			cout << "你想要抽取的奖在此之前已经完成了抽奖，你可以选择：";
			cout << "****************************************************************************" << endl;
			cout << "1.查看该奖获奖信息				    2.置空获奖信息，并开始新一轮开始抽奖	" << endl;
			cout << "3.抽取其它奖						0.退出抽奖系统" << endl;
			int n;
			cin >> n;
			switch (n)
			{
			case 0:
				exit(0);
				break;
			case 1:
				Gifts.Getgift()[n].Write_to_Shell();
				break;
			case 2:
				Gifts.Getgift().clear();
				//置空Gift数组，再抽奖
				Gifts.ShowGift();
				break;
			case 3:
				//抽其他奖品
				Gifts.ShowGift();
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "是否一次完成抽奖？y/n";//n是一次一次进行抽奖
			cout << endl;
			char c;
			cin >> c;
			if (c == 'y' || c == 'Y')
				Luck_All(n);
			else if (c == 'N' || c == 'n')
				Luck_one(n);
			else
			{
				cout << "输入错误，请重新选择：";
				Game_Gift();
			}
		}
	}
}
void Menu()
{
	while (1) {
		cout << "****************************************************************************" << endl;
		cout << "1.员工人员操作						2.奖项操作	" << endl;
		cout << "3.抽奖操作						    0.退出抽奖系统" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			exit(0);
		case 1:
			Person_Set();
			break;
		case 2:
			Gift_Set();
			break;
		case 3:
			Game_Gift();
			break;
		default:
			cout << "输入错误,请重新输入。" << endl;
			break;
		}
		system("cls");
	}
}

int main()
{
	Menu();
	return 0;
}