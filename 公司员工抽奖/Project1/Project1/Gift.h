#include<iostream>
#include<map>
#include<vector>
#include<fcntl.h>//文件操作
#include <time.h>//系统时间
#include <cmath>
#include"Person.h"
#include"string.h"

using namespace std;

void Pause() {
	cout << endl << "继续请按回车" << endl;
	while (1) {
		fflush(stdin);
		char c = getchar();
		if (c == '\n') {
			break;
		}
	}
}
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
	static Gift CreateGift()
	{
		string name, thing;
		int num;
		cout << "请输入奖品名称：";
		cin >> name;
		cout << "请输入奖品内容：";
		cin >> thing;
		cout << "请设置该奖项需要抽取的数量：";
		cin >> num;
		return Gift(name, thing,num);
	}

	bool Modify_Gift_Num(int n)//修改这种奖品的数目
	{
		total_gift = n;
	}
	bool Write_Gift_inf_to_file()//存储获奖人员信息
	{
		ofstream file;
		file.open("Gift_inf");
		if (file&&person.size()!=0) {
			file << "			该奖项获奖人员信息		" << endl;
			file << "获奖员工编号		" << "		获奖员工姓名		" << "		获奖员工联系方式:";
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
	bool Write_to_Shell()//列出奖品详细信息
	{
		cout << "奖品名称	 " << "	奖品			" << "该奖总数		 " << "		已抽取数" << endl;
		cout << gift_name << "		" << gift << "				" << total_gift << "					" << person.size() << endl;
		if (person.size()!=0)
		{
			cout << "获奖员工编号			" << "		获奖员工姓名		" << "		获奖员工手机:";
			for (auto e : person) 
				cout << e.job_num << "			 " << e.name << "			 " << e.phone_number << endl;
		}
		return true;
	}
};//end of Gift

class Gift_list {
	friend class Gift;
private:
	vector<Gift> gift_;
public:
	static Tool_Person tool_person;
public:
	vector<Gift>& Getgift()
	{
		return gift_;
	}

	void InsertGift(Gift gift)//增加奖项
	{
		if (Search(gift.gift_name) == -1)
			gift_.push_back(gift);
		else
			cout << "你所要插入的奖品已经存在，请进行其他操作" << endl;
	}
	int Search(string name)//通过奖项名称查找奖项
	{
		for (size_t i = 0; i < gift_.size(); i++) {
			if (strcmp(name.c_str(), gift_[i].gift_name.c_str()) == 0)
				return i;
		}
		return -1;
	}
	bool DelGift(Gift gift)//删除奖项
	{
		size_t pos = Search(gift.gift_name);
		if (gift_.size() == 1)
			gift_.clear();
		else if (pos == -1)
		{
			cout << "你说要删除的奖品信息不存在，请核实之后再进行操作" << endl;
		}
		else
		{
			for (size_t i = pos + 1; i < gift_.size(); i++)//0 1
				gift_[i - 1] = gift_[i];
			gift_.pop_back();
		}

		return true;
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
		Read_File();
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
};

Tool_Person Gift_list::tool_person = Tool_Person();//int A::a=10;