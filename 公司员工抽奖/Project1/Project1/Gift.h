#include<iostream>
#include<map>
#include<vector>
#include<fcntl.h>//�ļ�����
#include <time.h>//ϵͳʱ��
#include <cmath>
#include"Person.h"
#include"string.h"

using namespace std;

class Gift//��Ʒ��
{
public:
	Gift(string gift_name_,string gift_) :gift_name(gift_name_), gift(gift_)
	{}
	static Gift CreateGift()
	{
		string name, thing;
		cout << "�����뽱Ʒ���ƣ�";
		cin >> name;
		cout << "�����뽱Ʒ���ݣ�";
		cin >> thing;
		return Gift(name, thing);
	}
	
	bool Modify_Gift_Num(int n)//�޸����ֽ�Ʒ����Ŀ
	{
		total_gift = n;
	}
	bool Write_Gift_inf_to_file()//��Ʒ��ϸ��Ϣд���ļ�
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
	bool Write_to_Shell()//�г���Ʒ��ϸ��Ϣ
	{
		cout << "����" << gift_name << "�ý��ƻ���ȡ����  " << total_gift << "�ý�Ʒ�Ѿ���ȡ������  " << person.size() << endl;
		cout << "����Ա��Ϣ" << endl;
		cout << "��Ա����ţ�" << "	��Ա��������" << "	��Ա����ϵ��ʽ:";
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
	string gift_name;//��������
	string gift;//��Ʒ
	size_t total_gift;//�ý���ɳ�ȡ������
	vector<Person> person;//����Ա��Ϣ
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

	void InsertGift(Gift gift)//���ӽ���
	{
		gift_.push_back(gift);
	}
	int Search(Gift gift)//���ҽ���
	{
		for (size_t i = 0;i<gift_.size();i++){
			if (strcmp(gift.GetGiftName().c_str(), gift_[i].GetGiftName().c_str()) == 0)
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
	void ShowGift()//�г����н���
	{
		for (auto e : gift_)
			e.Write_to_Shell();
		getchar();
	}
	bool Write_to_file()//���潱��
	{
		ofstream f;
		f.open("All_Gift");
		if (f){
			f << "��Ʒ����	" << "�ý��ƻ���ȡ����		" << "�ý�Ʒ�Ѿ���ȡ������  " << endl;
			for (auto e : gift_){
				f << e.GetGiftName() << "		" << e.GetTotalGift() << "			" << e.GetPeople().size() << endl;
			}
		}
		return true;
	}
};

Tool_Person Gift_list::tool_person = Tool_Person();//int A::a=10;