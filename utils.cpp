#include "stdafx.h"

using namespace std;

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

/* htoi: convert hexadecimal string s to integer */
int htoi(char s[])
{
	int hexdigit, i, inhex, n;
	i = 0;
	if(s[i] == '0') {/* skip optional 0x or 0X */
		++i;
		if(s[i] == 'x' || s[i] == 'X')
			++i;
	}
	n = 0;/* integer value to be returned */
	inhex = YES;/* assume valid hexadecimal digit */
	for ( ; inhex == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = NO;/* not a valid hexadecimal digit */
		if (inhex == YES)
			n = 16 * n + hexdigit;
	}
	return n;
}

/* any: return first location in s1 where any char from s2 occurs */
int any(char s1[], char s2[])
{
	int i, j;
	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])/* match found? */
				return i;/* location first match */
	return -1;/* otherwise, no match */
}

/* setbits: set n bits of x at position p with bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p+1-n)) | 
		(y & ~(~0 << n)) << (p+1-n);
}

/* invert: inverts the n bits of x that begin at position p */
unsigned invert(unsigned x, int p, int n)
{
	return x ^(~(~0 << n) << (p+1-n));
}

/* rightrot: rotate x to the right by n positions */
unsigned rightrot(unsigned x, int n)
{
	int wordlength(void);
	int rbit;/* rightmost bit */

	while (n-- > 0) {
		rbit = (x & 1) << (wordlength() -1);
		x = x >> 1;/* shift x 1 position right */
		x = x | rbit;/* complete one rotation */
	}
	return x;
}

/* wordlength: computes word length of the machine */
int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;

	for (i = 1; (v = v >> 1) >0; i++)
		;
	return i;
}

/* bitcount: count 1 bits in x - faster version */
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= x - 1)
		++b;
	return b;
}

/* lower: convert c to lower case (ASCII only) */
int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}