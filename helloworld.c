#include <stdio.h>
#include <string.h>

#define LIM 	5
#define SIZE 	81

void strptr(char* ptr[], int count);

int main(void)
{
	int cnt = 0;
	char strs[LIM][SIZE];
	char* ptrs[LIM];

	printf("Input %d strings.", SIZE);
	fputs("To stop, press an Enter key:\n", stdout);

	while (cnt < LIM && *fgets( strs[cnt], SIZE, stdin) != '\n')
	{
		ptrs[cnt] = strs[cnt];
		cnt++;
	}

	strptr( ptrs, cnt);
	for ( int i = 0; i < cnt; i++)
		fputs( ptrs[i], stdout);

	return 0;
}

void strptr( char* ptr[], int cnt)
{
	int i,j;
	char* p = NULL;

	for (i = 0; i < cnt; i++)
		for (j = i+1; j < cnt-i; j++)
		{
			if ( strncmp( *(ptr+j-1), *(ptr+j), SIZE) > 0)
			{
				p = *(ptr+j-1);
				*(ptr+j-1) = *(ptr+j);
				*(ptr+j) = p;
			}
		}
}
