#include"Gift.h"


static Gift_list Gifts;

void Menu()
{
	bool had_gift_game = 0;
	while (1) {
		system("cls");
		cout << "****************************************************************************" << endl;
		cout << "0.退出抽奖系统				   1.员工信息操作" << endl;
		cout << "2.奖项信息操作				   3.抽奖			4.查看获奖名单" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
			Gifts.tool_person.Person_Set();
			break;
		case 2:
			Gifts.Gift_Set();
			break;
		case 3:
			had_gift_game = 1;
			Gifts.Game_Gift();
			break;
		case 4:
			if (had_gift_game == 0)//如果查看奖品信息时还未进行抽奖，则读取上次保存的获奖人员信息
			{
				for (auto& e : Gifts.Getgift())
					e.ReadGiftInf();
			}
			for (auto& e : Gifts.Getgift())
				e.Write_to_Shell();
			//打印获奖人员名单，如果内存没有任何获奖信息，则打印上次保存到文件的获奖信息
			for (auto& e : Gifts.Getgift())
				e.Write_Gift_People_to_Shell();
			Pause();
			break;
		default:
			cout << "输入错误,请重新输入。" << endl;
			Pause();
			break;
		}
		if (n == 0)
		{
			cout << "是否保存此次抽奖人员信息?y/n" << endl;
			while (1)
			{
				char c;
				cin >> c;
				if (c == 'y' || c == 'Y')
				{
					//将奖品信息和获奖人员信息更新到文件，员工信息始终不要改变
					cout << "你已经保存" << endl;
					for (auto& e : Gifts.Getgift())
						e.Write_Gift_inf_to_file();//保存此次抽奖获奖人员信息
					Pause();
					break;
				}
				else if (c == 'n' || c == 'N')
				{
					cout << "你未保存" << endl;
					Pause();
					break;
				}
			}
			break;
		}
	}
}

int main()
{
	Menu();
	return 0;
}