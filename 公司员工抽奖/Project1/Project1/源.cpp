//#include"Gift.h"
//
//static Gift_list Gifts;//�洢��Ʒ������Ӧ��Ψһ����
//void Search()
//{
//	cout << "����������Ҫ�Ĳ�ѯ��ʽ��" << endl;
//	cout << "1.Ա����Ų���						2.Ա����������	" << endl;
//	cout << "3.Ա���ֻ��Ų���				    0.�˳��齱ϵͳ" << endl;
//	int n;
//	cin >> n;
//	switch (n)
//	{
//	case 0:
//		exit(0);
//		break;
//	case 1:
//	{
//			  cout << "����������Ҫ��ѯ��Ա�����:";
//			  int n;
//			  cin >> n;
//			  Gifts.tool_person.SearchPerson_Jobnum(n);
//	}
//		break;
//	case 2:
//	{
//			  cout << "����������Ҫ��ѯ��Ա������:";
//			  string str;
//			  cin >> str;
//			  Gifts.tool_person.SearchPerson_Name(str);
//	}
//		break;
//	case 3:
//	{
//			  cout << "����������Ҫ��ѯ��Ա���ֻ���:";
//			  string str;
//			  cin >> str;
//			  Gifts.tool_person.SearchPerson_Phone(str);
//	}
//		break;
//	default:
//		cout << "ѡ�����" << endl;
//		break;
//	}
//}
//void Person_Set()
//{
//	cout << endl << "****************************************************************************" << endl;
//	cout << "1.Ա����Ϣ����						2.���Ա��	" << endl;
//	cout << "3.Ա������						    4.�޸�Ա����Ϣ" << endl;
//	cout << "5.ɾ��ĳԱ��					    6.Ա����Ϣ�������ļ�" << endl;
//	cout << "0.�˳��齱ϵͳ" << endl;
//	int n;
//	cin >> n;
//	switch (n)
//	{
//	case 0:
//		exit(0);
//		break;
//	case 1:
//		Gift_list::tool_person.Read_File();
//		cout << "�Ѿ����Ա����Ϣ���룬��ѡ������������" << endl;
//		Person_Set();
//		break;
//	case 2:
//		Gift_list::tool_person.InsertNode(Person::CreateNode());
//		cout << "�Ѿ����Ա����Ϣ��ӣ���ѡ������������" << endl;
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
//void ModifyGift()//�޸Ľ���
//{
//	Gifts.ShowGift();
//	cout << "�����������޸ĵĽ����ţ�";
//	int n;
//	cin >> n;
//	cout << "������ý����������Ϣ��";
//	Gifts.Getgift()[n] = Gift::CreateGift();
//}
//void Gift_Set()
//{
//	cout << "****************************************************************************" << endl;
//	cout << "1.��ӽ���							2.�޸Ľ���	" << endl;
//	cout << "3.���潱��							4.ɾ������" << endl;
//	cout << "5.�г�������Ϣ				        0.�˳��齱ϵͳ" << endl;
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
//		//�޸Ľ���
//		ModifyGift();
//		break;
//	case 3:
//		Gifts.Write_to_file();//д���ļ�������
//		break;
//	case 4:
//		Gifts.DelGift(Gift::CreateGift());//ɾ������
//		break;
//	case 5:
//		//�г�������Ϣ
//		Gifts.ShowGift();
//		break;
//	default:
//		exit(0);
//		break;
//	}
//}
//
//bool  Luck_one(int n)//��һ����
//{
//	int pos = rand() % Gift_list::tool_person.GetPerMap().size();//���ɵ������
//	Gifts.Getgift()[n].GetPeople().push_back(Gift_list::tool_person.GetPerMap()[pos]);
//	return true;
//}
//
//bool Luck_All(int n)//һ����ɳ齱�
//{
//	int size = Gifts.Getgift()[n].GetTotalGift();//�ܹ�Ҫ��ȡ�Ľ���Ŀ
//	while (size--)
//		Luck_one(n);
//	return true;
//}
//void Game_Gift()//�齱����ѡ��˵�
//{
//	cout << "****************************************************************************" << endl;
//	//�г�������Ϣ
//	Gifts.ShowGift();
//	cout << "����������Ҫ�ȳ�ȡ�Ľ����ţ�";
//	size_t n;
//	cin >> n;
//	if (n > Gifts.Getgift().size())
//	{
//		cout << "�������������������룺";
//		//�г�������Ϣ
//		Gifts.ShowGift();
//	}
//	else
//	{
//		//�齱֮ǰ���ȼ��ʣ������
//		if (Gifts.Getgift()[n].GetPeople().size() >= Gifts.Getgift()[n].GetTotalGift())
//		{
//			cout << "����Ҫ��ȡ�Ľ��ڴ�֮ǰ�Ѿ�����˳齱�������ѡ��";
//			cout << "****************************************************************************" << endl;
//			cout << "1.�鿴�ý�����Ϣ				    2.�ÿջ���Ϣ������ʼ��һ�ֿ�ʼ�齱	" << endl;
//			cout << "3.��ȡ������						0.�˳��齱ϵͳ" << endl;
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
//				//�ÿ�Gift���飬�ٳ齱
//				Gifts.ShowGift();
//				break;
//			case 3:
//				//��������Ʒ
//				Gifts.ShowGift();
//				break;
//			default:
//				break;
//			}
//		}
//		else
//		{
//			cout << "�Ƿ�һ����ɳ齱��y/n";//n��һ��һ�ν��г齱
//			cout << endl;
//			char c;
//			cin >> c;
//			if (c == 'y' || c == 'Y')
//				Luck_All(n);
//			else if (c == 'N' || c == 'n')
//				Luck_one(n);
//			else
//			{
//				cout << "�������������ѡ��";
//				Game_Gift();
//			}
//		}
//	}
//}
//void Menu()
//{
//	cout << "****************************************************************************" << endl;
//	cout << "1.Ա����Ա����						2.�������	" << endl;
//	cout << "3.�齱����						    0.�˳��齱ϵͳ" << endl;
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
//		cout << "�������,���������롣" << endl;
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
	cout << "�����밴�س�" << endl;
	while (1) {
		getchar();
		char c = getchar();
		if (c == '\n') {
			break;
		}
	}
}

static Gift_list Gifts;//�洢��Ʒ������Ӧ��Ψһ����
void Search()
{
	while (1) {
		cout << "����������Ҫ�Ĳ�ѯ��ʽ��" << endl;
		cout << "1.Ա����Ų���						2.Ա����������	" << endl;
		cout << "3.Ա���ֻ��Ų���				    0.������һ��˵�" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
		{
				  system("cls");
				  cout << "����������Ҫ��ѯ��Ա�����:";
				  int n;
				  cin >> n;
				  Gifts.tool_person.SearchPerson_Jobnum(n);
				  Pause();
		}
			break;
		case 2:
		{
				  system("cls");
				  cout << "����������Ҫ��ѯ��Ա������:";
				  string str;
				  cin >> str;
				  Gifts.tool_person.SearchPerson_Name(str);
				  Pause();
		}
			break;
		case 3:
		{
				  system("cls");
				  cout << "����������Ҫ��ѯ��Ա���ֻ���:";
				  string str;
				  cin >> str;
				  Gifts.tool_person.SearchPerson_Phone(str);
				  Pause();
		}
			break;
		default:
			system("cls");
			cout << "ѡ�����" << endl;
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
		cout << "1.Ա����Ϣ����						2.���Ա��	" << endl;
		cout << "3.Ա������						    4.�޸�Ա����Ϣ" << endl;
		cout << "5.ɾ��ĳԱ��					    6.Ա����Ϣ�������ļ�" << endl;
		cout << "0.�����ϲ�˵�" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
			system("cls");
			Gift_list::tool_person.Read_File();
			cout << "�Ѿ����Ա����Ϣ����" << endl;
			Pause();
			break;
		case 2:
			system("cls");
			Gift_list::tool_person.InsertNode(Person::CreateNode());
			cout << "�Ѿ����Ա����Ϣ���" << endl;
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

void ModifyGift()//�޸Ľ���
{
	Gifts.ShowGift();
	cout << "�����������޸ĵĽ����ţ�";
	int n;
	cin >> n;
	cout << "������ý����������Ϣ��";
	Gifts.Getgift()[n] = Gift::CreateGift();
}
void Gift_Set()
{
	cout << "****************************************************************************" << endl;
	cout << "1.��ӽ���							2.�޸Ľ���	" << endl;
	cout << "3.���潱��							4.ɾ������" << endl;
	cout << "5.�г�������Ϣ				        0.�˳��齱ϵͳ" << endl;
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
		//�޸Ľ���
		ModifyGift();
		break;
	case 3:
		Gifts.Write_to_file();//д���ļ�������
		break;
	case 4:
		Gifts.DelGift(Gift::CreateGift());//ɾ������
		break;
	case 5:
		//�г�������Ϣ
		Gifts.ShowGift();
		break;
	default:
		exit(0);
		break;
	}
}

bool  Luck_one(int n)//��һ����
{
	int pos = rand() % Gift_list::tool_person.GetPerMap().size();//���ɵ������
	Gifts.Getgift()[n].GetPeople().push_back(Gift_list::tool_person.GetPerMap()[pos]);
	return true;
}

bool Luck_All(int n)//һ����ɳ齱�
{
	int size = Gifts.Getgift()[n].GetTotalGift();//�ܹ�Ҫ��ȡ�Ľ���Ŀ
	while (size--)
		Luck_one(n);
	return true;
}
void Game_Gift()//�齱����ѡ��˵�
{
	cout << "****************************************************************************" << endl;
	//�г�������Ϣ
	Gifts.ShowGift();
	cout << "����������Ҫ�ȳ�ȡ�Ľ����ţ�";
	size_t n;
	cin >> n;
	if (n > Gifts.Getgift().size())
	{
		cout << "�������������������룺";
		//�г�������Ϣ
		Gifts.ShowGift();
	}
	else
	{
		//�齱֮ǰ���ȼ��ʣ������
		if (Gifts.Getgift()[n].GetPeople().size() >= Gifts.Getgift()[n].GetTotalGift())
		{
			cout << "����Ҫ��ȡ�Ľ��ڴ�֮ǰ�Ѿ�����˳齱�������ѡ��";
			cout << "****************************************************************************" << endl;
			cout << "1.�鿴�ý�����Ϣ				    2.�ÿջ���Ϣ������ʼ��һ�ֿ�ʼ�齱	" << endl;
			cout << "3.��ȡ������						0.�˳��齱ϵͳ" << endl;
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
				//�ÿ�Gift���飬�ٳ齱
				Gifts.ShowGift();
				break;
			case 3:
				//��������Ʒ
				Gifts.ShowGift();
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "�Ƿ�һ����ɳ齱��y/n";//n��һ��һ�ν��г齱
			cout << endl;
			char c;
			cin >> c;
			if (c == 'y' || c == 'Y')
				Luck_All(n);
			else if (c == 'N' || c == 'n')
				Luck_one(n);
			else
			{
				cout << "�������������ѡ��";
				Game_Gift();
			}
		}
	}
}
void Menu()
{
	while (1) {
		cout << "****************************************************************************" << endl;
		cout << "1.Ա����Ա����						2.�������	" << endl;
		cout << "3.�齱����						    0.�˳��齱ϵͳ" << endl;
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
			cout << "�������,���������롣" << endl;
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