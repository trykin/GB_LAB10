#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <direct.h>
#include <time.h>
#include <stdlib.h>


int main()
{
	char* dir;
	char fileName[256];
	FILE* file;
	//Читаем текущий каталог
	if ((dir = _getcwd(NULL, 0)) == NULL)
		perror("Error read directory");
	//Склеиваем
	snprintf(fileName, sizeof fileName, "%s%s", dir, "\\file.csv");

	srand(time(NULL));
	unsigned int s = rand() % 100;
	file = fopen(fileName, "w+t");
	for (int i = 0; i < s; i++)
		fprintf(file, "%d;%d;%d;%d;\n", rand(), rand(), rand(), rand());
	fclose(file);
}
