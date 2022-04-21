#include<iostream>
#include<string>
#include"STACK.h"
#include"STACK.cpp"
using namespace std;

void bracket_checker(string brackets)
{
	Stack<char> s1, s2;
	for (int i = 0; i < brackets.size(); i++)
	{
		s1.push(brackets[i]);	//Entering whole string in Stack
	}
	int check1 = 0, check2 = 0, check3 = 0;	//check1 is used for ()check2 is used for {}check3 is used for []
	char check;
	if (brackets.size()%2!=0)//Odd number brackets are always false
	{
		cout << "Brackets are not Okay\n";
	}
	else
	{
		for (int i = 0; i < brackets.size() / 2; i++)//Half of the string is added to stack#2 
		{
			check = s1.pop();
			if (check == ')' || check == '(')
			{
				check1++;
			}
			if (check == '}' || check == '{')
			{
				check2++;
			}
			if (check == ']' || check == '[')
			{
				check3++;
			}
			s2.push(check);
		}
		char c1;
		char c2;
		for (int i = 0; i < brackets.size() / 2; i++)//Now by poping from both stacks we can check the validity
		{
			c1 = s1.pop();
			c2 = s2.pop();
			if (c2 == ')' && c1 == '(')//Checking if bracket is closing or not
			{
				check1--;
			}
			if (c2 == '}' && c1 == '{')//Checking if bracket is closing or not
			{
				check2--;
			}
			if (c2 == ']' && c1 == '[')//Checking if bracket is closing or not
			{
				check3--;
			}
		}
		if (check1 == 0 && check2 == 0 && check3 == 0)//At the end if all check are means all brackets are closed
		{
			cout << "Brackets are okay\n";
		}
		else
		{
			cout << "Brackets are not okay\n";
		}
	}
}
int main()
{
	string brackets;
	cout << "Enter String: ";
	cin >> brackets;
	bracket_checker(brackets);
}
