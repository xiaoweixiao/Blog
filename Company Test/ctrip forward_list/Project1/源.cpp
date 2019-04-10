
//int main()
//{
//	vector<string> in;
//	string s;
//	while (getline(cin,s))
//	{
//		size_t begin = 0;
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			if (s[i] == ',')
//			{
//				string s1 = s.substr(begin, i-begin);
//				in.push_back(s1);
//			}
//		}
//	}
//	for (size_t i = 0; i < in.size(); i++)
//	{
//		for (size_t j = i; j < in.size(); j++)
//		{
//			if (s[i] == s[j])
//			{
//				cout << "false" << endl;
//				return 0;
//			}
//		}
//	}
//	cout << "true" << endl;
//	return 0;
//}

//#include<string>
//#include<iostream>
//using namespace std;
//
//struct Node
//{
//	Node(int val_)
//	:val(val_)
//	{}
//	int val;
//	Node* next;
//};
//struct Slist
//{
//	void Push_back(Node* n)
//	{
//		if (head == nullptr)
//			head = tail = n;
//		else
//		{
//			tail->next = n;
//			tail = tail->next;
//		}
//	}
//public:
//	Node* head=nullptr;
//	Node* tail=nullptr;
//};
//int main()
//{
//	int tmp;
//	int k;
//	Slist l;
//	string s;
//	while (getline(cin,s))
//	{
//		if (s[0] == '[')
//		{
//			for (size_t i = 1; i < s.size(); i += 2)
//			{
//				Node n(s[i] - '0');
//				l.Push_back(&n);
//			}
//		}
//		else
//			k = s[0] - '0';
//	}
//
//	Node* cur = l.head;
//	while (cur&&k--)
//		cur = cur->next;
//
//
//}


//#include<iostream>
//#include<forward_list>
//using namespace std;
//int main()
//{
//	forward_list<int> in;
//	int len;
//	int key;
//	cin >> len;
//	for (int i = 0; i < len; i++)
//	{
//		int tmp;
//		cin >> tmp;
//		forward_list<int>::iterator it;
//		it = in.insert_after(in.before_begin(), tmp);
//
//	}
//}
