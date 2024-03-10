#include"function.h"

char* CreateStr(int size)
{
	char* str = new char[size];
	return str;
}

char* NewStr(char* str, int size)
{
	char* newstr = new char[size];
	for (int i = 0; i < size - 1; i++)
	{
		newstr[i] = str[i];
	}
	delete[] str;
	return newstr;
}

void AddLine(FILE* f,FILE* f2)
{
	char c = fgetc(f);
	int count = 0;
	int size = 1;
	char* str = CreateStr(size);
	bool space = 0;
	bool lastline = 1;
	while (c != EOF)
	{
		
		space = 0;
		while(c!='\n'&& c != EOF)
		{
			if (c == ' ')
				space = 1;
			if (c != '\n')
			{
				str = NewStr(str, size++);
				str[count] = c;
			}
			count++;
			c = fgetc(f);
		}
		str = NewStr(str, size++);
		str[count] = '\0';
		size = 1;
		count = 0;
		c = fgetc(f);
		if (space == 0)
		{
			fprintf(f2, "%s", str);
			fprintf(f2, "%s", "-------------\n");
			lastline = 0;
		}
		else
		{
			fprintf(f2, "%s", str);
			fprintf(f2, "%s", "\n");
		}
	}
	if (lastline)
		fprintf(f2, "%s", "-------------\n");
	delete[] str;
}