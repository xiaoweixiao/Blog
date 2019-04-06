//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	/**
//	*  奇数位上都是奇数或者偶数位上都是偶数
//	*  输入：数组arr，长度大于2
//	*  len：arr的长度
//	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
//	*/
//	void oddInOddEvenInEven(vector<int>& arr, int len) {
//		int even = 0;
//		int odd = 1;
//		while (even<len&&odd<len)
//		{
//			if (arr[even] % 2 == 0)//偶数位是偶数
//				even += 2;
//			if (arr[odd] % 2 == 1)//奇数位是奇数
//				odd += 2;
//			if (arr[even] % 2 == 1 && arr[odd] % 2 == 0)//偶数位是奇数，并且奇数位是偶数
//			{
//				swap(arr[even], arr[odd]);
//				even += 2, odd += 2;
//			}
//		}
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> in{ 1, 2, 3, 4 };
//	s.oddInOddEvenInEven(in,4);
//}

#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n != 0)
	{
		int left = 0;
		int first = n / 5;
		while (n)
		{
			left += n % 5;
			n /= 5;
		}
		cout << first << ' ' << left << endl;
	}
}