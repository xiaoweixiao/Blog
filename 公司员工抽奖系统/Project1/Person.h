#include<iostream>
#include<vector>
#include<string>
#include<map>
#include <sstream>
#include<fstream>
#include <time.h>//ϵͳʱ��
#include"string.h"

using namespace std;

void Pause() {
	cout << endl << "�밴�س�" << endl;
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
			cout << "������Ա����ţ�";
			cin >> p.job_num;
			if (PerMap.find(p.job_num) == PerMap.end())
			{
				cout << "������Ա��������";
				cin >> p.name;
				cout << "������Ա���ֻ��ţ�";
				cin >> p.phone_number;
				break;
			}
			else
				cout << "�����ų�ͻ" << endl;
		}
		return p;
	}
	Tool_Person(){}

	void Update() {
		cout << "���´洢�ļ���y�������£�n" << endl;
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

	bool InsertNode(Person node) {//���
		if (PerMap.find(node.job_num) != PerMap.end()) {
			cout << "���ų�ͻ���޷�����" << endl;
			return false;
		}
		else {
			PerMap.insert(pair<int, Person>(node.job_num, node));
			
		}
		return true;
	}
	bool DeleteNode(int n) {//ɾ��
		
		if (PerMap.find(n) == PerMap.end()) {
			cout << "���ﲻ���ڣ��޷�ɾ��" << endl;
			return false;
		}
		else {
			PerMap.erase(n);
			
		}
		return true;
	}
	bool ModifyNode(Person node) {//�޸�
		if (PerMap.find(node.job_num) == PerMap.end()) {
			cout << "��Ա�����ڣ��޷�����" << endl;
			return false;
		}
		else {
			PerMap[node.job_num] = node;
			cout << "�޸ĳɹ�" << endl;
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
	bool SearchPerson_Phone(string phone_nums) {//���ֻ��Ų���
		for (auto& e : PerMap) {
			if (strcmp(e.second.phone_number.c_str(), phone_nums.c_str()) == 0) {
				cout << "���ţ�" << e.first << "������" << e.second.name << "�ֻ��ţ�" << phone_nums << endl;
				return true;
			}
		}
		cout << "�˵绰�Ų�����" << endl;
		return false;
	}

	bool SearchPerson_Name(string names) {//�����ֲ���
		bool find = 0;
		for (auto& e : PerMap) {
			if (e.second.name == names)
			{
				find = 1;
				cout << "���ţ�" << e.first << "������" << names << "�ֻ��ţ�" << e.second.phone_number << endl;
			}
		}
		if (find == 1)
		{

			cout << "�������" << endl;
			return true;
		}
		else
		{
			cout << "������������" << endl;
			return false;
		}
	}
	bool Write_to_File() {//�ļ�д��
		ofstream ofs;
		ofs.open("Table_Of_Information.txt");
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
	map<int, Person>& GetPerMap()
	{
		return PerMap;
	}
	void Print()
	{
		cout << "����" << "			" << "����" << "		" << "�ֻ�" << endl;
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
		cout << "����������Ҫ�Ĳ�ѯ��ʽ��" << endl;
		cout << "1.Ա����Ų���						2.Ա����������	" << endl;
		cout << "3.Ա���ֻ��Ų���				    0.������һ��˵�" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
		{
				  system("cls");
				  cout << "����������Ҫ��ѯ��Ա�����:";
				  int n;
				  cin >> n;
				  SearchPerson_Jobnum(n);
				  Pause();
		}
			break;
		case 2:
		{
				  system("cls");
				  cout << "����������Ҫ��ѯ��Ա������:";
				  string str;
				  cin >> str;
				  SearchPerson_Name(str);
				  Pause();
		}
			break;
		case 3:
		{
				  system("cls");
				  cout << "����������Ҫ��ѯ��Ա���ֻ���:";
				  string str;
				  cin >> str;
				  SearchPerson_Phone(str);
				  Pause();
		}
			break;
		default:
			system("cls");
			cout << "ѡ�����" << endl;
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
		cout << "1.Ա����Ϣ����					          2.���Ա��	" << endl;
		cout << "3.Ա������						  4.�޸�Ա����Ϣ" << endl;
		cout << "5.ɾ��ĳԱ��						  6.Ա����Ϣ�������ļ�" << endl;
		cout << "7.��ʾԱ����Ϣ						  0.�����ϲ�˵�" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 0:
			break;
		case 1:
			system("cls");
			Read_File();
			cout << "�Ѿ����Ա����Ϣ����" << endl;
			Pause();
			break;
		case 2:
			system("cls");
			InsertNode(CreateNode());
			cout << "��ӳɹ�" << endl;
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
				  cout << "��������Ҫɾ����Ա�����" << endl;
				  cin >> n;
				  DeleteNode(n);
				  cout << "ɾ���ɹ�" << endl;
				  Pause();
		}
			
			break;
		case 6:
			Write_to_File();
			had_save = 1;
			cout << "�ѱ������ļ�" << endl;
			Pause();
			break;
		case 7:
			Print();
			break;
		default:
			cout << "�������" << endl;
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