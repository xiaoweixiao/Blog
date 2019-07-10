#include<iostream>
#include<map>
#include<vector>
#include<fcntl.h>//�ļ�����
#include <time.h>//ϵͳʱ��
#include <cmath>
#include"Person.h"
#include"string.h"


using namespace std;
class Gift
{
public:
	Gift(string gift_name_) :gift_name(gift_name_)
	{}
	Person Luck_one()//��һ����
	{
		Person p = YuanGong.PerMap[rand() % YuanGong.PerMap.size()];//����Ա����Χ�ڵ���������ǵ�������������
		person.push_back(p);
		return p;
	}
	bool Luck_All()//һ����ɳ齱�
	{
		int n = total_gift, tmp;
		while (n--)
		{
			Person p = YuanGong.PerMap[rand() % YuanGong.PerMap.size()];//����Ա����Χ�ڵ���������ǵ�������������
			person.push_back(p);
		}
		return true;
	}
	bool Modify_Gift_Num(int n)//�޸Ľ��ĵý���Ŀ
	{
		total_gift = n;
	}
	bool Write_Gift_inf_to_file()
	{
		ofstream file;
		file.open("Gift_inf");
		if (file){
			file << "����" << gift_name << "�ý��ƻ���ȡ����  " << total_gift << "�ý�Ʒ�Ѿ���ȡ������  " << person.size() << endl;
			file << "����Ա��Ϣ" << endl;
			file << "��Ա����ţ�" << "	��Ա��������" << "	��Ա����ϵ��ʽ:";
			for (auto e : person){
				file << e.job_num << "	  " << e.name << "  " << e.phone_number << endl;
			}
		}
	}
	bool Write_to_Shell()
	{
		cout << "����" << gift_name << "�ý��ƻ���ȡ����  " << total_gift << "�ý�Ʒ�Ѿ���ȡ������  " << person.size() << endl;
		cout << "����Ա��Ϣ" << endl;
		cout << "��Ա����ţ�" << "	��Ա��������" << "	��Ա����ϵ��ʽ:";
		for (auto e : person){
			cout << e.job_num << "	  " << e.name << "  " << e.phone_number << endl;
		}
	}
public:
	string gift_name;
	int total_gift;//�ý���ɳ�ȡ������
	vector<Person> person;//����Ա��Ϣ
	Tool_Person YuanGong;//map<int, Person> PerMap;
};
class Gift_list{
private:
	vector<Gift> gift_;
public:
	bool InsertGift(Gift gift)//���ӽ���
	{
		gift_.push_back(gift);
	}
	int Search(Gift gift)
	{
		for (size_t i = 0;i<gift_.size();i++){
			if (strcmp(gift.gift_name.c_str(), gift_[i].gift_name.c_str()) == 0)
			{
				cout << "�ҵ��ý����Ϣ���£�" << endl;
				gift_[i].Write_to_Shell();
				return i;
			}
		}
		cout << "���޴˽������ʵ֮���ٲ�����������" << endl;
		return -1;
	}
	bool DelGift(Gift gift)//ɾ������
	{
		int pos = Search(gift);
		for (int i = pos + 1; pos < gift_.size(); i++)
			gift_[i - 1] = gift_[i];

		gift_.pop_back();
	}
	void ShowGift()//�г�����
	{
		for (auto e : gift_)
			e.Write_to_Shell();
	}
	bool Write_to_file()//���潱��
	{
		ofstream f;
		f.open("All_Gift");
		if (f){
			f << "��Ʒ����	" << "�ý��ƻ���ȡ����		" << "�ý�Ʒ�Ѿ���ȡ������  " << endl;
			for (auto e : gift_){
				f << e.gift_name << "		" << e.total_gift << "			" << e.person.size() << endl;
			}
		}
	}
};