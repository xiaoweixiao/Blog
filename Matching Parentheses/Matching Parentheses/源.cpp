//Matching Parentheses
#include<iostream>
#include<string>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		int left = 0;
		for (int i = 0; i<n; i++)
		{
			if (A[i] == '(')
			{
				if (left<0)//ÓÒÀ¨ºÅÏÈÓÚ×óÀ¨ºÅ³öÏÖ
					return false;
				left++;
			}
			else if (A[i] == ')')
			{
				if (left>0)
					left--;
				else
					return false;
			}
			else
				return false;
		}
		if (left == 0)
			return true;
		else
			return false;
	}
};
