#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>
using namespace std;
struct Person {
	int job_num;
	string name;
	long long phone_number;
};
class Tool_Person {
public:
	bool InsertNode(Person& node) {//添加
		if (PerMap.find(node.job_num) != PerMap.end()) {
			return false;
		}
		else {
			PerMap.insert(pair<int, Person>(node.job_num, node));
		}
		return true;
	}
	bool DeleteNode(Person& node) {//删除
		if (PerMap.find(node.job_num) == PerMap.end()) {
			return false;
		}
		else {
			PerMap.erase(node.job_num);
		}
		return true;
	}
	bool ModifyNode(Person& node) {//修改
		if (PerMap.find(node.job_num) == PerMap.end()) {
			return false;
		}
		else {
			PerMap[node.job_num] = node;
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
	bool SearchPerson_Phone(int phone_nums) {//按手机号查找
		for (auto& e : PerMap) {
			if (e.second.phone_number == phone_nums) {
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
		ofs.open("Table_Of_Information");
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
public:
	map<int, Person> PerMap;
};