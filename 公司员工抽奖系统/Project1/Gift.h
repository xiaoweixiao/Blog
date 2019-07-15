#include"Person.h"

class Gift//��Ʒ��
{
public:
	string gift_name;//��������
	string gift;//��Ʒ����
	size_t total_gift;//�ý���ɳ�ȡ������
	vector<Person> person;//����Ա��Ϣ
public:
	Gift(){}
	Gift(string gift_name_, string gift_, int n, int id = 0) 
		:gift_name(gift_name_)
		, gift(gift_)
		, total_gift(n)
		, person(vector<Person>())
	{}
	

	bool Modify_Gift_Num(int n)//�޸����ֽ�Ʒ����Ŀ
	{
		total_gift = n;
	}
	bool Write_Gift_inf_to_file()//�洢����Ա��Ϣ
	{
		ofstream file;
		file.open("Gift_inf");
		if (file&&person.size()!=0) {
			file << "��Ա�����		" << "		��Ա������		" << "		��Ա����ϵ��ʽ" << endl;
			for (auto e : person) {
				file << e.job_num << "				" << e.name << "				  " << e.phone_number << endl;
			}
		}
		return true;
	}
	bool ReadGiftInf()//��ȡ����Ա��Ϣ
	{
		person.clear();
		ifstream ifs("Gift_inf", ios::in);
		char line[1024] = { 0 };
		for (int i = 0; ifs.getline(line, sizeof(line)); ++i) {
			if (i == 0) {
				continue;
			}
			stringstream word(line);
			Person p;
			word >> p.job_num;
			word >> p.name;
			word >> p.phone_number;
			person.push_back(p);
		}
		return true;
	}
	bool Write_Gift_People_to_Shell()//��ӡ����Ա��Ϣ
	{
		if (person.size()>0)
		{
			cout << gift_name << endl;
			cout << "��Ա�����			" << "		��Ա������		" << "		��Ա���ֻ�" << endl;
			for (auto& e : person) 
				cout << e.job_num << "			 " << e.name << "			 " << e.phone_number << endl;
		}
		cout << endl;
		return true;
	}

	bool Write_to_Shell()//�г���Ʒ��ϸ��Ϣ
	{
		cout << gift_name << "		" << gift << "			" << total_gift << "					" << person.size() << endl;
		return true;
	}
};//end of Gift

class Gift_list {
	friend class Gift;
private:
	static vector<Gift> gift_;
public:
	static Tool_Person tool_person;
public:
	vector<Gift>& Getgift()
	{
		return gift_;
	}
	Gift CreateGift()
	{
		string name, thing;
		int num;
		while (1)
		{
			cout << "�����뽱Ʒ���ƣ�";
			cin >> name;
			int pos = Search(name);
			if (pos != -1)
				cout << "������󣬸ý����Ѿ�����" << endl;
			else
			{
				cout << "�����뽱Ʒ���ݣ�";
				cin >> thing;
				cout << "�����øý�����Ҫ��ȡ��������";
				cin >> num;
				break;
			}
		}
		return Gift(name, thing, num);
	}
	void InsertGift(Gift gift)//���ӽ���
	{
		gift_.push_back(gift);
	}
	int Search(string name)//ͨ���������Ʋ��ҽ���
	{
		for (size_t i = 0; i < gift_.size(); i++) {
			if (strcmp(name.c_str(), gift_[i].gift_name.c_str()) == 0)
				return i;
		}
		return -1;
	}
	bool DelGift(string str)//ɾ������
	{
		int pos = Search(str);
		if (gift_.size() == 1)
			gift_.clear();
		else if (pos == -1)
		{
			cout << "��˵Ҫɾ���Ľ�Ʒ���Ʋ����ڣ�����������:" << endl;
			string s;
			cin >> s;
			DelGift(s);
		}
		else
		{
			for (size_t i = pos + 1; i < gift_.size(); i++)//0 1
				gift_[i - 1] = gift_[i];
			gift_.pop_back();
		}

		return true;
	}
	void Up_Date() {
		cout << "���´洢�ļ���y�������£�n" << endl;
		fflush(stdin);
		char c = getchar();
		if (c == 'y') {
			Write_to_file();
		}
	}
	void Read_File()//���ļ���ȡ��Ʒ��Ϣ�������ý�Ʒ����Ա��Ϣ��
	{
		gift_.clear();//��ȡ�ļ�֮ǰ���������ÿգ����ļ�����Ϊ׼
		ifstream ifs("All_Gift", ios::in);
		char line[1024] = { 0 };
		for (int i = 0; ifs.getline(line, sizeof(line)); ++i) {
			if (i == 0) {
				continue;
			}
			stringstream word(line);
			Gift g;
			word >> g.gift_name;
			word >> g.gift;
			word >> g.total_gift;
			g.ReadGiftInf();
			gift_.push_back(g);
		}
		ifs.clear();
		ifs.close();
	}
	void ShowGift()//�г����н���
	{
		cout << "��Ʒ����	 " << "��Ʒ			" << "�ý�����		 " << "		�ѳ�ȡ��" << endl;
		for (auto e : gift_)
			e.Write_to_Shell();
		Pause();
	}
	bool Write_to_file()//���潱��
	{
		ofstream f;
		f.open("All_Gift");
		if (f) {
			f << "��Ʒ����		" << "��Ʒ����	" << "�ý��ƻ���ȡ����		" << "�ý�Ʒ�Ѿ���ȡ������  " << endl;
			for (auto e : gift_) {
				f << e.gift_name << "		" << e.gift << "		" << e.total_gift << "			" << e.person.size() << endl;
				e.Write_Gift_inf_to_file();//���潱��ʱ�򣬶�Ӧ�����ȡ��Ա��ϢҲҪ����
			}
		}
		return true;
	}
	bool  Luck_one(int n)//��һ����
	{
		if (Gift_list::tool_person.GetPerMap().size() == 0)
		{
			Gift_list::tool_person.Read_File();
			if (Gift_list::tool_person.GetPerMap().size() == 0)
			{
				cout << "���������Ա��Ϣ���ٽ��г齱����" << endl;
				Pause();
			}
		}
		while (1)
		{
			int pos = rand() % 20 + 1;//���ɵ�1~20�������
			//�õ�������±꣬ʹ���±�ȥmapȡ��Ա�����ж��±��Ƿ����
			if (Gift_list::tool_person.GetPerMap().find(pos) == Gift_list::tool_person.GetPerMap().end())
				;//map�в����ڸ���Ա

			else
			{
				Getgift()[n].person.push_back(Gift_list::tool_person.GetPerMap()[pos]);//�ý�����Ա�����仯
				//��ȡ��Ա��ȡ��Ʒ֮����Ҫ��map��ɾ��
				Gift_list::tool_person.DeleteNode(pos);
				//��ӡ����Ա��Ϣ
				cout << "���ţ�" << Getgift()[n].person.back().job_num << endl;
				cout << "������" << Getgift()[n].person.back().name << endl;
				cout << "�ֻ���" << Getgift()[n].person.back().phone_number << endl;
				cout << "��ϲ����Ա�����" << Getgift()[n].gift_name << endl;
				cout << "��Ʒ��" << Getgift()[n].gift << endl;
				Pause();
				return true;
			}
		}

	}

	bool Luck_All(int n)//һ����ɳ齱�
	{
		int size = Getgift()[n].total_gift;//�ܹ�Ҫ��ȡ�Ľ���Ŀ
		while (size--)
			Luck_one(n);
		return true;
	}
public:
	void Gift_Set();
	void ModifyGift();//�޸Ľ���
	void Game_Gift();//�齱����ѡ��˵�
};
vector<Gift> Gift_list::gift_ = vector<Gift>();

Tool_Person Gift_list::tool_person = Tool_Person();//int A::a=10;

void Gift_list::ModifyGift()//�޸Ľ���
{
	ShowGift();
	cout << "����������Ҫ�޸ĵĽ�������" << endl;
	string str;
	cin >> str;
	while (1){
		int n = Search(str);
		if (n == -1)
		{
			cout << "�������!���������룺" << endl;
			cin >> str;
		}
		Getgift()[n] = CreateGift();
		cout << "�޸ĳɹ�" << endl; 
		break;
	}
}
void Gift_list::Gift_Set()
{
	bool had_save = 0;
	while (1){
		system("cls");
		cout << "****************************************************************************" << endl;
		cout << "1.��ӽ���							2.�޸Ľ���	" << endl;
		cout << "3.���潱��							4.ɾ������" << endl;
		cout << "5.�г�������Ϣ				        0.�����ϲ�˵�" << endl;
		cout << "6.���ϴα���Ľ����ļ��ж�ȡ������Ϣ" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
			InsertGift(CreateGift());
			Write_to_file();
			cout << "��ӽ�����Ϣ�ɹ�����д���ļ�" << endl;
			Pause();
			break;
		case 2:
			ModifyGift();
			break;
		case 3:
			Write_to_file();//д���ļ�������
			had_save = 1;
			cout << "���浽�ļ��ɹ�����" << endl;
			Pause();
			break;
		case 4:
		{
				  cout << "��������Ҫɾ���Ľ�������:";
				  string str;
				  cin >> str;
				  DelGift(str);
				  cout << "ɾ���ɹ�" << endl;
				  Pause();
		}
			break;
		case 5:
			//�г�������Ϣ
			ShowGift();
			break;
		case 6:
			Read_File();
			cout << "�Ѷ�ȡ���ڴ棬�ɼ�������" << endl;
			Pause();
			break;
		default:
			cout << "�������" << endl;
			break;
		}
		if (n == 0)
		{
			if (had_save == 0)
				Up_Date();
			break;
		}
		system("cls");
	}
}
void Gift_list::Game_Gift()//�齱����ѡ��˵�
{
	if (gift_.size() == 0)
	{
		cout << "������ӽ�����Ϣ�ٲ���" << endl;
		Pause();
		return;
	}
	while (1)
	{
		system("cls");
		cout << "****************************************************************************" << endl;
		//�г�������Ϣ
		ShowGift();
		cout << "����������Ҫ��ȡ�Ľ�������" << endl;
		string str;
		cin >> str;
		int pos = Search(str.c_str());
		if (pos == -1 || Getgift().size() == 0)
		{
			cout << "������Ϣ����";
		}
		else
		{
			//�齱֮ǰ���ȼ��ʣ������
			if (Getgift()[pos].person.size() >= Getgift()[pos].total_gift)
			{
				cout << "����Ҫ��ȡ�Ľ��ڴ�֮ǰ�Ѿ�����˳齱�������ѡ��" << endl;
				cout << "****************************************************************************" << endl;
				cout << "0.�����ϲ�˵�				    1.��ʼ��һ�ֳ齱	" << endl;
				int n;
				cin >> n;
				switch (n)
				{
				case 0:
					break;
				case 1:
					Getgift()[pos].person.clear();//����ý������Ա����
					Write_to_file();
					Game_Gift();
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
					Luck_All(pos);
				else if (c == 'N' || c == 'n')
					Luck_one(pos);
				else
				{
					cout << "�������������ѡ��";
					Game_Gift();
				}
			}
			break;
		}
	}
}