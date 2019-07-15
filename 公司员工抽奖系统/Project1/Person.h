#include<iostream>
#include<vector>
#include<string>
#include<map>
#include <sstream>
#include<fstream>
#include <time.h>//系统时间
#include"string.h"

using namespace std;

void Pause() {
	cout << endl << "请按回车" << endl;
	while (1) {
		fflush(stdin);
		char c = getchar();
		if (c == '\n') {
			break;
		}
	}
}

struct Person {
	
	int job_num;
	string name;
	string phone_number;
};
class Tool_Person {
public:
	Person CreateNode()
	{
		Person p;
		while (1)
		{
			cout << "请输入员工编号：";
			cin >> p.job_num;
			if (PerMap.find(p.job_num) == PerMap.end())
			{
				cout << "亲输入员工姓名：";
				cin >> p.name;
				cout << "请输入员工手机号：";
				cin >> p.phone_number;
				break;
			}
			else
				cout << "输入编号冲突" << endl;
		}
		return p;
	}
	Tool_Person(){}

	void Update() {
		cout << "更新存储文件：y，不更新：n" << endl;
		fflush(stdin);
		char c = getchar();
		if (c == 'y') {
			Write_to_File();
		}
	}
	void Read_File() {
		ifstream ifs("Table_Of_Information.txt", ios::in);
		char line[1024] = { 0 };
		for (int i = 0; ifs.getline(line, sizeof(line)); ++i) {
			if (i == 0) {
				continue;
			}
			stringstream word(line);
			Person node;
			word >> node.job_num;
			word >> node.name;
			word >> node.phone_number;
			InsertNode(node);
		}
		ifs.clear();
		ifs.close();
	}

	bool InsertNode(Person node) {//添加
		if (PerMap.find(node.job_num) != PerMap.end()) {
			cout << "工号冲突，无法加入" << endl;
			return false;
		}
		else {
			PerMap.insert(pair<int, Person>(node.job_num, node));
			
		}
		return true;
	}
	bool DeleteNode(int n) {//删除
		
		if (PerMap.find(n) == PerMap.end()) {
			cout << "人物不存在，无法删除" << endl;
			return false;
		}
		else {
			PerMap.erase(n);
			
		}
		return true;
	}
	bool ModifyNode(Person node) {//修改
		if (PerMap.find(node.job_num) == PerMap.end()) {
			cout << "人员不存在，无法操作" << endl;
			return false;
		}
		else {
			PerMap[node.job_num] = node;
			cout << "修改成功" << endl;
		}
		return true;
	}
	bool SearchPerson_Jobnum(int job_nums) {//按工号查找
		if (PerMap.find(job_nums) == PerMap.end()) {
			cout << "此工号不存在，无法删除" << endl;
			return false;
		}
		else {
			cout << "工号：" << job_nums << "姓名：" << PerMap[job_nums].name << "手机号：" << PerMap[job_nums].phone_number << endl;
			return true;
		}
	}
	bool SearchPerson_Phone(string phone_nums) {//按手机号查找
		for (auto& e : PerMap) {
			if (strcmp(e.second.phone_number.c_str(), phone_nums.c_str()) == 0) {
				cout << "工号：" << e.first << "姓名：" << e.second.name << "手机号：" << phone_nums << endl;
				return true;
			}
		}
		cout << "此电话号不存在" << endl;
		return false;
	}

	bool SearchPerson_Name(string names) {//按名字查找
		bool find = 0;
		for (auto& e : PerMap) {
			if (e.second.name == names)
			{
				find = 1;
				cout << "工号：" << e.first << "姓名：" << names << "手机号：" << e.second.phone_number << endl;
			}
		}
		if (find == 1)
		{

			cout << "查找完毕" << endl;
			return true;
		}
		else
		{
			cout << "此人名不存在" << endl;
			return false;
		}
	}
	bool Write_to_File() {//文件写入
		ofstream ofs;
		ofs.open("Table_Of_Information.txt");
		if (ofs) {
			ofs << "工号    " << "    姓名    " << "    电话号码    " << endl;
			for (auto& e : PerMap) {
				ofs << e.second.job_num << "          " << e.second.name << "      " << e.second.phone_number << endl;
			}
		}
		else {
			ofs.close();
			return false;
		}
		ofs.close();
		return true;
	}
	map<int, Person>& GetPerMap()
	{
		return PerMap;
	}
	void Print()
	{
		cout << "工号" << "			" << "姓名" << "		" << "手机" << endl;
		for (auto e : PerMap)
			cout << e.second.job_num <<"		"<< e.second.name<<"		" << e.second.phone_number << endl;
		Pause();
	}
private:
	map<int, Person> PerMap;
public:
	void Search();
	void Person_Set();
};
void Tool_Person::Search()
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
				  SearchPerson_Jobnum(n);
				  Pause();
		}
			break;
		case 2:
		{
				  system("cls");
				  cout << "请输入你所要查询的员工姓名:";
				  string str;
				  cin >> str;
				  SearchPerson_Name(str);
				  Pause();
		}
			break;
		case 3:
		{
				  system("cls");
				  cout << "请输入你所要查询的员工手机号:";
				  string str;
				  cin >> str;
				  SearchPerson_Phone(str);
				  Pause();
		}
			break;
		default:
			system("cls");
			cout << "选择错误" << endl;
			Pause();
			break;
		}
		if (n == 0) {
			break;
		}
		system("cls");
	}
}

void Tool_Person::Person_Set()
{
	bool had_save = 0;
	while (1) {
		system("cls");
		cout << endl << "****************************************************************************" << endl;
		cout << "1.员工信息导入					          2.添加员工	" << endl;
		cout << "3.员工查找						  4.修改员工信息" << endl;
		cout << "5.删除某员工						  6.员工信息保存至文件" << endl;
		cout << "7.显示员工信息						  0.返回上层菜单" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
			system("cls");
			Read_File();
			cout << "已经完成员工信息导入" << endl;
			Pause();
			break;
		case 2:
			system("cls");
			InsertNode(CreateNode());
			cout << "添加成功" << endl;
			Pause();
			break;
		case 3:
			Search();
			break;
		case 4:
			ModifyNode(CreateNode());
			Pause();
			break;
		case 5:
		{
				  int n;
				  cout << "请输入想要删除的员工编号" << endl;
				  cin >> n;
				  DeleteNode(n);
				  cout << "删除成功" << endl;
				  Pause();
		}
			
			break;
		case 6:
			Write_to_File();
			had_save = 1;
			cout << "已保存至文件" << endl;
			Pause();
			break;
		case 7:
			Print();
			break;
		default:
			cout << "输入错误" << endl;
			Pause();
			break;
		}
		if (n == 0) {
			if (had_save == 0)
				Update();
			break;
		}
		system("cls");
	}
}