#include"Person.h"

class Gift//奖品类
{
public:
	string gift_name;//奖项名称
	string gift;//奖品内容
	size_t total_gift;//该奖项可抽取的数量
	vector<Person> person;//获奖人员信息
public:
	Gift(){}
	Gift(string gift_name_, string gift_, int n, int id = 0) 
		:gift_name(gift_name_)
		, gift(gift_)
		, total_gift(n)
		, person(vector<Person>())
	{}
	

	bool Modify_Gift_Num(int n)//修改这种奖品的数目
	{
		total_gift = n;
	}
	bool Write_Gift_inf_to_file()//存储获奖人员信息
	{
		ofstream file;
		file.open("Gift_inf");
		if (file&&person.size()!=0) {
			file << "获奖员工编号		" << "		获奖员工姓名		" << "		获奖员工联系方式" << endl;
			for (auto e : person) {
				file << e.job_num << "				" << e.name << "				  " << e.phone_number << endl;
			}
		}
		return true;
	}
	bool ReadGiftInf()//读取获奖人员信息
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
	bool Write_Gift_People_to_Shell()//打印获奖人员信息
	{
		if (person.size()>0)
		{
			cout << gift_name << endl;
			cout << "获奖员工编号			" << "		获奖员工姓名		" << "		获奖员工手机" << endl;
			for (auto& e : person) 
				cout << e.job_num << "			 " << e.name << "			 " << e.phone_number << endl;
		}
		cout << endl;
		return true;
	}

	bool Write_to_Shell()//列出奖品详细信息
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
			cout << "请输入奖品名称：";
			cin >> name;
			int pos = Search(name);
			if (pos != -1)
				cout << "输入错误，该奖项已经存在" << endl;
			else
			{
				cout << "请输入奖品内容：";
				cin >> thing;
				cout << "请设置该奖项需要抽取的数量：";
				cin >> num;
				break;
			}
		}
		return Gift(name, thing, num);
	}
	void InsertGift(Gift gift)//增加奖项
	{
		gift_.push_back(gift);
	}
	int Search(string name)//通过奖项名称查找奖项
	{
		for (size_t i = 0; i < gift_.size(); i++) {
			if (strcmp(name.c_str(), gift_[i].gift_name.c_str()) == 0)
				return i;
		}
		return -1;
	}
	bool DelGift(string str)//删除奖项
	{
		int pos = Search(str);
		if (gift_.size() == 1)
			gift_.clear();
		else if (pos == -1)
		{
			cout << "你说要删除的奖品名称不存在，请重新输入:" << endl;
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
		cout << "更新存储文件：y，不更新：n" << endl;
		fflush(stdin);
		char c = getchar();
		if (c == 'y') {
			Write_to_file();
		}
	}
	void Read_File()//从文件读取奖品信息（包括该奖品获奖人员信息）
	{
		gift_.clear();//读取文件之前，将数组置空，以文件数据为准
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
	void ShowGift()//列出所有奖项
	{
		cout << "奖品名称	 " << "奖品			" << "该奖总数		 " << "		已抽取数" << endl;
		for (auto e : gift_)
			e.Write_to_Shell();
		Pause();
	}
	bool Write_to_file()//保存奖项
	{
		ofstream f;
		f.open("All_Gift");
		if (f) {
			f << "奖品名称		" << "奖品内容	" << "该奖计划抽取总数		" << "该奖品已经抽取的人数  " << endl;
			for (auto e : gift_) {
				f << e.gift_name << "		" << e.gift << "		" << e.total_gift << "			" << e.person.size() << endl;
				e.Write_Gift_inf_to_file();//保存奖项时候，对应奖项抽取人员信息也要更新
			}
		}
		return true;
	}
	bool  Luck_one(int n)//抽一个奖
	{
		if (Gift_list::tool_person.GetPerMap().size() == 0)
		{
			Gift_list::tool_person.Read_File();
			if (Gift_list::tool_person.GetPerMap().size() == 0)
			{
				cout << "请先添加人员信息，再进行抽奖！！" << endl;
				Pause();
			}
		}
		while (1)
		{
			int pos = rand() % 20 + 1;//生成的1~20的随机数
			//拿到随机数下标，使用下标去map取人员，先判断下标是否存在
			if (Gift_list::tool_person.GetPerMap().find(pos) == Gift_list::tool_person.GetPerMap().end())
				;//map中不存在该人员

			else
			{
				Getgift()[n].person.push_back(Gift_list::tool_person.GetPerMap()[pos]);//该奖项人员发生变化
				//抽取人员抽取奖品之后需要从map中删除
				Gift_list::tool_person.DeleteNode(pos);
				//打印获奖人员信息
				cout << "工号：" << Getgift()[n].person.back().job_num << endl;
				cout << "姓名：" << Getgift()[n].person.back().name << endl;
				cout << "手机：" << Getgift()[n].person.back().phone_number << endl;
				cout << "恭喜上述员工获得" << Getgift()[n].gift_name << endl;
				cout << "奖品是" << Getgift()[n].gift << endl;
				Pause();
				return true;
			}
		}

	}

	bool Luck_All(int n)//一次完成抽奖活动
	{
		int size = Getgift()[n].total_gift;//总共要抽取的奖数目
		while (size--)
			Luck_one(n);
		return true;
	}
public:
	void Gift_Set();
	void ModifyGift();//修改奖项
	void Game_Gift();//抽奖操作选择菜单
};
vector<Gift> Gift_list::gift_ = vector<Gift>();

Tool_Person Gift_list::tool_person = Tool_Person();//int A::a=10;

void Gift_list::ModifyGift()//修改奖项
{
	ShowGift();
	cout << "请输入你想要修改的奖项名称" << endl;
	string str;
	cin >> str;
	while (1){
		int n = Search(str);
		if (n == -1)
		{
			cout << "输入错误!请重新输入：" << endl;
			cin >> str;
		}
		Getgift()[n] = CreateGift();
		cout << "修改成功" << endl; 
		break;
	}
}
void Gift_list::Gift_Set()
{
	bool had_save = 0;
	while (1){
		system("cls");
		cout << "****************************************************************************" << endl;
		cout << "1.添加奖项							2.修改奖项	" << endl;
		cout << "3.保存奖项							4.删除奖项" << endl;
		cout << "5.列出奖项信息				        0.返回上层菜单" << endl;
		cout << "6.从上次保存的奖项文件中读取奖项信息" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
			InsertGift(CreateGift());
			Write_to_file();
			cout << "添加奖项信息成功，已写入文件" << endl;
			Pause();
			break;
		case 2:
			ModifyGift();
			break;
		case 3:
			Write_to_file();//写入文件保存了
			had_save = 1;
			cout << "保存到文件成功！！" << endl;
			Pause();
			break;
		case 4:
		{
				  cout << "请输入想要删除的奖项名称:";
				  string str;
				  cin >> str;
				  DelGift(str);
				  cout << "删除成功" << endl;
				  Pause();
		}
			break;
		case 5:
			//列出奖项信息
			ShowGift();
			break;
		case 6:
			Read_File();
			cout << "已读取至内存，可继续操作" << endl;
			Pause();
			break;
		default:
			cout << "输入错误" << endl;
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
void Gift_list::Game_Gift()//抽奖操作选择菜单
{
	if (gift_.size() == 0)
	{
		cout << "请先添加奖项信息再操作" << endl;
		Pause();
		return;
	}
	while (1)
	{
		system("cls");
		cout << "****************************************************************************" << endl;
		//列出奖项信息
		ShowGift();
		cout << "请输入你想要抽取的奖项名称" << endl;
		string str;
		cin >> str;
		int pos = Search(str.c_str());
		if (pos == -1 || Getgift().size() == 0)
		{
			cout << "输入信息有误";
		}
		else
		{
			//抽奖之前，先检查剩余名额
			if (Getgift()[pos].person.size() >= Getgift()[pos].total_gift)
			{
				cout << "你想要抽取的奖在此之前已经完成了抽奖，你可以选择：" << endl;
				cout << "****************************************************************************" << endl;
				cout << "0.返回上层菜单				    1.开始新一轮抽奖	" << endl;
				int n;
				cin >> n;
				switch (n)
				{
				case 0:
					break;
				case 1:
					Getgift()[pos].person.clear();//清除该奖项的人员名单
					Write_to_file();
					Game_Gift();
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
					Luck_All(pos);
				else if (c == 'N' || c == 'n')
					Luck_one(pos);
				else
				{
					cout << "输入错误，请重新选择：";
					Game_Gift();
				}
			}
			break;
		}
	}
}