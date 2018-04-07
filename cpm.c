#include "cpm.tab.h"
#include <stdio.h>
#include "shared.h"
#define _CRT_SECURE_NO_WARNINGS
int main(int argc, char **argv)
{
	char* file;
	char last[4];
	char* name;
	char x;
	int len;
	char names[] = "Guy Tordjman is The Best";
	printf("%s\n",names);
	if (argc == 2)
	{
		file = argv[1];
		len= strlen(file);
		if (len > 4)
		{
			strcpy(last, file + len - 3);
			if (strcmp(last, "cpl") == 0 || strcmp(last, "CPL") == 0)
			{

				yyin = fopen(file, "r");
				if (yyin != NULL)
				{
					name = (char*)malloc(len - 2);
					strncpy(name, file, len - 3);
					name[len - 3] = '\0';
					myout = StringCat(name, "lst");
					yyout = fopen(myout, "w");
					free(myout);
					if (yyout != NULL)
					{
						myout = StringCat(name, "s");
						fprintf(yyout, "/* %s */ \n\n",names);
						fprintf(yyout, "1. ");
						int x = 0;
						do {
							yyparse();
						} while (!feof(yyin));
						if (eCount != 0)
						{
							printf("Can't recover from error. Compilation Done With %d Errors", eCount - 1);
						}
						freeErrors();
						fclose(yyout);
						fclose(yyin);
						free(name);
					}
					else
						printf("cannot create lst file");//out file open

				}
				else
					printf("cannot open source file");//file open
			}
			else
				printf("file type error");//file type
		}
		else
			printf("file name error");//len <= 4
	}
	else
		printf("input file not found!");
	printf("\npress any key to continue..");
	x = getchar();
	return 0;
}