#include<iostream>
#include<vector>
#include<string>
#include<map>
#include <sstream>
#include<fstream>
using namespace std;
struct Person {
	static Person CreateNode()
	{
		Person p;
		cout << "请输入员工编号：";
		cin >> p.job_num;
		cout << "亲输入员工姓名：";
		cin >> p.name;
		cout << "请输入员工手机号：";
		cin >> p.phone_number;
		return p;
	}
	int job_num;
	string name;
	string phone_number;
};
class Tool_Person {
public:
	Tool_Person(){}

	void Update() {
		cout << "更新存储文件：y，不更新：n" << endl;
		getchar();
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
			cout << "添加成功" << endl;
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
			cout << "删除成功" << endl;
		}
		return true;
	}
	bool ModifyNode(Person node) {//修改
		if (PerMap.find(node.job_num) == PerMap.end()) {
			cout << "人物不存在，无法删除" << endl;
			return false;
		}
		else {
			PerMap[node.job_num] = node;
			cout << "修改成功成功" << endl;
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
		cout << "此电话号不存在，无法删除" << endl;
		return false;
	}

	bool SearchPerson_Name(string names) {//按名字查找
		for (auto& e : PerMap) {
			if (e.second.name == names) {
				cout << "工号：" << e.first << "姓名：" << names << "手机号：" << e.second.phone_number << endl;
				return true;
			}
		}
		cout << "此人名不存在，无法删除" << endl;
		return false;
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
private:
	map<int, Person> PerMap;
};