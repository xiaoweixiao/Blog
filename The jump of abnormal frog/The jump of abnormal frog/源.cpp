#include<iostream>
//f(n)=1+2+3+...+f(n-1)
//f(n-1)=1+2+3...+f(n-2)
//f(n)=2*f(n-1)
class Solution {
public:
	int jumpFloorII(int number) {
		if (number < 1)
			return 0;
		else if (number == 1)
			return 1;
		else
			return pow(2, number - 1);
	}
};