#include"Gift.h"


static Gift_list Gifts;

void Menu()
{
	bool had_gift_game = 0;
	while (1) {
		system("cls");
		cout << "****************************************************************************" << endl;
		cout << "0.�˳��齱ϵͳ				   1.Ա����Ϣ����" << endl;
		cout << "2.������Ϣ����				   3.�齱			4.�鿴������" << endl;
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
			if (had_gift_game == 0)//����鿴��Ʒ��Ϣʱ��δ���г齱�����ȡ�ϴα���Ļ���Ա��Ϣ
			{
				for (auto& e : Gifts.Getgift())
					e.ReadGiftInf();
			}
			for (auto& e : Gifts.Getgift())
				e.Write_to_Shell();
			//��ӡ����Ա����������ڴ�û���κλ���Ϣ�����ӡ�ϴα��浽�ļ��Ļ���Ϣ
			for (auto& e : Gifts.Getgift())
				e.Write_Gift_People_to_Shell();
			Pause();
			break;
		default:
			cout << "�������,���������롣" << endl;
			Pause();
			break;
		}
		if (n == 0)
		{
			cout << "�Ƿ񱣴�˴γ齱��Ա��Ϣ?y/n" << endl;
			while (1)
			{
				char c;
				cin >> c;
				if (c == 'y' || c == 'Y')
				{
					//����Ʒ��Ϣ�ͻ���Ա��Ϣ���µ��ļ���Ա����Ϣʼ�ղ�Ҫ�ı�
					cout << "���Ѿ�����" << endl;
					for (auto& e : Gifts.Getgift())
						e.Write_Gift_inf_to_file();//����˴γ齱����Ա��Ϣ
					Pause();
					break;
				}
				else if (c == 'n' || c == 'N')
				{
					cout << "��δ����" << endl;
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