//#include<vector>
//#include<algorithm>
//#include<iostream>
//using namespace std;
//class Solution {
//public:
//	/**
//	*	正数数组中的最小不可组成和
//	*	输入：正数数组arr
//	*	返回：正数数组中的最小不可组成和
//	*/
//	int getFirstUnFormedNum(vector<int> arr, int len) {
//		sort(arr.begin(), arr.end());
//		int min = arr[0];
//		int max = 0;
//		for (int i = 0; i < len; i++)
//			max += arr[i];
//
//		for (int i = min; i <= max; i++)
//		{
//			for (int j = 0; arr[j] < i; j++)
//			{
//				i-=
//			}
//		}
//	}
//};


#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n!=0)
	{
		int i = 0;
		while (pow(2, i) <= n)
			i++;
		cout << --i << endl;
	}
	system("pause");
}
