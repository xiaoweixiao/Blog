
//3_7µÚÒ»Ìâ
#include<iostream>
using namespace std;

int main()
{
	int sub1, sub2, add1, add2;
	cin >> sub1 >> sub2 >> add1 >> add2;
	int A, B, C;
	B = (add1 - sub1) / 2;
	A = add1 - B;
	C = add2 - B;
	if (A != sub1 + B || C != B - sub2)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << A << ' ' << B << ' ' << C << endl;
	system("pause");
	return 0;
}