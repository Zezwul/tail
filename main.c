#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myTailFromFile(int numberOfChars)
{
	FILE *file;
	file = fopen("src/text.txt", "r");

	for(int i = numberOfChars; i > 0; i--)
	{
		fseek(file, -i, 2);
		printf("%c", fgetc(file));
	}

	fclose(file);
	return 0;
}

int myTailFromStream(char* argv[])
{
	char* str, c;
	int i = 0, j = 1;
	str = (char*)malloc(sizeof(char));

	while (c != EOF)
	{
		c = getc(stdin);
		if ( c == EOF ) break;
		str = (char*)realloc(str, j * sizeof(char));
		str[i] = c;
		i++;
		j++;
	}

	int stringLength = strlen(str);
	int value = atoi(argv[1]);
	int it = stringLength < value ? 0 : stringLength - value;

	for( ; it < stringLength; it++)
	{
		printf("%c", str[it]);
	}

	free(str);
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("error: to few arguments in main(int argc, char* argv[])\n");
		printf("                                    ^\n");
		return 1;
	}
	myTailFromStream(argv);
	return 0;
}
