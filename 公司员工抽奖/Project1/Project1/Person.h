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
	bool InsertNode(Person& node) {//���
		if (PerMap.find(node.job_num) != PerMap.end()) {
			return false;
		}
		else {
			PerMap.insert(pair<int, Person>(node.job_num, node));
		}
		return true;
	}
	bool DeleteNode(Person& node) {//ɾ��
		if (PerMap.find(node.job_num) == PerMap.end()) {
			return false;
		}
		else {
			PerMap.erase(node.job_num);
		}
		return true;
	}
	bool ModifyNode(Person& node) {//�޸�
		if (PerMap.find(node.job_num) == PerMap.end()) {
			return false;
		}
		else {
			PerMap[node.job_num] = node;
		}
		return true;
	}
	bool SearchPerson_Jobnum(int job_nums) {//�����Ų���
		if (PerMap.find(job_nums) == PerMap.end()) {
			cout << "�˹��Ų����ڣ��޷�ɾ��" << endl;
			return false;
		}
		else {
			cout << "���ţ�" << job_nums << "������" << PerMap[job_nums].name << "�ֻ��ţ�" << PerMap[job_nums].phone_number << endl;
			return true;
		}
	}
	bool SearchPerson_Phone(int phone_nums) {//���ֻ��Ų���
		for (auto& e : PerMap) {
			if (e.second.phone_number == phone_nums) {
				cout << "���ţ�" << e.first << "������" << e.second.name << "�ֻ��ţ�" << phone_nums << endl;
				return true;
			}
		}
		cout << "�˵绰�Ų����ڣ��޷�ɾ��" << endl;
		return false;
	}

	bool SearchPerson_Name(string names) {//�����ֲ���
		for (auto& e : PerMap) {
			if (e.second.name == names) {
				cout << "���ţ�" << e.first << "������" << names << "�ֻ��ţ�" << e.second.phone_number << endl;
				return true;
			}
		}
		cout << "�����������ڣ��޷�ɾ��" << endl;
		return false;
	}
	bool Write_to_File() {//�ļ�д��
		ofstream ofs;
		ofs.open("Table_Of_Information");
		if (ofs) {
			ofs << "����    " << "    ����    " << "    �绰����    " << endl;
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