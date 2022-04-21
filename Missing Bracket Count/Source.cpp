#include<iostream>
#include<string>
#include"STACK.h"
#include"STACK.cpp"
using namespace std;

void missing_brackets(string brackets)
{
	Stack<char> s1, s2;
	for (int i = 0; i < brackets.size(); i++)
	{
		s1.push(brackets[i]);//Pushing all values in stack
	}
	int check1 = 0, check2 = 0, check3 = 0;
	char check;
	for (int i = 0; i < brackets.size(); i++)
	{
		check = s1.pop();
		if (check == ')')//If closing bracket deteted than increase check
		{
			check1++;
		}
		if (check == '(')//If opeing comes than reduce the check at the end if some bracket is missing check will have its count
		{
			check1--;
		}
		if (check == '}')//If closing bracket deteted than increase check
		{
			check2++;
		}
		if (check == '{')//If opeing comes than reduce the check at the end if some bracket is missing check will have its count
		{
			check2--;
		}
		if (check == ']')//If closing bracket deteted than increase check
		{
			check3++;
		}
		if (check == '[')//If opeing comes than reduce the check at the end if some bracket is missing check will have its count
		{
			check3--;
		}
	}
	if (check1 < 0)//If the values of check is negatice make it positive
	{
		check1 = check1 * (-1);
	}
	if (check2 < 0)//If the values of check is negatice make it positive
	{
		check2 = check2 * (-1);
	}
	if (check3 < 0)//If the values of check is negatice make it positive
	{
		check3 = check3 * (-1);
	}
	cout << "Brackets required are: " << check1 + check2 + check3 << "\n";//At the end the sum shows the required brackets
}
int main()
{
	string brackets;
	cout << "Enter String: ";
	cin >> brackets;
	missing_brackets(brackets);
}
