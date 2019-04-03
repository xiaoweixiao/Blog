#include<iostream>
#include<vector>
#include<initializer_list>
using namespace std;
class SmallHeal{
public:
	SmallHeal(const initializer_list<int> l)
		:data(l.begin(), l.end())
	{
	}
	void MakeSmallHeap()
	{
		int i = (data.size() - 2) >> 1;//从最后一个叶子节点的父亲开始，最后一个节点data.size()-1
		while (i >= 0)
		{
			AdjustDown(i);
			i--;
		}
	}
	bool Insert(int num)
	{
		if (num > data[0])
			data[0] = num;
		AdjustDown(0);
		return true;
	}
	void Show()
	{
		for (size_t i = 0; i < data.size(); i++)
			cout << data[i] << "    ";
		cout << endl;
	}
private:
	vector<int> data;
	void AdjustDown(int i);
};
void SmallHeal::AdjustDown(int i)
{
	int p = i;
	size_t child = 2 * i + 1;
	while (child<data.size())
	{
		if (child + 1 < data.size())
			child = data[child + 1] < data[child] ? child + 1 : child;//选小孩子
		if (data[child] < data[p])
			swap(data[child], data[p]);
		p = child;
		child = 2 * p + 1;
	}
}

int main()
{
	SmallHeal b{ 1, 10, 100, 1000, 10000 };
	b.MakeSmallHeap();
	b.Insert(20);
	b.Insert(200);
	b.Insert(2000);
	b.Show();
	system("pause");
	return 0;
}
