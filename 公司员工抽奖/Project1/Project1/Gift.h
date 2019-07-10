#include<iostream>
#include<map>
#include<vector>
#include<fcntl.h>//文件操作
#include <time.h>//系统时间
#include <cmath>
#include"Person.h"
#include"string.h"


using namespace std;
class Gift
{
public:
	Gift(string gift_name_) :gift_name(gift_name_)
	{}
	Person Luck_one()//抽一个奖
	{
		Person p = YuanGong.PerMap[rand() % YuanGong.PerMap.size()];//生成员工范围内的随机数，记得主函数置种子
		person.push_back(p);
		return p;
	}
	bool Luck_All()//一次完成抽奖活动
	{
		int n = total_gift, tmp;
		while (n--)
		{
			Person p = YuanGong.PerMap[rand() % YuanGong.PerMap.size()];//生成员工范围内的随机数，记得主函数置种子
			person.push_back(p);
		}
		return true;
	}
	bool Modify_Gift_Num(int n)//修改奖的得奖数目
	{
		total_gift = n;
	}
	bool Write_Gift_inf_to_file()
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
	bool Write_to_Shell()
	{
		cout << "礼物" << gift_name << "该奖计划抽取总数  " << total_gift << "该奖品已经抽取的人数  " << person.size() << endl;
		cout << "获奖人员信息" << endl;
		cout << "获奖员工编号：" << "	获奖员工姓名：" << "	获奖员工联系方式:";
		for (auto e : person){
			cout << e.job_num << "	  " << e.name << "  " << e.phone_number << endl;
		}
	}
public:
	string gift_name;
	int total_gift;//该奖项可抽取的数量
	vector<Person> person;//获奖人员信息
	Tool_Person YuanGong;//map<int, Person> PerMap;
};
class Gift_list{
private:
	vector<Gift> gift_;
public:
	bool InsertGift(Gift gift)//增加奖项
	{
		gift_.push_back(gift);
	}
	int Search(Gift gift)
	{
		for (size_t i = 0;i<gift_.size();i++){
			if (strcmp(gift.gift_name.c_str(), gift_[i].gift_name.c_str()) == 0)
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
		int pos = Search(gift);
		for (int i = pos + 1; pos < gift_.size(); i++)
			gift_[i - 1] = gift_[i];

		gift_.pop_back();
	}
	void ShowGift()//列出奖项
	{
		for (auto e : gift_)
			e.Write_to_Shell();
	}
	bool Write_to_file()//保存奖项
	{
		ofstream f;
		f.open("All_Gift");
		if (f){
			f << "奖品名称	" << "该奖计划抽取总数		" << "该奖品已经抽取的人数  " << endl;
			for (auto e : gift_){
				f << e.gift_name << "		" << e.total_gift << "			" << e.person.size() << endl;
			}
		}
	}
};