#include<iostream>
using namespace std;
void StrArrange(char *pstr,char *begin);
void StrArrange(char *pstr)
{
	if (pstr == NULL)
		return;
	StrArrange(pstr, pstr);
}
void StrArrange(char *pstr, char *begin)
{
	if (*begin == '\0')
	{
		cout << pstr << " ";
	}
	else
	{
		for (char *pch = begin; *pch != '\0'; pch++)
		{
			char tmp = *pch;
			*pch = *begin;
			*begin = tmp;
			StrArrange(pstr, begin + 1);
			tmp = *pch;
			*pch = *begin;
			*begin = tmp;
		}
	}
}
int main()
{
	char a[] = "asdf";
	StrArrange(a);
	system("pause");
	return 0;
}