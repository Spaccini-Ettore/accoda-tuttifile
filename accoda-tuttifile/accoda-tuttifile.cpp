#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int accodaTuttiFile(const char* fileConNomi, const char* fileOutput);

int main()
{
	int n = accodaTuttiFile("\\temp\\elenco.txt", "file.txt.output");
	printf("%d", n);
	return 0; 
}

int accodaTuttiFile(const char* fileConNomi, const char* fileOutput)
{
	FILE* fnomi, * fout; 

	if ((fnomi = fopen(fileConNomi, "r")) == NULL)
	{
		return 0; 
	}
	if ((fout = fopen(fileOutput, "wb")) == NULL)
	{
		return 0; 
	}
	
	size_t n = 0 ;
	char filename[255];
	while (fgets(filename, 255, fnomi) != NULL)
	{
		if (filename[strlen(filename) - 1] == '\n')
		{
			filename[strlen(filename) - 1] = '\0'; //sposto il \0 perche fgets mi legge anche il \n
		}
		char ff2[500] = "C:\\TEMP\\";
		strcat(ff2, filename);
		FILE* f = fopen(ff2, "rb");
		if (f == NULL)
			continue;
		int c; 
		while ((c = fgetc(f)) != EOF)
			fputc(c, fout);

		fclose(f);
		n++;
	}
	fclose(fnomi);
	fclose(fout);
	return n; 
}