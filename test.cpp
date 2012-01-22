// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void squeeze(char[], char[]);
int getline(char[], int);

int main(int argc, char* argv[])
{
	char s1[100];
	char s2[100];
	cout << "Please input s1: ";
	getline(s1, 100);
	cout << "Please input s2: ";
	getline(s2, 100);
	printf("before squeeze : s1=%s\n",s1);
	printf("before squeeze : s2=%s\n",s2);
	squeeze(s1, s2);
	printf("after squeeze : s1=%s\n", s1);
	return 0;
}

/* squeeze: delete each char in s1 which is in s2 */
void squeeze(char s1[], char s2[])
{
	int i, j, k;
	for ( i = k = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if (s2[j] == '\0')/* end of string - no match */
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i, j;
	for(i = 0, j = 0; (c = getchar())!=EOF && c != '\n' && c != '\0'; ++i)
	{
		if(i < lim - 1)
		{
			s[j++] = c;
		}
	}
	s[j] = '\0';
	return i;
}