// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void squeeze(char[], char[]);
int getline(char[], int);
int htoi(char[]);
int wordlength(void);

int main(int argc, char* argv[])
{
	char s1[100];
	//char s2[100];
	cout << "Please input s1: ";
	getline(s1, 100);
	/*cout << "Please input s2: ";
	getline(s2, 100);
	printf("before squeeze : s1=%s\n",s1);
	printf("before squeeze : s2=%s\n",s2);
	squeeze(s1, s2);
	printf("after squeeze : s1=%s\n", s1);*/
	//printf("htoi : %d\n", htoi(s1));
	printf("wordlength : %d\n", wordlength());
	return 0;
}
