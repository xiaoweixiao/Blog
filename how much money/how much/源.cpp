#include<iostream>
using namespace std;
class Date{
public:
	Date(int year_, int month_, int day_)
		:year(year_)
		, month(month_)
		, day(day_)
	{}
	int GetMonthDay()
	{
		int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			arr[2]++;
		return arr[month];
	}
	Date operator++()
	{
		if (++day>GetMonthDay())
		{
			day -= GetMonthDay();
			if (++month==13)
			{
				month = 1;
				year++;
			}
		}
		return *this;
	}
	bool operator!=(Date&  d)
	{
		if (d.year == year&&d.month == month&&d.day == day)
			return false;
		else
			return true;
	}
public:
	int year, month, day;
};
int main()
{
	int year1, month1, day1, year2, month2, day2;
	int money = 0;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		Date d1(year1, month1, day1), d2(year2, month2, day2);
		while (d1!=d2)
		{
			money+=2;
			if (d1.month == 2|| d1.month == 3|| d1.month == 5|| d1.month == 7|| d1.month == 11)
				money--;
			++d1;
		}
		money+=2;
			if (d1.month == 2|| d1.month == 3|| d1.month == 5|| d1.month == 7|| d1.month == 11)
				money--;
		cout << money << endl;
	}
}