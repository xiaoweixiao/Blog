#include<iostream>
#include<map>
#include<vector>
#include<fcntl.h>//文件操作
#include <time.h>//系统时间
#include <cmath>
#include"Person.h"
#include"string.h"

using namespace std;

class Gift//奖品类
{
public:
	Gift(string gift_name_,string gift_) :gift_name(gift_name_), gift(gift_)
	{}
	static Gift CreateGift()
	{
		string name, thing;
		cout << "请输入奖品名称：";
		cin >> name;
		cout << "请输入奖品内容：";
		cin >> thing;
		return Gift(name, thing);
	}
	
	bool Modify_Gift_Num(int n)//修改这种奖品的数目
	{
		total_gift = n;
	}
	bool Write_Gift_inf_to_file()//奖品详细信息写入文件
	{
		ofstream file;
		file.open("Gift_inf");
		if (file){
			file << "礼物" << gift_name << "该奖计划抽取总数  " << total_gift << "该奖品已经抽取的人数  " << person.size() << endl;
			file << "获奖人员信息" << endl;
			file << "获奖员工编号：" << "	获奖员工姓名：" << "	获奖员工联系方式:";
			for (auto e : person){
				file << e.job_num << "	  " << e.name << "  " << e.phone_number << endl;
			}
		}
	}
	bool Write_to_Shell()//列出奖品详细信息
	{
		cout << "礼物" << gift_name << "该奖计划抽取总数  " << total_gift << "该奖品已经抽取的人数  " << person.size() << endl;
		cout << "获奖人员信息" << endl;
		cout << "获奖员工编号：" << "	获奖员工姓名：" << "	获奖员工联系方式:";
		for (auto e : person){
			cout << e.job_num << "	  " << e.name << "  " << e.phone_number << endl;
		}
		system("pause");
		return true;
	}
	string& GetGiftName()
	{
		return gift_name;
	}
	size_t GetTotalGift()
	{
		return total_gift;
	}
	vector<Person>& GetPeople()
	{
		return person;
	}
private:
	string gift_name;//奖项名称
	string gift;//奖品
	size_t total_gift;//该奖项可抽取的数量
	vector<Person> person;//获奖人员信息
};//end of Gift

class Gift_list{
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
		gift_.push_back(gift);
	}
	int Search(Gift gift)//查找奖项
	{
		for (size_t i = 0;i<gift_.size();i++){
			if (strcmp(gift.GetGiftName().c_str(), gift_[i].GetGiftName().c_str()) == 0)
			{
				cout << "找到该奖项，信息如下：" << endl;
				gift_[i].Write_to_Shell();
				return i;
			}
		}
		cout << "查无此奖，请核实之后再操作！！！！" << endl;
		return -1;
	}
	bool DelGift(Gift gift)//删除奖项
	{
		size_t pos = Search(gift);
		if (gift_.size() == 1)
			gift_.clear();
		else
		{
			for (size_t i = pos + 1; i < gift_.size(); i++)//0 1
				gift_[i - 1] = gift_[i];
			gift_.pop_back();
		}
		
		return true;
	}
	void ShowGift()//列出所有奖项
	{
		for (auto e : gift_)
			e.Write_to_Shell();
		getchar();
	}
	bool Write_to_file()//保存奖项
	{
		ofstream f;
		f.open("All_Gift");
		if (f){
			f << "奖品名称	" << "该奖计划抽取总数		" << "该奖品已经抽取的人数  " << endl;
			for (auto e : gift_){
				f << e.GetGiftName() << "		" << e.GetTotalGift() << "			" << e.GetPeople().size() << endl;
			}
		}
		return true;
	}
};

Tool_Person Gift_list::tool_person = Tool_Person();//int A::a=10;